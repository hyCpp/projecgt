#ifndef C_AUDIO_PROCESS_H_INCLUDED
#define C_AUDIO_PROCESS_H_INCLUDED

#pragma once
#include <stdio.h>
#include <string>
#include "AUDIO_Recog.h"
#include "RecordButton_Define.h"

AUDIO_RECOG_ERROR_TYPE playMusic(const char* filepath, double starttime, double endtime);

AUDIO_RECOG_ERROR_TYPE pauseMusic();

AUDIO_RECOG_ERROR_TYPE resumeMusic();

AUDIO_RECOG_ERROR_TYPE stopMusic();

AUDIO_RECOG_ERROR_TYPE checkRecordVoice(void * hinst, std::string& msg);

void WaveInitFormat(LPWAVEFORMATEX m_WaveFormat, WORD nCh, DWORD nSampleRate, WORD BitsPerSample);

AUDIO_RECOG_ERROR_TYPE startRecord(AUDIO_Recog* judge_record);

AUDIO_RECOG_ERROR_TYPE endRecord(AUDIO_Recog* judge_record);

#endif