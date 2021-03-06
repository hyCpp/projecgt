#include "fingerprint.h"
#include <algorithm>
#include <map>

using namespace std;

#define BEEPLEN_01 0.05
#define BEEPLEN_02 0.25
#define BEEPLEN_03 0.50
#define BEEPLEN_04 0.10
#define BEEPIDLE_05 0.05
#define BEEPIDLE_06 0.50
#define BEEPLEN_RANGE 1
#define BEEP_F 3000

bool readConfigFile(int &a)
{
	string BEEP_I = "BEEP_I";
	ifstream configfile;
	string path = "./config.txt";

	fstream _file;
	if (NULL == path.c_str()) {
		AR_LOG_FILE("filepath is null!");
		return false;
	}
	_file.open(path.c_str(), ios::in);
	if (!_file)
	{
		AR_LOG_FILE("%s not exist!", path.c_str());
		_file.close();
		return false;
	}
	_file.close();

	configfile.open(path.c_str()); //打开文件
	if (!configfile.is_open()) {
		AR_LOG_FILE("can not open config file:%s\n ", path);
		return false;
	}
	char tmp[1000];
	configfile.getline(tmp, 1000); //每行读取前1000个字符，1000个应该足够了
	string line(tmp);
	size_t pos = line.find('=');//找到每行的“=”号位置，之前是key之后是value  
	if (pos == string::npos)
		return false;
	string tmpKey = line.substr(0, pos);//取=号之前  
	if (BEEP_I == tmpKey)
	{
		a = atoi(line.substr(pos + 1).c_str());//取=号之后  
	}
	return true;
}

const std::pair<int, std::string> beepvalue[] =
{
	std::make_pair(1, "Beep01"),
	std::make_pair(2, "Beep02"),
	std::make_pair(3, "Beep03"),
	std::make_pair(4, "Beep04"),
	std::make_pair(5, "Beep05"),
	std::make_pair(6, "Beep06")
};

std::map<int, std::string> BeepMap(beepvalue, beepvalue + sizeof(beepvalue) / sizeof(beepvalue[0]));

TExtractFeature::TExtractFeature() {
	fftw_in = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)* FRAME_SIZE);
	fftw_out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)* FRAME_SIZE);
	fftw_p = fftw_plan_dft_1d(FRAME_SIZE, fftw_in, fftw_out, FFTW_FORWARD, FFTW_ESTIMATE);

	MALLOC(threshold, FRAME_HEIGHT, float);
	MALLOC(peak, FRAME_HEIGHT, float);

	MALLOC(Gauss_base, FRAME_HEIGHT * 2 + 1, float);
	Gauss = Gauss_base + FRAME_HEIGHT;
	for (int i = -FRAME_HEIGHT; i <= FRAME_HEIGHT; i++)
		Gauss[i] = (float)exp(-0.5*i*i / Gauss_Var / Gauss_Var);
	MALLOC(Hamming, FRAME_SIZE, float);
	for (int i = 0; i<FRAME_SIZE; i++)
		Hamming[i] = (float)(0.54 - 0.46*cos(2 * PI*i / (FRAME_SIZE - 1)));
	MALLOC(search, MAX_FEATURE_PER_FRAME, int);

	frame_num = 0;
	spectrum = NULL;
	feature = NULL;
}

int TExtractFeature::AddSearch(int frame, int freq) {
	int min_place = 0;	//使spectrum[frame][search[k]]最小的k
	int flag = 0;		//可插入标志
	for (int k = 0; k<MAX_FEATURE_PER_FRAME; k++) {
		if (search[k] == 0) {	//search[k]为空,可将新值填入
			flag = 1;
			min_place = k;
			break;
		}
		if (spectrum[frame][search[k]]<spectrum[frame][freq])	//可以插入
			flag = 1;
		if (spectrum[frame][search[k]]<spectrum[frame][search[min_place]])
			min_place = k;
	}
	if (flag == 0) return 0;
	search[min_place] = freq;
	return 1;
}

void TExtractFeature::Init() {
	MALLOC2D(spectrum, frame_num, FRAME_HEIGHT, float);
	MALLOC2D(feature, frame_num, FRAME_HEIGHT, int);
	for (int i = 0; i<frame_num; i++)
		memset(feature[i], 0, sizeof(int)*FRAME_HEIGHT);
}

int TExtractFeature::NotExtremum(int j, float Arr[]) {
	if (j == 0 && Arr[j] <= Arr[j + 1])
		return 1;
	if (j == FRAME_HEIGHT - 1 && Arr[j] <= Arr[j - 1])
		return 1;
	if (j>0 && j<FRAME_HEIGHT - 1 && (Arr[j] <= Arr[j + 1] || Arr[j] <= Arr[j - 1]))
		return 1;
	return 0;
}

int TExtractFeature::ExtractPair(const char *filename, THash &hash, int offset, float decay, int Id, int mode) {
	decay_factor = decay;
	int iFrameNum = Wav2Spectrum(filename, offset);
	Spectrum2Feature();
	if (mode == 0)
		Feature2PairInsert(hash, Id);
	else
		Feature2PairSearch(hash);

	return iFrameNum;
}

void TExtractFeature::AddBeep(Json::Value &res, int &iNum, int iStart, int type, double starttime) {
	float fStart = (float)(iStart*(float)FRAME_HOP / float(samples));
	++iNum;
	Json::Value beep;
	beep["startID"] = iNum;
	beep["Type"] = BeepMap[type];
	beep["startTime"] = fStart + starttime;
	// beep["length"] = fLength;
	res["beepList"].append(beep);
}

int TExtractFeature::getSingleBeepType(int iCount) {
	float fLength = (float)(iCount*(float)FRAME_HOP / float(samples));
	float fRange = (float)(BEEPLEN_RANGE*(float)FRAME_HOP / float(samples));
	if ((BEEPLEN_01 - fRange <= fLength) && (BEEPLEN_01 + fRange >= fLength)) {
		return 1;
	}
	else if ((BEEPLEN_02 - fRange <= fLength) && (BEEPLEN_02 + fRange >= fLength)) {
		return 2;
	}
	else if ((BEEPLEN_03 - fRange <= fLength) && (BEEPLEN_03 + fRange >= fLength)) {
		return 3;
	}
	else if ((BEEPLEN_04 - fRange <= fLength) && (BEEPLEN_04 + fRange >= fLength)) {
		return 4;
	}
	return -1;
}

int TExtractFeature::getBeepType(int& iStart, int& end)
{
	
	int iCount = 0;
	int type = 0;
	iCount = getFrameBusyCount(iStart);
	if (iCount < 0) {
		return -2;
	}
	type = getSingleBeepType(iCount);
	if (1 == type)
	{
		int coutmp = iCount;
		iStart += 1;
		iCount = getFrameIdleCount(iStart);
		coutmp += iCount;
		float fLength = (float)(iCount*(float)FRAME_HOP / float(samples));
		float fRange = (float)(BEEPLEN_RANGE*(float)FRAME_HOP / float(samples));
		if ((BEEPLEN_01 - fRange <= fLength) && (BEEPLEN_01 + fRange >= fLength)) {
			type = getSingleBeepType(getFrameBusyCount(iStart));
			if (type == 1) {
				type = 5;

			}
		}
		end = iStart;
		iStart -= coutmp;
	}
	if (4 == type)
	{
		int coutmp = iCount;
		iStart += 1;
		iCount = getFrameIdleCount(iStart);
		coutmp += iCount;
		float fLength = (float)(iCount*(float)FRAME_HOP / float(samples));
		float fRange = (float)(BEEPLEN_RANGE*(float)FRAME_HOP / float(samples));
		if ((BEEPIDLE_06 - fRange <= fLength) && (BEEPIDLE_06 + fRange >= fLength)) {
			iStart += iCount;
			type = getSingleBeepType(getFrameBusyCount(iStart));
			if (type == 4) {
				type = 6;
			}
		}
		end = iStart;
		iStart -= coutmp;
	}
	
	return type;
}

string TExtractFeature::BeepJudge(const char *filename, double starttime) {
	Json::Value res;
	//res["beepFile"] = filename;
	int framenum = Wav2Spectrum(filename, 0);
	int iNum = 0;
	int iStart = 0, end = 0;
	while (iStart < framenum) {
		int type = getBeepType(iStart, end);
		if (end - iStart > -2 && end - iStart < 2)
			break;
		if (BeepMap.find(type) != BeepMap.end())
		{
			AddBeep(res, iNum, iStart, type, starttime);
		}
		iStart = end > iStart ? end - 1 : iStart + 1;
	}

	res["beepNum"] = iNum;
	return res.toStyledString();
}

int TExtractFeature::Wav2Spectrum(const char *filename, int offset) {
	TWav wav(filename);
	int block_num = wav.wav_info.data_size / wav.wav_info.format.block_align;
	if (0 >= block_num - offset - FRAME_SIZE) {
		return block_num;
	}

	frame_num = (block_num - offset - FRAME_SIZE) / FRAME_HOP + 2;
	samples = wav.wav_info.format.samples_per_sec;

	Init();
	fseek(wav.wav_info.fp, offset*wav.wav_info.format.block_align, SEEK_CUR);
	//FILE* tmp;
	//fopen_s(&tmp, "C:\\Users\\toby\\Desktop\\tmp.txt", "wb+");
	for (int i = 0; i<frame_num; i++) {
		for (int j = 0; j<FRAME_SIZE; j++) {
			fftw_in[j][0] = wav.GetSample() * Hamming[j];
			fftw_in[j][1] = 0;
		}
		fseek(wav.wav_info.fp, (FRAME_HOP - FRAME_SIZE)*wav.wav_info.format.block_align, SEEK_CUR);
		fftw_execute(fftw_p);
		for (int j = 0; j<FRAME_HEIGHT; j++) {
			if (j<LOW_FREQ)
				spectrum[i][j] = 0;
			else
				spectrum[i][j] = (float)sqrt(fftw_out[j][0] * fftw_out[j][0] + fftw_out[j][1] * fftw_out[j][1]) / FRAME_SIZE;
			//fprintf(tmp, "%d\t%d\t%f \n", i, j, spectrum[i][j]);
		}
	}
//	fclose(tmp);
	return frame_num;
}

int TExtractFeature::Spectrum2Feature() {
	memset(peak, 0, sizeof(float)*FRAME_HEIGHT);
	memset(threshold, 0, sizeof(float)*FRAME_HEIGHT);

	for (int i = 0; i<10; i++)
		for (int j = 0; j<FRAME_HEIGHT; j++) {
			if (spectrum[i][j]>peak[j])
				peak[j] = spectrum[i][j];
		}
	for (int j = 0; j<FRAME_HEIGHT; j++) {
		if (NotExtremum(j, peak))
		{
			continue;
		}
		for (int k = 0; k<FRAME_HEIGHT; k++)
			threshold[k] = (float)max3(threshold[k], peak[j] * Gauss[k - j], MIN_THRESHOLD);
	}

	for (int i = 10; i<frame_num; i++) {
		memset(search, 0, MAX_FEATURE_PER_FRAME * sizeof(int));
		for (int j = 0; j<FRAME_HEIGHT; j++) {
			if (spectrum[i][j] <= threshold[j])
				continue;
			if (NotExtremum(j, spectrum[i]))
				continue;
			AddSearch(i, j);
		}
		//记录特征点,更新threshold[]
		for (int j = 0; j<MAX_FEATURE_PER_FRAME; j++) {
			if (search[j] == 0)
				continue;
			feature[i][search[j]] = 1;
			for (int k = 0; k<FRAME_HEIGHT; k++)
				threshold[k] = (float)max3(threshold[k], Gauss[k - search[j]] * spectrum[i][search[j]], MIN_THRESHOLD);
		}
		//使threshold[]衰减
		for (int j = 0; j<FRAME_HEIGHT; j++)
			threshold[j] *= decay_factor;
	}

	//Init threshold[]
	memset(threshold, 0, sizeof(float)*FRAME_HEIGHT);
	for (int j = 0; j<FRAME_HEIGHT; j++) {
		if (NotExtremum(j, spectrum[frame_num - 1]))
			continue;
		for (int k = 0; k<FRAME_HEIGHT; k++)
			threshold[k] = max2(threshold[k], spectrum[frame_num - 1][j] * Gauss[k - j]);
	}
	//decaying threshold法,逆向扫描,减少特征点
	for (int i = frame_num - 1; i >= 0; i--) {
		for (int j = 0; j<FRAME_HEIGHT; j++)
			if (feature[i][j]) {
				if (spectrum[i][j]<threshold[j]) {
					feature[i][j] = 0;
					continue;
				}
				for (int k = 0; k<FRAME_HEIGHT; k++)
					threshold[k] = max2(threshold[k], spectrum[i][j] * Gauss[k - j]);
			}
		//使threshold[]衰减
		for (int j = 0; j<FRAME_HEIGHT; j++)
			threshold[j] *= decay_factor;
	}
	return 0;
}

int TExtractFeature::Feature2PairInsert(THash &hash, int id) {
	int pi, pj;
	int count;
	int flag;
	// [> int index = 0; <]
	for (int i = 0; i<frame_num; i++)
		for (int j = 0; j<FRAME_HEIGHT; j++) {
			flag = 1;
			if (feature[i][j] == 0)
				continue;
			count = 0;
			for (pi = i + PAIR_OFFSET; flag && pi<i + PAIR_DX && pi<frame_num; pi++)
				for (pj = max2(j - PAIR_DY, 0); flag && pj<j + PAIR_DY && pj<FRAME_HEIGHT; pj++) {
					if (feature[pi][pj] == 0)
						continue;
					count++;
					hash.InsertHash(j, pj - j + f2_f1_max, pi - i, id, i);
					if (count >= MAX_PAIR_PER_FEATURE) flag = 0;
				}
		}
	return 0;
}

int TExtractFeature::Feature2PairSearch(THash &hash) {
	int pi, pj;
	int count;
	int flag;
	/* int index = 0; */
	for (int i = 0; i<frame_num; i++)
		for (int j = 0; j<FRAME_HEIGHT; j++) {
			flag = 1;
			if (feature[i][j] == 0)
				continue;
			count = 0;
			for (pi = i + PAIR_OFFSET; flag && pi<i + PAIR_DX && pi<frame_num; pi++)
				for (pj = max2(j - PAIR_DY, 0); flag && pj<j + PAIR_DY && pj<FRAME_HEIGHT; pj++) {
					if (feature[pi][pj] == 0)
						continue;
					count++;
					hash.Vote(j, pj - j + f2_f1_max, pi - i, i);
				}
		}
	return 0;
}

int TExtractFeature::getFrameBusyCount(int& iStartFrame)
{
	int BEEP_I=0;
	bool error = readConfigFile(BEEP_I);
	if (0 == error)
	{
		AR_LOG_FILE("Read config file wrong!\n");
		return -1;
	}
	int iCount = 0, flag = 0;
	int iF = (int)ceil((float)BEEP_F / ((float)samples / 2)*(float)FRAME_HEIGHT);
	for (int i = iStartFrame; i < frame_num; ++i) {
		if (0 == flag && BEEP_I > spectrum[i][iF]) {
			iStartFrame = max(iStartFrame, i);
			continue;
		}
		else if (1 == flag && BEEP_I > spectrum[i][iF]) {
			iStartFrame = max(iStartFrame, i);
			break;
		}
		else {
			flag = 1;
			iCount++;
			iStartFrame++;
		}
	}
	return iCount;
}

int TExtractFeature::getFrameIdleCount(int& iStartFrame)
{
	int BEEP_I = 0;
	bool error = readConfigFile(BEEP_I);
	if (0 == error)
	{
		AR_LOG_FILE("Read config file wrong!\n");
	}
	
	int iCount = 0, flag = 0;
	int iF = (int)ceil((float)BEEP_F / ((float)samples / 2)*(float)FRAME_HEIGHT);
	for (int i = iStartFrame; i < frame_num; ++i) {
		if (0 == flag && BEEP_I <= spectrum[i][iF]) {
			iStartFrame = max(iStartFrame, i);
			continue;
		}
		else if (1 == flag && BEEP_I <= spectrum[i][iF]) {
			iStartFrame = max(iStartFrame, i);
			break;
		}
		else {
			flag = 1;
			iCount++;
			iStartFrame++;
		}
	}
	return iCount;
}

TExtractFeature::~TExtractFeature() {
	fftw_destroy_plan(fftw_p);
	fftw_free(fftw_in);
	fftw_free(fftw_out);

	FREE(Gauss_base);
	FREE(Hamming);
	FREE(threshold);
	FREE(peak);
	FREE(search);
}

void TExtractFeature::UnInit() {
	FREE2D(spectrum, frame_num);
	FREE2D(feature, frame_num);
}
