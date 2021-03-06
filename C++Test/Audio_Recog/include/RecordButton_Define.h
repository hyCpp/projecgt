#ifndef RECORDBUTTON_H_INCLUDEDAR_LOG_FILE
#define RECORDBUTTON_H_INCLUDED
#pragma once
#include <Windows.h>
#include "mmsystem.h"
#include "WavFile.h"
#include <thread>
#define SAMPLES 16000
#define SAMPLEBIT 16
#define CHANNELNUM 1
#define CHUNCK_SIZE 10240
#define AR_LOG_FILE_MAX_SIZE 1024*1024*20

#define AR_LOG_FILE(fmt,...){\
	                        FILE *pFile;\
							errno_t err = fopen_s(&pFile,"aclog.log", "a+");\
							if (0 != err){\
								printf("File open WRONG. %d\n", err);\
							}\
							fseek(pFile, 0, SEEK_END);\
							int length = ftell(pFile);\
							if (length > AR_LOG_FILE_MAX_SIZE) {\
								fclose(pFile);\
								system("del aclog.log");\
								fopen_s(&pFile,"aclog.log", "a+");\
																																			}\
							fprintf(pFile, "time %s  %s(%d)-<%s>: "##fmt, timestring().c_str(), __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);\
							fprintf(pFile, "\n");\
							fclose(pFile);\
							}

extern std::string timestring();

typedef struct AUDIO_Recog {
	void *UsrData;
	char *SourceFilePath;
	char *saveFilePath;
   // int BEEP_I;
	WavFile * audioin;
	HWAVEIN phwi;
	std::thread* r_j_th;
	WAVEINCAPS waveIncaps;
	WAVEFORMATEX pwfx;
	WAVEHDR pwh1;
	WAVEHDR pwh2;
} AUDIO_Recog;

#endif