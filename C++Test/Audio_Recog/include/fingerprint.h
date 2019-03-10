#ifndef FINGERPRINT_H
#define FINGERPRINT_H

#include <math.h>
#include <fftw3.h>
//#include <assert.h>
#include "wav.h"
#include "hash.h"
#include <stdint.h>
#include "json/json.h"
#include "RecordButton_Define.h"
#include <iostream>
#include <fstream>
#include <string>

#define FRAME_SIZE 512
#define FRAME_HEIGHT FRAME_SIZE/2
#define FRAME_HOP 256
#define LOW_FREQ 1
#define PAIR_OFFSET 5
#define PAIR_DX 63
#define PAIR_DY 31
#define Gauss_Var 30
#define PI 3.1415926
#define MAX_FEATURE_PER_FRAME 5
#define MAX_PAIR_PER_FEATURE 32
#define f2_f1_max 32
#define MIN_THRESHOLD 0.15

#define MALLOC(arr, m, type) {\
	arr = (type *)malloc((m) * sizeof(type));\
}

#define MALLOC2D(arr, m, n, type) {\
	arr = (type **)malloc((m)*sizeof(type*));\
	for (int i = 0; i < (m); i++){\
		arr[i] = (type *)malloc((n)*sizeof(type));\
	}\
}

#define FREE(p) {\
	if (p != NULL){\
		free(p);\
		p = NULL;\
	}\
}

#define FREE2D(arr, m) {\
	if (NULL != arr) {\
		for (int i = 0; i < (m); i++){\
			FREE(arr[i]);\
		}\
		FREE(arr);\
		arr = NULL;\
	}\
}

#define max2(a, b) (((a)>(b))?(a):(b))
#define max3(a,b,c) max2(max2((a),(b)),(c))

class TExtractFeature {
private:
	void AddBeep(Json::Value &res, int &iNum, int iStart, int type, double starttime);
	int getBeepType(int& iStart, int& end);
	int getSingleBeepType(int iCount);
	int Wav2Spectrum(const char *filename, int offset);
	int Spectrum2Feature();
	int Feature2PairInsert(THash &hash, int Id);
	int Feature2PairSearch(THash &hash);
	int getFrameBusyCount(int& iStartFrame);
	int getFrameIdleCount(int& iStartFrame);

	fftw_complex *fftw_in, *fftw_out;
	fftw_plan fftw_p;
	float *threshold;
	float **spectrum;
	float *Gauss;
	float *Gauss_base;
	float *Hamming;
	float *peak;
	int **feature;
	int frame_num;
	int *search;
	float decay_factor;

public:
	TExtractFeature();
	~TExtractFeature();

	void UnInit();
	int ExtractPair(const char *filename, THash &hash, int offset, float decay, int Id, int mode);
	string BeepJudge(const char *filename, double starttime);
	
	void Init();
	int AddSearch(int frame, int freq);
	int NotExtremum(int j, float Arr[]);

	int samples;
};

#endif
