#include "AudioProcess.h"
#include "AUDIO_Recog.h"
#include <atltime.h>
#include <thread>

bool recIsStarted = false;
/* Handle to the WAVE In Device */
HWAVEIN WaveInHandle;

/* Handle to the disk file where we permanently store the recorded audio data */
HANDLE WaveFileHandle = INVALID_HANDLE_VALUE;

/* We use two WAVEHDR's for recording (ie, double-buffering) in this example */
WAVEHDR WaveHeader[2];

/* Variable used to indicate whether we are in record */
BOOL InRecord = FALSE;

/* Variable used by recording thread to indicate whether we are in record */
unsigned char DoneAll = 2;

std::string timestring()
{
	CTime tm = CTime::GetCurrentTime();//»ñÈ¡ÏµÍ³ÈÕÆÚ
	CString date = tm.Format(_T("%Y-%m-%d %X"));
	CStringA stra(date.GetBuffer(0));
	date.ReleaseBuffer();
	std::string timestr = stra.GetBuffer(0);
	stra.ReleaseBuffer();
	return timestr;
}

const wchar_t *GetWC(const char *c)
{
	size_t converted = 0;
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	if (NULL == wc)
	{
		AR_LOG_FILE("wc new failed!");
	}
	else
	{
		mbstowcs_s(&converted, wc, cSize, c, _TRUNCATE);
	}

	return wc;
}

DWORD getinfo(UINT wDeviceID, DWORD item)
{
	MCI_STATUS_PARMS mcistatusparms;
	mcistatusparms.dwCallback = NULL;
	mcistatusparms.dwItem = item;
	mcistatusparms.dwReturn = 0;
	mciSendCommand(wDeviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mcistatusparms);
	return mcistatusparms.dwReturn;
}

double getMusicLen(const char* filename)
{
	MCI_OPEN_PARMS op;
	DWORD cdlen;
	op.dwCallback = NULL;
	op.lpstrAlias = NULL;
	op.lpstrDeviceType = TEXT("MPEGAudio");  
	op.lpstrElementName = GetWC(filename); 
	op.wDeviceID = NULL;    
	UINT rs;        
	rs = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)&op);
	mciSendCommand(NULL, MCI_SET, MCI_SET_DOOR_OPEN, NULL);
	cdlen = getinfo(op.wDeviceID, MCI_STATUS_LENGTH);
												 
	return (double)cdlen / 1000.0;
}

AUDIO_RECOG_ERROR_TYPE checkRecordVoice(void * hinst, std::string& msg)
{
	if (NULL == hinst)
	{
		AR_LOG_FILE("hinst is null!");
		msg = "hinst is null!";
		return AUDIORECORD_ERROR_TYPE_NULLPOINTER;
	}

	AUDIO_Recog *judge_record = (AUDIO_Recog*)hinst;

	if (NULL == judge_record)
	{
		AR_LOG_FILE("judge_record is null!");
		msg = "judge_record is null!";
		return AUDIORECORD_ERROR_TYPE_NULLPOINTER;
	}

	int count = waveInGetNumDevs();//1
	AR_LOG_FILE("Number of Device is %d \n", count);

	MMRESULT mmResult = waveInGetDevCaps(0, &judge_record->waveIncaps, sizeof(WAVEINCAPS));//2
	//AR_LOG_FILE("Input audio device is  %ws", judge_record->waveIncaps.szPname);
	
	if (MMSYSERR_NOERROR != mmResult)
	{
		msg = "waveInGetDevCaps error, not support record";
		return AUDIORECORD_ERROR_TYPE_START;
	}
	msg = "support record";
	//Â¼Òô²¿·Ö
	return AUDIORECORD_ERROR_TYPE_NO_ERROR;

}

DWORD WINAPI waveInProc(LPVOID arg)
{
	MSG     msg;
	AUDIO_Recog* recog = (AUDIO_Recog*)arg;
	/* Wait for a message sent to me by the audio driver */
	while (GetMessage(&msg, 0, 0, 0) == 1)
	{
		/* Figure out which message was sent */
		switch (msg.message)
		{
			/* A buffer has been filled by the driver */
		case MM_WIM_DATA:
		{
			/* msg.lParam contains a pointer to the WAVEHDR structure for the filled buffer.
			* NOTE: The WAVEHDR's dwBytesRecorded field specifies how many bytes of
			* audio data are in the buffer. It may not be full, as would be the case
			* if recording was stopped *while* this buffer was being filled. (ie, A
			* final, partial block of audio data may be returned)
			*/
			if (((WAVEHDR *)msg.lParam)->dwBytesRecorded)
			{
				/* Let's write out this next block of data to our already open file. NOTE: The main
				* thread opened this file prior to starting recording, and stored its handle in
				* 'WaveFileHandle'
				*/
				if (!recog->audioin->write(((WAVEHDR *)msg.lParam)->lpData, ((WAVEHDR *)msg.lParam)->dwBytesRecorded) ||
					/* Check for an error */
					msg.time != ((WAVEHDR *)msg.lParam)->dwBytesRecorded)
				{
					/* Normally you'd do something here like signal the main thread to have it stop recording and
					* display an error message about there being a problem writing the audio data to disk
					*/
				}
			}

			/* Are we still recording? */
			if (InRecord)
			{
				/* Yes. Now we need to requeue this buffer so the driver can use it for another block of audio
				* data. NOTE: We shouldn't need to waveInPrepareHeader() a WAVEHDR that has already been prepared once
				*/
				waveInAddBuffer(recog->phwi, (WAVEHDR *)msg.lParam, sizeof(WAVEHDR));
			}

			/* We aren't recording, so another WAVEHDR has been returned to us after recording has stopped.
			* When we get all of them back, DoneAll will be equal to how many WAVEHDRs we queued
			*/
			else
			{
				++DoneAll;
			}

			/* Keep waiting for more messages */
			continue;
		}

		/* Our main thread is opening the WAVE device */
		case MM_WIM_OPEN:
		{
			/* Re-initialize 'DoneAll' */
			AR_LOG_FILE("Device is opening...");
			DoneAll = 0;

			/* Keep waiting for more messages */
			continue;
		}

		/* Our main thread is closing the WAVE device */
		case MM_WIM_CLOSE:
		{
			AR_LOG_FILE("Device is closing...");
			DoneAll = 2;
			/* Terminate this thread (by return'ing) */
			break;
		}
		}
	}

	return(0);
}


AUDIO_RECOG_ERROR_TYPE startRecord(AUDIO_Recog* judge_record)
{
	if (InRecord) {
		AR_LOG_FILE("record is already started!");
		return AUDIORECORD_ERROR_TYPE_START;
	}
	if (NULL == judge_record)
	{
		AR_LOG_FILE("judge_record is null!");
		return AUDIORECORD_ERROR_TYPE_NULLPOINTER;
	}

	int count = waveInGetNumDevs();//1
	AR_LOG_FILE("Number of Device is %d \n", count);
	MMRESULT mmResult = waveInGetDevCaps(0, &judge_record->waveIncaps, sizeof(WAVEINCAPS));//2
	//AR_LOG_FILE("Input audio device is %ws ", judge_record->waveIncaps.szPname);

	if (MMSYSERR_NOERROR != mmResult)
	{
		AR_LOG_FILE("waveInGetDevCaps error, errorcode %d", mmResult);
		return AUDIORECORD_ERROR_TYPE_START;
	}

	judge_record->audioin = new WavFile();
	if (NULL == judge_record->audioin)
	{
		AR_LOG_FILE("judge_record->audioin new failed!");
		return AUDIORECORD_ERROR_TYPE_NULLPOINTER;
	}
	judge_record->audioin->openW(judge_record->saveFilePath, SAMPLES);

	DWORD threadid;
	HANDLE waveInThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)waveInProc, judge_record, 0, &threadid);
	if (!waveInThread)
	{
		AR_LOG_FILE("Can't create WAVE recording thread! -- %08X", GetLastError());
		return AUDIORECORD_ERROR_TYPE_START;
	}
	CloseHandle(waveInThread);

	ZeroMemory(&WaveHeader[0], sizeof(WAVEHDR) * 2);

	WaveInitFormat(&judge_record->pwfx, CHANNELNUM, SAMPLES, SAMPLEBIT);
	AR_LOG_FILE("Asking for opening audio device");
	AR_LOG_FILE("Sample is %d Hz SAMPLEBIT is  %d bit", SAMPLES, SAMPLEBIT);

	mmResult = waveInOpen(&judge_record->phwi, WAVE_MAPPER, &judge_record->pwfx, (DWORD)threadid, 0, CALLBACK_THREAD);//3
	if (mmResult)
	{
		AR_LOG_FILE("Can't open WAVE In Device!");
		return AUDIORECORD_ERROR_TYPE_START;
	}

	if (MMSYSERR_NOERROR != mmResult)
	{
		AR_LOG_FILE("waveInOpen error, errorcode £º%d", mmResult);
		return AUDIORECORD_ERROR_TYPE_START;
	}
	/* Allocate, prepare, and queue two buffers that the driver can use to record blocks of audio data.
	* (ie, We're using double-buffering. You can use more buffers if you'd like, and you should do that
	* if you suspect that you may lag the driver when you're writing a buffer to disk and are too slow
	* to requeue it with waveInAddBuffer. With more buffers, you can take your time requeueing
	* each).
	*
	* I'll allocate 2 buffers large enough to hold 2 seconds worth of waveform data at 44Khz. NOTE:
	* Just to make it easy, I'll use 1 call to VirtualAlloc to allocate both buffers, but you can
	* use 2 separate calls since the buffers do NOT need to be contiguous. You should do the latter if
	* using many, large buffers
	*/
	WaveHeader[1].dwBufferLength = WaveHeader[0].dwBufferLength = judge_record->pwfx.nAvgBytesPerSec << 1;
	if (!(WaveHeader[0].lpData = (char *)VirtualAlloc(0, WaveHeader[0].dwBufferLength * 2, MEM_COMMIT, PAGE_READWRITE)))
	{
		AR_LOG_FILE("ERROR: Can't allocate memory for WAVE buffer!");
	}
	else
	{
		/* Fill in WAVEHDR fields for buffer starting address. We've already filled in the size fields above */
		WaveHeader[1].lpData = WaveHeader[0].lpData + WaveHeader[0].dwBufferLength;

		/* Leave other WAVEHDR fields at 0 */

		/* Prepare the 2 WAVEHDR's */
		if ((MMSYSERR_NOERROR != waveInPrepareHeader(judge_record->phwi, &WaveHeader[0], sizeof(WAVEHDR))))
		{
			AR_LOG_FILE("Error preparing WAVEHDR 1! -- %08X", mmResult);
		}
		else
		{
			if ((MMSYSERR_NOERROR != waveInPrepareHeader(judge_record->phwi, &WaveHeader[1], sizeof(WAVEHDR))))
			{
				AR_LOG_FILE("Error preparing WAVEHDR 2! -- %08X", mmResult);
			}
			else
			{
				/* Queue first WAVEHDR (recording hasn't started yet) */
				if ((MMSYSERR_NOERROR != waveInAddBuffer(judge_record->phwi, &WaveHeader[0], sizeof(WAVEHDR))))
				{
					AR_LOG_FILE("Error queueing WAVEHDR 1! -- %08X\n", mmResult);
				}
				else
				{
					/* Queue second WAVEHDR */
					if ((MMSYSERR_NOERROR != waveInAddBuffer(judge_record->phwi, &WaveHeader[1], sizeof(WAVEHDR))))
					{
						AR_LOG_FILE("Error queueing WAVEHDR 2! -- %08X", mmResult);
						DoneAll = 1;
					}
					else
					{
						/* Start recording. Our secondary thread will now be receiving
						* and storing audio data to disk
						*/
						InRecord = TRUE;
						if ((MMSYSERR_NOERROR != waveInStart(judge_record->phwi)))
						{
							AR_LOG_FILE("Error starting record! -- %08X", mmResult);
						}
					}
				}

			}
		}
	}
	return AUDIORECORD_ERROR_TYPE_NO_ERROR;
}


void WaveInitFormat(LPWAVEFORMATEX m_WaveFormat, WORD nCh, DWORD nSampleRate, WORD BitsPerSample)
{
	if (NULL == m_WaveFormat)
	{
		AR_LOG_FILE("m_WaveFormat is null!");
		return;
	}
	m_WaveFormat->wFormatTag = WAVE_FORMAT_PCM;
	m_WaveFormat->nChannels = nCh;
	m_WaveFormat->nSamplesPerSec = nSampleRate;
	m_WaveFormat->nAvgBytesPerSec = nSampleRate * nCh * BitsPerSample / 8;
	m_WaveFormat->nBlockAlign = m_WaveFormat->nChannels * BitsPerSample / 8;
	m_WaveFormat->wBitsPerSample = BitsPerSample;
	m_WaveFormat->cbSize = 0;
}

AUDIO_RECOG_ERROR_TYPE endRecord(AUDIO_Recog* judge_record)
{
	if (NULL == judge_record)
	{
		AR_LOG_FILE("judge_record is null!");
		return AUDIORECORD_ERROR_TYPE_NULLPOINTER;
	}
	int result = MMSYSERR_NOERROR;
	MMRESULT mmResult = MMSYSERR_NOERROR;
	/* Tell our recording thread not to queue any WAVEHDRs it gets back via MM_WIM_DONE */
	InRecord = FALSE;
	/* Stop recording and tell the driver to unqueue/return all of our WAVEHDRs.
	* The driver will return any partially filled buffer that was currently
	* recording. Because we use waveInReset() instead of waveInStop(),
	* all of the other WAVEHDRs will also be returned via MM_WIM_DONE too
	*/
	waveInReset(judge_record->phwi);
	while (DoneAll < 2) Sleep(100);
	if ((MMSYSERR_NOERROR != waveInUnprepareHeader(judge_record->phwi, &WaveHeader[1], sizeof(WAVEHDR))))
	{
		AR_LOG_FILE("Error unpreparing WAVEHDR 2! -- %08X", mmResult);
	}
	if ((MMSYSERR_NOERROR != waveInUnprepareHeader(judge_record->phwi, &WaveHeader[0], sizeof(WAVEHDR))))
	{
		AR_LOG_FILE("Error unpreparing WAVEHDR 1! -- %08X", mmResult);
	}

	if (NULL != judge_record->audioin)
	{
		judge_record->audioin->close();
		delete judge_record->audioin;
		judge_record->audioin = NULL;
	}

	if (NULL != judge_record->pwh1.lpData) {
		free(judge_record->pwh1.lpData);
		judge_record->pwh1.lpData = NULL;
	}

	if (NULL != judge_record->pwh2.lpData) {
		free(judge_record->pwh2.lpData);
		judge_record->pwh2.lpData = NULL;
	}
	// return mmResult + result == MMSYSERR_NOERROR ? AUDIORECORD_ERROR_TYPE_NO_ERROR : AUDIORECORD_ERROR_TYPE_END;
	return result == MMSYSERR_NOERROR ? AUDIORECORD_ERROR_TYPE_NO_ERROR : AUDIORECORD_ERROR_TYPE_END;
}

AUDIO_RECOG_ERROR_TYPE playMusic(const char* filepath, double starttime, double endtime)
{
	if (starttime < 0) {
		starttime = 0;
	}

	double musiclen = getMusicLen(filepath);
	if (endtime < 0 || endtime > musiclen) {
		endtime = musiclen;
	}
	if (starttime > musiclen) {
		return AUDIORECORD_ERROR_TYPE_PLAY;
	}

	std::string tmp1("open ");
	std::string tmp2(filepath);
	std::string tmp3(" alias aa");
	const wchar_t* cmd = GetWC((tmp1 + tmp2 + tmp3).c_str());
	if (0 != mciSendString(cmd, NULL, 0, NULL))
	{
		return AUDIORECORD_ERROR_TYPE_OPEN;
	}
	std::string start = std::to_string((int)(starttime * 1000));
	std::string end = std::to_string((int)(endtime * 1000));
	std::string playaa = "play aa FROM ";
	std::string to = " TO ";
	cmd = GetWC((playaa + start + to + end).c_str());
	return 0 == mciSendString(cmd, NULL, 0, NULL) ? AUDIORECORD_ERROR_TYPE_NO_ERROR : AUDIORECORD_ERROR_TYPE_OPEN;

}

AUDIO_RECOG_ERROR_TYPE pauseMusic()
{
	return 0 == mciSendString(TEXT("pause aa"), NULL, 0, NULL) ? AUDIORECORD_ERROR_TYPE_NO_ERROR : AUDIORECORD_ERROR_TYPE_PAUSE;
}

AUDIO_RECOG_ERROR_TYPE resumeMusic()
{
	return 0 == mciSendString(TEXT("resume aa"), NULL, 0, NULL) ? AUDIORECORD_ERROR_TYPE_NO_ERROR : AUDIORECORD_ERROR_TYPE_RESUME;
}

AUDIO_RECOG_ERROR_TYPE stopMusic()
{
	return mciSendString(TEXT("stop aa"), NULL, 0, NULL) ? AUDIORECORD_ERROR_TYPE_NO_ERROR : AUDIORECORD_ERROR_TYPE_STOP;
}