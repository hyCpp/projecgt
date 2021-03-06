#include "hash.h"
#include "fingerprint.h"
#include "recog.h"
#include <json/json.h>
#include <algorithm>
#include "RecordButton_Define.h"
#include <fstream>
#include <iostream>
#include <direct.h> 
#include <io.h>
#include <sstream>

using namespace std;
#define MATCH_PER 0.01


#define HASH_DIR "hash"
#define HASH_INDEX "hash\\index.txt"

int makedir(string dir)
{
	if (_access(dir.c_str(), 0) == -1)
	{
		int flag = _mkdir(dir.c_str());

		if (flag != 0)
		{
			AR_LOG_FILE("Dir:%s make failed! \n", dir.c_str());
			return -1;
		}
	}
	return 0;
}

float getSourceFileTime(string szSourceFilePath) {
	ifstream myfile(HASH_INDEX);
	if (!myfile.is_open())
	{
		AR_LOG_FILE("Hash index file open failed! \n");
		return -1;
	}
	string sCurFile = "";
	float fFileTime = -1;
	while (!myfile.eof()) {
		float fTime = -1;
		myfile >> sCurFile >> fTime;
		if (0 == sCurFile.compare(szSourceFilePath)) {
			fFileTime = fTime;
			break;
		}
	}
	myfile.close();
	return fFileTime;
}

void addSourceFile(string szSourceFilePath, float fSourceFileTime) {
	ofstream outfile(HASH_INDEX, ios::app);
	outfile << szSourceFilePath << " " << fSourceFileTime << endl;
	outfile.close();
}

string ProcessSelelct(const char *szMusicPath, const char *szAudioPath) {
	Json::Value res;
	if ((NULL == szMusicPath) || (NULL == szAudioPath)) {

		res["result_type"] = AUDIORECOGNITION_ERROR_TYPE_NULLPOINT;
		return res.toStyledString();
	}

	THash myhash;
	TExtractFeature fingerprint;

	myhash.BuildInit();

	int frame_num = 0;
	ostringstream oss;
	string sSourceFile = szMusicPath;
	int iStart = sSourceFile.rfind("\\");
	int iEnd = sSourceFile.rfind(".");
	string sHashFile = sSourceFile.substr(iStart + 1, iEnd - iStart - 1);
	oss << HASH_DIR << "\\" << sHashFile << ".txt";

	float fSourceFileTime = getSourceFileTime(oss.str());
	if (-1 == fSourceFileTime) {
		myhash.AddSongList(szMusicPath);
		frame_num = fingerprint.ExtractPair(szMusicPath, myhash, 0, (float)0.98, 0, 0);
		fingerprint.UnInit();

		makedir(HASH_DIR);
		myhash.Hash2File(oss.str().c_str());
		fSourceFileTime = (float)(frame_num * (float)FRAME_HOP / float(fingerprint.samples));
		addSourceFile(oss.str(), fSourceFileTime);
	}

	myhash.File2Hash(oss.str().c_str());
	res["SourceFileTime"] = fSourceFileTime;

	myhash.ReBuildInit();
	myhash.VoteInit();

	frame_num = fingerprint.ExtractPair(szAudioPath, myhash, 0, (float)0.98, 0, 1);
	fingerprint.UnInit();
	frame_num = fingerprint.ExtractPair(szAudioPath, myhash, 64, (float)0.98, 0, 1);
	fingerprint.UnInit();
	frame_num = fingerprint.ExtractPair(szAudioPath, myhash, 128, (float)0.98, 0, 1);
	fingerprint.UnInit();
	frame_num = fingerprint.ExtractPair(szAudioPath, myhash, 192, (float)0.98, 0, 1);
	fingerprint.UnInit();
	float fSaveFileTime = (float)(frame_num * (float)FRAME_HOP / float(fingerprint.samples));
	res["SaveFileTime"] = fSaveFileTime;
	size_t offset;
	size_t max = myhash.VoteResult(offset);
	res["keyNum"] = Json::Value(static_cast<unsigned int>(myhash.data_num));
	res["match"] = Json::Value(static_cast<unsigned int>(max));
	if (0 == max) {
		res["matchPer"] = Json::Value(static_cast<unsigned int>(0));
		res["matchResult"] = false;
	}
	else {
		float fMatchPer = (float)max / (float)myhash.data_num;
		res["matchPer"] = fMatchPer;
		if ((MATCH_PER * (min(fSourceFileTime, fSaveFileTime) / fSourceFileTime)) <= fMatchPer) {
			res["matchResult"] = true;
		}
		else {
			res["matchResult"] = false;
		}
	}

	res["startTime"] = (float)(offset*(float)FRAME_HOP / float(fingerprint.samples));
	res["endTime"] = res["startTime"].asDouble() + res["SaveFileTime"].asDouble();
	myhash.BuildUnInit();
	res["result_type"] = AUDIORECOGNITION_ERROR_TYPE_NO_ERROR;

	return res.toStyledString();
}


string ProcessBeep(const char *szBeepFilePath, double starttime) {
	TExtractFeature fingerprint;
	string result = fingerprint.BeepJudge(szBeepFilePath, starttime);
	fingerprint.UnInit();
	return result;
}

//string ProcessMusic(const char *szBeepFilePath, double starttime) {
//	TExtractFeature fingerprint;
//	string result = fingerprint.MusicJudge(szBeepFilePath, starttime);
//	fingerprint.UnInit();
//	return result;
//}