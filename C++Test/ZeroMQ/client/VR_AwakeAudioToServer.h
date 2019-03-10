/**
 * Copyright @ 2014 - 2018 Suntec Software(Shanghai) Co., Ltd.
 * All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are NOT permitted except as agreed by
 * Suntec Software(Shanghai) Co., Ltd.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

/**
 * @file VR_AwakeAudioToServer.h
 * @brief Declaration file of class VR_AwakeAudioToServer.
 *
 * This file includes the declaration of class VR_AwakeAudioToServer.
 *
 * @attention used for C++ only.
 */

#ifndef VR_AWAKEAUDIOTOSERVER_H
#define VR_AWAKEAUDIOTOSERVER_H

#ifndef __cplusplus
#    error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif


//#include </home/huyang/iAuto3_Mix/externals/libcurl/include/curl/curl.h>
#include <curl/curl.h>
#include <string>
#include <MyThread.h>
/**
 * @brief The VR_IconDownload class
 *
 * class declaration
 */
class VR_AwakeAudioToServer : public MyThread
{

public:
    VR_AwakeAudioToServer(const std::string& path);
    ~VR_AwakeAudioToServer();

    bool run();
    void setUploadPath(const std::string& path);


private:
    bool UploadAudio();
    bool requestMsg();
    bool initUpload(CURL*& curl, char* url, const std::string& body);

    std::string m_path;
};



#endif // VR_AWAKEAUDIOTOSERVER_H

