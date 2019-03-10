#ifndef VUIMODELXMLDEFINE
#define VUIMODELXMLDEFINE
#include <string>

struct VoiceRecog_PoiSearchResult
{
    std::string     poiType;
    std::string     poiId;
    std::string     poiName;
    int             poiLon;
    int             poiLat;
    std::string     tel;
    std::string     address;
    int             linkId;
    int             distance;

    VoiceRecog_PoiSearchResult()
        : poiType("")
        , poiId("")
        , poiName("")
        , poiLon(0)
        , poiLat(0)
        , tel("")
        , address("")
        , linkId(0)
        , distance(0)
    {

    }
};

struct VoiceRecog_SongSearchResult
{
    std::string     songId;
    std::string     songName;
    std::string     albumId;
    std::string     albumName;
    std::string     artistId;
    std::string     artistName;
    std::string     sourceId;

    VoiceRecog_SongSearchResult()
        : songId("")
        , songName("")
        , albumId("")
        , albumName("")
        , artistId("")
        , artistName("")
        , sourceId("")
    {

    }
};

struct VoiceRecog_PhoneSearchResult
{
    int             contactId;
    std::string     firstName;
    std::string     lastName;
    std::string     phoneType1;
    std::string     phoneType2;
    std::string     phoneType3;
    std::string     phoneType4;
    std::string     phoneNumber1;
    std::string     phoneNumber2;
    std::string     phoneNumber3;
    std::string     phoneNumber4;

    VoiceRecog_PhoneSearchResult()
        : contactId(0)
        , firstName("")
        , lastName("")
        , phoneType1("")
        , phoneType2("")
        , phoneType3("")
        , phoneType4("")
        , phoneNumber1("")
        , phoneNumber2("")
        , phoneNumber3("")
        , phoneNumber4("")
    {

    }
};

struct VoiceRecog_searchResult
{
    std::string type;
    VoiceRecog_PoiSearchResult   poi_infos;
    VoiceRecog_SongSearchResult  song_infos;
    VoiceRecog_PhoneSearchResult phone_infos;

    VoiceRecog_searchResult()
        : type("")
        , poi_infos()
        , song_infos()
        , phone_infos()
    {

    }
};

struct VoiceRecog_RecognitionResult
{
    std::string content;
    std::string engineType;
    std::string enginState;
    std::string recogResult;
    int         volume;
    std::string volumeStatus;
    bool        isError;

    VoiceRecog_RecognitionResult()
        : engineType("")
        , enginState("")
        , recogResult("")
        , volume(0)
        , volumeStatus("")
        , isError(false)
        , content("")
    {

    }
};
#define VOICERECOG_SEARCH_NODE_PATH                         std::string("//items/item")
#define FC_VOICERECOG_EMPTY                                      std::string("")
#define ITEMS_ITEM_TYPE                                                      std::string("<display agent=\"Navi\" content=\"SearchResult\" errcode=\"0\">"\
                                                                                                                            "<count>0</count>"\
                                                                                                                                 "<items>"\
                                                                                                                                        "<item>"\
                                                                                                                                               "<type>poi</type>"\
                                                                                                                                               "<poitype>poitype2</poitype>"\
                                                                                                                                               "<poiid>poiid3</poiid>"\
                                                                                                                                               "<poiname>poiname4</poiname>"\
                                                                                                                                               "<poilon>1235</poilon>"\
                                                                                                                                               "<poilat>9981</poilat>"\
                                                                                                                                               "<tel>tel7</tel>"\
                                                                                                                                               "<address>address8</address>"\
                                                                                                                                               "<linkid>linkid9</linkid>"\
                                                                                                                                               "<distance>distance10</distance>"\
                                                                                                                                        "</item>"\
                                                                                                                                        "<item>"\
                                                                                                                                                "<type>song</type>"\
                                                                                                                                                "<songid>11</songid>"\
                                                                                                                                                "<songname>songname12</songname>"\
                                                                                                                                                "<albumid>albumid13</albumid>"\
                                                                                                                                                "<albumname>albumname14</albumname>"\
                                                                                                                                                "<artistid>artistid15</artistid>"\
                                                                                                                                                "<artistname>artistname16</artistname>"\
                                                                                                                                                "<sourceid>sourceid17</sourceid>"\
                                                                                                                                        "</item>"\
                                                                                                                                        "<item>"\
                                                                                                                                               "<type>phone</type>"\
                                                                                                                                               "<contactid>contactid</contactid>"\
                                                                                                                                               "<firstname>firstname</firstname>"\
                                                                                                                                               "<lastname>lastname</lastname>"\
                                                                                                                                               "<phonetype1>phonetype1</phonetype1>"\
                                                                                                                                               "<phonenumber1>phonenumber1</phonenumber1>"\
                                                                                                                                               "<phonetype2>phonetype2</phonetype2>"\
                                                                                                                                               "<phonenumber2>phonenumber2</phonenumber2>"\
                                                                                                                                               "<phonetype3>phonetype3</phonetype3>"\
                                                                                                                                               "<phonenumber3>phonenumber3</phonenumber3>"\
                                                                                                                                               "<phonetype4>phonetype4</phonetype4>"\
                                                                                                                                               "<phonenumber4>phonenumber4</phonenumber4>"\
                                                                                                                                       "</item>"\
                                                                                                                                "</items>"\
                                                                                                                        "</display>")

#define DISPLAY_VRSTATE_VOICERECOG_RESULT                          std::string("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
                                                                              "<display agent=\"Common\" content=\"VRState\">" \
                                                                                 "<engineType>local</engineType>" \
                                                                                 "<state>播放中</state>" \
                                                                                 "<tag>Voice Control</tag>" \
                                                                                 "<prompt>speak a command</prompt>" \
                                                                                 "<nbest>false</nbest>" \
                                                                                 "<test>" \
                                                                                    "<result>play</result>" \
                                                                                 "</test>"\
                                                                              "</display>")

#define FC_VUI_VRSTATE_VOICERECOG_RESULT std::string("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
    "<notification>" \
        "<id>10</id>" \
        "<type>notifyScreennChanged</type>" \
        "<domain>GLOBAL</domain>" \
    "</notification>")

#define FC_VUI_VRSTATE_HINTS std::string("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
    "<action>" \
        "<id>10</id>" \
        "<type>updatehints</type>" \
        "<params>" \
            "<param><name>domain</name><value>GLOBAL</value></param>" \
            "<param><name>awakenHints</name><value>Hello words</value></param>" \
            "<param><name>helpHints</name><value>This is dome</value></param>" \
            "<param><name>helpHints</name><value>This is VUI helpHints</value></param>" \
            "<param><name>helpHints</name><value>德玛西亚万岁</value></param>" \
        "</params>" \
    "</action>")

#define FC_VUI_VRSTATE_STARTDIAG std::string("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
    "<action>" \
        "<id>10</id>" \
        "<type>updatehints</type>" \
        "<params>" \
            "<param><name>domain</name><value>GLOBAL</value></param>" \
        "</params>" \
    "</action>")



#define VOICERECOG_SEARCH_TYPE                                std::string("type")
#define VOICERECOG_SEARCH_COUNT                               std::string("count")
#define VOICERECOG_SEARCH_POITYPE                             std::string("poitype")
#define VOICERECOG_SEARCH_POIID                               std::string("poiid")
#define VOICERECOG_SEARCH_POINAME                             std::string("poiname")
#define VOICERECOG_SEARCH_POILON                              std::string("poilon")
#define VOICERECOG_SEARCH_POILAT                              std::string("poilat")
#define VOICERECOG_SEARCH_TEL                                 std::string("tel")
#define VOICERECOG_SEARCH_ADDRESS                             std::string("address")
#define VOICERECOG_SEARCH_LINKID                              std::string("linkid")
#define VOICERECOG_SEARCH_DISTANCE                            std::string("distance")

#define VOICERECOG_SEARCH_SONGID                              std::string("songid")
#define VOICERECOG_SEARCH_SONGNAME                            std::string("songname")
#define VOICERECOG_SEARCH_ALBUMID                             std::string("albumid")
#define VOICERECOG_SEARCH_ALBUMNAME                           std::string("albumname")
#define VOICERECOG_SEARCH_ARTISTID                            std::string("artistid")
#define VOICERECOG_SEARCH_ARTISTNAME                          std::string("artistname")
#define VOICERECOG_SEARCH_SOURCEID                            std::string("sourceid")

#define VOICERECOG_SEARCH_CONTACTID                           std::string("contactid")
#define VOICERECOG_SEARCH_FIRSTNAME                           std::string("firstname")
#define VOICERECOG_SEARCH_LASTNAME                            std::string("lastname")
#define VOICERECOG_SEARCH_PHONETYPE1                          std::string("phonetype1")
#define VOICERECOG_SEARCH_PHONETYPE2                          std::string("phonetype2")
#define VOICERECOG_SEARCH_PHONETYPE3                          std::string("phonetype3")
#define VOICERECOG_SEARCH_PHONETYPE4                          std::string("phonetype4")
#define VOICERECOG_SEARCH_PHONENUMBER1                        std::string("phonenumber1")
#define VOICERECOG_SEARCH_PHONENUMBER2                        std::string("phonenumber2")
#define VOICERECOG_SEARCH_PHONENUMBER3                        std::string("phonenumber3")
#define VOICERECOG_SEARCH_PHONENUMBER4                        std::string("phonenumber4")

#define VOICERECOG_SEARCH_NODE_PATH                           std::string("//items/item")
//----------------------------------------Recog Result Xml Node--------------------------------------------------
#define FC_VOICERECOG_RESULT_DISPAY_TAG                          std::string("display")
#define FC_VOICERECOG_RESULT_ENGINETYPE_TAG                      std::string("engineType")
#define FC_VOICERECOG_RESULT_TYPE_TAG                            std::string("type")
#define FC_VOICERECOG_RESULT_STATE_TAG                           std::string("state")
#define FC_VOICERECOG_RESULT_VOLUME_TAG                          std::string("volume")
#define FC_VOICERECOG_RESULT_VOLUMESTATUS_TAG                    std::string("volumeStatus")
#define FC_VOICERECOG_RESULT_RESULT_TAG                          std::string("result")
#define FC_VOICERECOG_RESULT_PROMPT_TAG                          std::string("prompt")

//----------------------------------------Recog Result Xml Value--------------------------------------------------
#define FC_VOICERECOG_RESULT_COMMON_VALUE                        std::string("Common")
#define FC_VOICERECOG_RESULT_VRSTATE_VALUE                       std::string("VRState")
#define FC_VOICERECOG_RESULT_VOLUME_VALUE                        std::string("Volume")
#define FC_VOICERECOG_RESULT_DISPLAY_AGENT                       std::string("agent")
#define FC_VOICERECOG_RESULT_DISPLAY_CONTENT                     std::string("content")

//----------------------------------------ASR State--------------------------------------------------
#define FC_VOICERECOG_RESULT_ASR_PROCESSING                      std::string("processing")
#define FC_VOICERECOG_RESULT_ASR_IDLE                            std::string("idle")
#define FC_VOICERECOG_RESULT_ASR_PROMPTPLAYING                   std::string("promptPlaying")
#define FC_VOICERECOG_RESULT_ASR_FINISHED                        std::string("finished")
#define FC_VOICERECOG_RESULT_ASR_LISTENING                       std::string("listening")

#define FC_VUI_RESULT_AWAKENHINTS                                std::string("awakenHints")
#define FC_VUI_RESULT_HELPHINTS                                  std::string("helpHints")
#define FC_VUI_RESULT_NOTIFYICATION_TAG                          std::string("notification")
#define FC_VUI_RESULT_PARAMS_TAG                                 std::string("params")
#define FC_VUI_RESULT_PARAM_TAG                                  std::string("param")
#define FC_VUI_RESULT_TYPE_TAG                                   std::string("type")
#define FC_VUI_RESULT_STATUS_TAG                                 std::string("status")
#define FC_VUI_RESULT_VOLUME_TAG                                 std::string("volume")
#define FC_VUI_RESULT_VOLUMESTATUS_TAG                           std::string("volumeStatus")
#define FC_VUI_RESULT_RESULT_TAG                                 std::string("result")
#define FC_VUI_RESULT_PROMPT_TAG                                 std::string("prompt")
#define FC_VUI_RESULT_ID_TAG                                     std::string("id")
#define FC_VUI_RESULT_ACTION_TAG                                 std::string("action")
#define FC_VUI_RESULT_NAME_TAG                                   std::string("name")
#define FC_VUI_RESULT_VALUE_TAG                                  std::string("value")
#define FC_VUI_HINTS_NODE_PATH                                   std::string("//params/param")
#define FC_VUI_RESULT_EMPTY                                      std::string("")


#define FC_VUI_RESULT_DOMAIN_CHANGED_NOTIFY           std::string("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
    "<notification>" \
        "<id></id>" \
        "<type></type>" \
        "<domain></domain>" \
    "</notification>")

#define FC_VUI_RESULT_UPDATA_HINTS_ACTION_RESULT      std::string("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
    "<action_result>" \
        "<id></id>" \
        "<action_type></action_type>" \
        "<action_id></action_id>" \
        "<error_no></error_no>" \
    "</action_result>")

#define FC_VUI_RESULT_PRESS_PTT_NOTIFY                std::string("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
    "<notification>" \
        "<id></id>" \
        "<type></type>" \
    "</notification>")

#define FC_VUI_RESULT_START_DIAG_ACITON_RESULT        std::string("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
    "<action_result>" \
        "<id></id>" \
        "<action_type></action_type>" \
        "<action_id></action_id>" \
        "<error_no></error_no>" \
    "</action_result>")

#define FC_VUI_RESULT_STOP_DIAG_NOTIFY                std::string("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
    "<notification>" \
        "<id></id>" \
        "<type></type>" \
    "</notification>")



struct XMLNodeData
{
    std::string id;
    std::string type;
    std::string domain;
    std::string error_no;
    std::string action_id;

    XMLNodeData()
        : id("")
        , type("")
        , domain("")
        , error_no("")
        , action_id("")
    {
    }
};

#endif // VUIMODELXMLDEFINE

