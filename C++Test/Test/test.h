#include <string.h>
#include <stdio.h>
#include <string>
#include <vector>
#include<iostream>

namespace nutshell
{
namespace media
{
enum NIMediaCinemoMediaType
{
    NIMediaCinemoMediaType_Unknown = 0, ///< unknown, usded by initialize
    NIMediaCinemoMediaType_Audio = 1, ///< audio mode
    NIMediaCinemoMediaType_Video = 2, ///< video mode
};

enum testEnum
{
    testEnum_test1 =1,
    testEnum_test2 = 2,
};

}

namespace voice
{
enum NIMediaCinemoMediaType
{
    NIMediaCinemoMediaType_Unknown = 0, ///< unknown, usded by initialize
    NIMediaCinemoMediaType_Audio = 1, ///< audio mode
    NIMediaCinemoMediaType_Video = 2, ///< video mode
};
}
}
enum VoiceVoiceRecog_MediaCinemoMediaType
{
    VoiceVoiceRecog_MediaCinemoMedia_Min =-1,
    VoiceVoiceRecog_MediaCinemoMedia_Unknown= 0,
    VoiceVoiceRecog_MediaCinemoMedia_Audio= 1,
    VoiceVoiceRecog_MediaCinemoMedia_Video= 2,
    VoiceVoiceRecog_MediaCinemoMedia_Max =255,
};
namespace nutshell1
{
namespace media
{
enum testEnum1
{
    testEnum_test1 =1,
    testEnum_test2 = 2,
};
}
}
