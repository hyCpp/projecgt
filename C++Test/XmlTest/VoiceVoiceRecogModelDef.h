#ifndef VOICEVOICERECOGMODELDEF_H
#define VOICEVOICERECOGMODELDEF_H

#ifndef __cplusplus
#    error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif

#include <QObject>

/*********************Model name define**********************************/
#define FC_VOICERECOG_MODEL_NAME_TEST           QString("testModel")
#define FC_VOICERECOG_MODEL_NAME_PHONE_BASE     QString("phoneBaseModel")
#define FC_VOICERECOG_MODEL_NAME_PHONE_LIST     QString("phoneListModel")
#define FC_VOICERECOG_MODEL_NAME_NAVI_BASE      QString("naviBaseModel")
#define FC_VOICERECOG_MODEL_NAME_NAVI_LIST      QString("naviListModel")
#define FC_VOICERECOG_MODEL_NAME_AUDIO_BASE     QString("audioBaseModel")
#define FC_VOICERECOG_MODEL_NAME_AUDIO_LIST     QString("audioListModel")
#define FC_VOICERECOG_MODEL_NAME_INFO_BASE    QString("infoBaseModel")
#define FC_VOICERECOG_MODEL_NAME_INFO_LIST    QString("infoListModel")
#define FC_VOICERECOG_MODEL_NAME_EU_BASE    QString("EUBaseModel")
#define FC_VOICERECOG_MODEL_NAME_EU_LIST    QString("EUListModel")
#define FC_VOICERECOG_MODEL_NAME_APPS_LIST      QString("appsListModel")
#define FC_VOICERECOG_MODEL_NAME_VOICETAG_BASE  QString("voiceTagBaseModel")
#define FC_VOICERECOG_MODEL_NAME_VRCOMMON_LIST QString("VRCommonListModel")
#define FC_VOICERECOG_DEALING_STATE         (false)
#define FC_VOICERECOG_NOT_DEALING_STATE         (true)
#define FC_VOICERECOG_MODEL_NAME_DEMO_LIST QString("DemoListModel")

// common base model name
#define FC_VOICERECOG_MODEL_NAME_COMMON_BASE    QString("commomBaseModel")

// Common
// #define FC_VOICERECOG_MODEL_NAME_COMMON     QString("commonModel")

/**********************Model property key define*************************/
/*
 * Model property key
 * sample: #define FC_YYY_MODEL_VALUE_ZZZZ  Qstring("zzzz")
 */
#define FC_VOICERECOG_MODEL_VALUE_TEST                  QString("test")
#define FC_VOICERECOG_MODEL_VALUE_PHONE_BASE            QString("phonebase")
#define FC_VOICERECOG_MODEL_VALUE_PHONE_LIST            QString("phoneList")
#define FC_VOICERECOG_MODEL_VALUE_PHONE_LIST_SUBTITLE   QString("phoneListsubtitle")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE             QString("navibase")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_LIST             QString("naviList")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_LIST_SUBTITLE    QString("naviListsubtitle")

#define FC_VOICERECOG_MODEL_VALUE_AUDIO_BASE_SUBTITLE   QString("audiobasesubtitle")
#define FC_VOICERECOG_MODEL_VALUE_AUDIO_LIST            QString("audiolist")
#define FC_VOICERECOG_MODEL_VALUE_AUDIO_LIST_SUBTITLE   QString("audiolistsubtitle")

// common base model property key: engine status and hintstext
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_ENGINE_STATUS     QString("commonbaseenginestatus")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_RECOG_RESULT      QString("commonbaserecogresult")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_VOICE_VOLUME      QString("commonbasevoicevolume")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_PROMPT            QString("commonbaseprompt")

// UI Define
// common base value
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_VRSTATE QString("VRState")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_VRDEALINGSTATE QString("VRDealingState")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_RECCOMMAND QString("RecCommand")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_VOICEVOLUME QString("VoiceVolume")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_TRAININGPHRASE QString("TrainingPhrase")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_TRAININGTIMES QString("TrainingTimes")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_SCOSTATE QString("SCOState") // no used
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_HFPSTATE QString("hfpState")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_TSLSTATE QString("tslState")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_TSLUSABLE QString("tslUsable")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_VRAGENT QString("vrAgent")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_INFOENABLE QString("infoEnable")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_TELPHONESTATE QString("telPhoneState")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_IPODSTATE QString("ipodState")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_PAUSERESUMESTATE QString("pauseResumeState")

// common list value
#define FC_VOICERECOG_MODEL_VALUE_COMMON_LIST_TOPHINTSLIST QString("TopHintsList")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_LIST_MOREHINTSLIST QString("MoreHintsList")
#define FC_VOICERECOG_MODEL_VALUE_COMMON_LIST_NBESTLIST QString("NbestList")

#define FC_VOICERECOG_MODEL_VALUE_COMMON_DEMO_LIST QString("DemoList")
#define FC_VOICERECOG_MODEL_VALUE_DEMO_LIST QString("DemoList")

// Navi base value
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE_COMPLETEADDRESSINFO QString("CompleteAddressInfo")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE_CONFIRMPOINAME QString("ConfirmPOIName")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE_CONFIRMPOIADDRESS QString("ConfirmPOIAddress")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE_STATENAME QString("StateName")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE_CITYNAME QString("CityName")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE_STREETNAME QString("StreetName")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE_LON QString("lon")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE_LAT QString("lat")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE_CONFIRMDELETEDESTINATION QString("ConfirmDeleteDestination")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE_SETROUTE QString("SetRoute")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE_CONFIRMDESTINAITON QString("ConfirmDestination")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE_INPUTTEDADDRESS QString("inputtedAddress")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_BASE_HOUSENUMBERADDRESS QString("houseNumberAddress")


// Navi list value
#define FC_VOICERECOG_MODEL_VALUE_NAVI_LIST_HISTORYADDRESSLIST QString("HistoryAddressList")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_LIST_ADDRESSDELETELIST QString("AddressDeleteList")
#define FC_VOICERECOG_MODEL_VALUE_NAVI_LIST_POISELECTLIST QString("POISelectList")

// Audio base value
#define FC_VOICERECOG_MODEL_VALUE_AUDIO_BASE_DEVICESTATUS QString("deviceStatus")
#define FC_VOICERECOG_MODEL_VALUE_AUDIO_BASE_PROMPTTITLE QString("prompTitle")

// Audio list value
#define FC_VOICERECOG_MODEL_VALUE_AUDIO_LIST_PLAYLISTLIST QString("playlistList")
#define FC_VOICERECOG_MODEL_VALUE_AUDIO_LIST_SOURCELIST QString("sourceList")
#define FC_VOICERECOG_MODEL_VALUE_AUDIO_LIST_MUSICLIST QString("musicList")

// App list value
#define FC_VOICERECOG_MODEL_VALUE_APP_LIST_APPLIST QString("appList")

// VoiceTag base value
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CAND1NAME QString("cand1Name")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CAND1PHONETYPE1 QString("cand1PhoneType1")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CAND1PHOMENUM1 QString("cand1PhomeNum1")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_PHONE2STATUS QString("phone2Status")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_PHONE3STATUS QString("phone3Status")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_PHONE4STATUS QString("phone4Status")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CAND1PHONETYPE2 QString("cand1PhoneType2")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CAND1PHOMENUM2 QString("cand1PhomeNum2")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CAND1PHONETYPE3 QString("cand1PhoneType3")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CAND1PHOMENUM3 QString("cand1PhomeNum3")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CAND1PHONETYPE4 QString("cand1PhoneType4")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CAND1PHOMENUM4 QString("cand1PhomeNum4")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CAND2NAME QString("cand2Name")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CAND3STATUS QString("cand3Status")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CAND3NAME QString("cand3Name")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CANDNAME QString("candName")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CANDPHONETYPE1 QString("candPhoneType1")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CANDPHONENUM1 QString("candPhoneNum1")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CURRENTPHONE2STATUS QString("currentphone2Status")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CURRENTPHONE3STATUS QString("currentphone3Status")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CURRENTPHONE4STATUS QString("currentphone4Status")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CANDPHONETYPE2 QString("candPhoneType2")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CANDPHONENUM2 QString("candPhoneNum2")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CANDPHONETYPE3 QString("candPhoneType3")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CANDPHONENUM3 QString("candPhoneNum3")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CANDPHONETYPE4 QString("candPhoneType4")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CANDPHONENUM4 QString("candPhoneNum4")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_PHONETYPEICON QString("phoneTypeIcon")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_MICCONNECTSTATUS QString("micConnectStatus")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_BTHFPCONNECTSTATUS QString("btHfpConnectStatus")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_PHONEUSESTATUS QString("phoneUseStatus")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_CANDIDATES_INFO QString("candidatesInfo")
#define FC_VOICERECOG_MODEL_VALUE_VOICETAG_BASE_SELECT_CANDIDATE_INFO QString("selectCandidateInfo")

// VRPhone base value
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRCALLCONTACTNAME QString("strCallContactName")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRCALLPHONENUM QString("strCallPhoneNum")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRCALLPHONETYPEMARK QString("strCallPhoneTypeMark")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_BOUTBOXSTATE QString("bOutBoxState")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_BHAVENEXTPAGE QString("bHaveNextPage")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_BHAVEPREVPAGE QString("bHavePrevPage")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRDIALPHONENUM QString("strDialPhoneNum")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRCALLINFO QString("strCallInfo")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRSMSCONTENT QString("strSMSContent")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRADDNUM QString("strAddNum")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRTONENUM QString("strToneNum")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRSMSCONTACTNAME QString("strSMSContactName")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRSMSPHONENUM QString("strSMSPhoneNum")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRSMSPHONETYPEMARK QString("strSMSPhoneTypeMark")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRCONTACTNAME QString("strContactName")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRPHONENUM QString("strPhoneNum")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRHISTORYDATE QString("strHistoryDate")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRHISTORYTIME QString("strHistoryTime")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRSENDERNAME QString("strSenderName")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRSENDERNUM QString("strSenderNum")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRRECEIVEDDATE QString("strReceivedDate")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRRECEIVEDTIME QString("strReceivedTime")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_STRRMSCONTENT QString("strRMSContent")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_HISTORYTYPE QString("strHistoryType")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_PROMPTCONTACTNAME QString("strPromptContactName")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_BCALLINFOVALUETYPE QString("bCallInfoValueType")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_BASE_BSENDERVALUETYPE QString("bSenderValueType")

// VRPhone list value
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_LIST_CONTACTNAMELIST QString("ContactNameList")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_LIST_PHONETYPELIST QString("PhoneTypeList")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_LIST_HISTORYLIST QString("HistoryList")
#define FC_VOICERECOG_MODEL_VALUE_VRPHONE_LIST_MSGCONTENTLIST QString("MsgContentList")

// VRInfo base value
#define FC_VOICERECOG_MODEL_VALUE_VRINFO_BASE_BROUTESTATE QString("bRouteState")
#define FC_VOICERECOG_MODEL_VALUE_VRINFO_BASE_BREGROUTESTATE QString("bRegRouteState")

// VRInfo list value
#define FC_VOICERECOG_MODEL_VALUE_VRINFO_LIST_ROUTENAMELIST QString("RouteNameList")
#define FC_VOICERECOG_MODEL_VALUE_VRINFO_LIST_SELECTINFOLIST QString("SelectInfoList")

// VREU base value
#define FC_VOICERECOG_MODEL_VALUE_VREU_BASE_STRVRSTATUSICON QString("strVRStatusIcon")
#define FC_VOICERECOG_MODEL_VALUE_VREU_BASE_STRLISTTYPE QString("strListType")
#define FC_VOICERECOG_MODEL_VALUE_VREU_BASE_STRVRSTATUSTEXT QString("strVRStatusText")
#define FC_VOICERECOG_MODEL_VALUE_VREU_BASE_STRRECOGRESULTS QString("strRecogResults")
#define FC_VOICERECOG_MODEL_VALUE_VREU_BASE_STRPHONENUMBER QString("strPhoneNumber")

// VREU list value
#define FC_VOICERECOG_MODEL_VALUE_VREU_LIST_TOPCMDLIST QString("TopCmdList")
#define FC_VOICERECOG_MODEL_VALUE_VREU_LIST_SUBCMDLIST QString("SubCmdList")
#define FC_VOICERECOG_MODEL_VALUE_VREU_LIST_DESTLIST QString("DestList")

// VR Prompt base value
#define FC_VOICERECOG_MODEL_VALUE_VRPROMPT_BASE_VRPROMPT QString("VRPrompt")

// VR Prompt key of map
#define FC_VOICERECOG_MODEL_VALUE_VRPROMPT_BASE_VRPROMPTCONTENT QString("VRPromptContent")
#define FC_VOICERECOG_MODEL_VALUE_VRPROMPT_BASE_VRPROMPTTEXT QString("VRPromptText")


// common
// #define FC_VOICERECOG_MODEL_VALUE_SESSION               QString("session")
// #define FC_VOICERECOG_MODEL_VALUE_TASK_ID               QString("taskId")
// #define FC_VOICERECOG_MODEL_VALUE_OPEN_SESSION_RESULT   QString("openSessionResult")
// #define FC_VOICERECOG_MODEL_VALUE_CLOSE_SESSION_RESULT  QString("closeSessionResult")
// #define FC_VOICERECOG_MODEL_VALUE_START_RECOG_STATE     QString("startRecogState")
// #define FC_VOICERECOG_MODEL_VALUE_START_RECOG_RESULT    QString("startRecogResult")


/*********************Model uodata key**********************************/

#define VRCOMMON_TOPHINTSLIST_HINT                      QString("hint")
#define VRCOMMON_MOREHINTSLIST_HINT                     QString("hint")
#define VRCOMMON_NBESTLIST_NAME                         QString("name")

#define VRNAVI_ADDRESSDELETELIST_NAME                   QString("name")
#define VRNAVI_HISTORYADDRESSLIST_NAME                  QString("name")
#define VRNAVI_POISELECTLIST_NAME                       QString("name")
#define VRNAVI_POISELECTLIST_DIRECTION                  QString("direction")
#define VRNAVI_POISELECTLIST_DISTANCE                   QString("distance")
#define VRNAVI_POISELECTLIST_UNIT                       QString("unit")

#define VRVOICETAG_VOICETAGBASE_CAND1NAME               QString("cand1Name")
#define VRVOICETAG_VOICETAGBASE_CAND1PHONETYPE1         QString("cand1PhoneType1")
#define VRVOICETAG_VOICETAGBASE_CAND1PHOMENUM1          QString ("cand1PhoneNum1")
#define VRVOICETAG_VOICETAGBASE_CAND1PHONETYPE2         QString ("cand1PhoneType2")
#define VRVOICETAG_VOICETAGBASE_CAND1PHOMENUM2          QString ("cand1PhoneNum2")
#define VRVOICETAG_VOICETAGBASE_CAND1PHONETYPE3         QString ("cand1PhoneType3")
#define VRVOICETAG_VOICETAGBASE_CAND1PHOMENUM3          QString ("cand1PhoneNum3")
#define VRVOICETAG_VOICETAGBASE_CAND1PHONETYPE4         QString ("cand1PhoneType4")
#define VRVOICETAG_VOICETAGBASE_CAND1PHOMENUM4          QString ("cand1PhoneNum4")
#define VRVOICETAG_VOICETAGBASE_CAND2NAME               QString ("cand2Name")
#define VRVOICETAG_VOICETAGBASE_CAND2NUM                QString ("cand2Num")
#define VRVOICETAG_VOICETAGBASE_CAND3NAME               QString ("cand3Name")
#define VRVOICETAG_VOICETAGBASE_CAND3NUM                QString ("cand3Num")
#define VRVOICETAG_VOICETAGBASE_CANDNAME                QString ("candName")
#define VRVOICETAG_VOICETAGBASE_CANDPHONETYPE1          QString ("candPhoneType1")
#define VRVOICETAG_VOICETAGBASE_CANDPHONENUM1           QString ("candPhoneNum1")
#define VRVOICETAG_VOICETAGBASE_CANDPHONETYPE2          QString ("candPhoneType2")
#define VRVOICETAG_VOICETAGBASE_CANDPHONENUM2           QString ("candPhoneNum2")
#define VRVOICETAG_VOICETAGBASE_CANDPHONETYPE3          QString ("candPhoneType3")
#define VRVOICETAG_VOICETAGBASE_CANDPHONENUM3           QString ("candPhoneNum3")
#define VRVOICETAG_VOICETAGBASE_CANDPHONETYPE4          QString ("candPhoneType4")
#define VRVOICETAG_VOICETAGBASE_CANDPHONENUM4           QString ("candPhoneNum4")

#define VRAPPS_APPLIST_NAME                             QString("name")

#define VRAUDIO_PLAYLIST_NAME                           QString("name")
#define VRAUDIO_MUSICLIST_NAME                          QString("name")
#define VRAUDIO_SOURCELIST_NAME                         QString("name")


// Phone Commom
#define VRPHONE_STRADDNUM_NUMBER                        QString("number")
#define VRPHONE_PHONETYPELIST_PHONTTYPE                 QString("phoneType")
#define VRPHONE_PHONETYPELIST_NUMBER                    QString("number")
#define VRPHONE_PHONETYPELIST_INDEX                     QString("index")

// Phone NA
#define VRPHONE_HISTORYLIST_INDEX                       QString("index")
#define VRPHONE_HISTORYLIST_CALLTYPE                    QString("calltype")
#define VRPHONE_HISTORYLIST_ENTRY                       QString("entry")
#define VRPHONE_HISTORYLIST_ENTRYTYPE                   QString("phonenamevalue")
#define VRPHONE_HISTORYLIST_PHONETYPE                   QString("phoneType")
#define VRPHONE_HISTORYLIST_TIMESTAMP                   QString("timestamp")
#define VRPHONE_MSGCONTENTLIST_INDEX                    QString("index")
#define VRPHONE_MSGCONTENTLIST_MESSAGEBODY              QString("messagebody")
#define VRPHONE_STRSENDER_NAME                          QString("name")
#define VRPHONE_STRSENDER_PHONENUMBER                   QString("phonenumber")
#define VRPHONE_CONTACTNAMELIST_NAME                    QString("name")
#define VRPHONE_CONTACTNAMELIST_INDEX                   QString("ItemNumber")

// Phone EU
#define VREU_TOPCMDLIST_COMMAND                         QString("command")
#define VREU_SUBCMDLIST_COMMAND                         QString("command")
#define VREU_EXISTSTATUS_COMMAND                        QString("selectAvailable")

// Info
#define VRINFO_SELECTINFOLIST_INFO                   QString("info")
#define VRINFO_SELECTINFOLIST_CONTENT                QString("content")

// vr start state

#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_SEARCH_PRERATION QString("searchPreparation")  // no used
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_DICTIONARY_DATA QString("dictionaryData") // no used
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_LANGUAGE_SPECIFIC QString("languageSpecific") // no used
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_CONTACTS_TRANSFERRED QString("contactsTransferred") // no used
#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_MEDIAVOCS QString("mediaVOCS") // no used

#define FC_VOICERECOG_MODEL_VALUE_COMMON_BASE_PVR_FLAG QString("pvrFlag")

// Define StartIndex and Count
#define VRLIST_START_INDEX_NAME                         QString("startIndex")
#define VRLIST_COUNT_NAME                               QString("count")
#define VR_NAVI_LIST_START_INDEX_NAME                   QString("navistartIndex")
#define VR_NAVI_LIST_COUNT_NAME                         QString("navicount")

#define VR_NAVI_HISTORY_LIST_LONGITUDE                  QString("longitude")
#define VR_NAVI_HISTORY_LIST_LATITUDE                   QString("latitude")
#define VR_NAVI_HISTORY_LIST_NAME                       QString("name")
#define VR_NAVI_HISTORY_LIST_ADDRESS                    QString("routeAddress")

#define VR_NAVI_ADDRESS_DELETE_LIST_LONGITUDE           QString("longitude")
#define VR_NAVI_ADDRESS_DELETE__LIST_LATITUDE           QString("latitude")
#define VR_NAVI_ADDRESS_DELETE_LIST_NAME                QString("name")
#define VR_NAVI_ADDRESS_DELETE_LIST_ADDRESS             QString("routeAddress")

// Define phone status
#define FC_VOICE_PHONE_STATUS_TYPE_DISCONNECTED             QString("disconnected")
#define FC_VOICE_PHONE_STATUS_TYPE_IDLE                     QString("idle")
#define FC_VOICE_PHONE_STATUS_TYPE_INCOMMING                QString("incoming")
#define FC_VOICE_PHONE_STATUS_TYPE_DIALING                  QString("dialing")
#define FC_VOICE_PHONE_STATUS_TYPE_WAITING                  QString("waiting")
#define FC_VOICE_PHONE_STATUS_TYPE_TALKING                  QString("talking")
#define FC_VOICE_PHONE_STATUS_TYPE_TALKINGINCOMING          QString("talkingincoming")
#define FC_VOICE_PHONE_STATUS_TYPE_HELDTALKING              QString("heldtalking")
#define FC_VOICE_PHONE_STATUS_TYPE_HELDTALKINGINCOMING      QString("heldtalkingincoming")
#define FC_VOICE_PHONE_STATUS_TYPE_HELDNOTALKING            QString("heldnotalking")
#define FC_VOICE_PHONE_STATUS_TYPE_HELDNOTALKINGINCOMING    QString("heldnotalkingincoming")
#define FC_VOICE_PHONE_STATUS_TYPE_INCOMINGHELD             QString("incomingheld")

// Define TelePhone Interrupt Type
#define FC_VOICE_PHONE_INTERRUPT_HELP_AND_SAFELY_CONNECTING                  QString("telephone_interrupt_help_and_safely_connecting")
#define FC_VOICE_PHONE_INTERRUPT_OPERATOR_AND_DESTINATION_ASSIST             QString("telephone_interrupt_operator_and_destination_assist")
#define FC_VOICE_PHONE_INTERRUPT_CALLRECORDING_AND_CONTACT_MANUAL_UPDATING   QString("telephone_interrupt_callrecording_and_contact_manual_updating")

// Compatible Handle
#define COMPARE_SPECIAL_STRING(x) (QString::compare(x, QString("")) == 0 || QString::compare(x, QString("''")) == 0)

enum ROLE_ID
{
    ROLE_ID_CALL_ID = Qt::UserRole + 1,
    ROLE_ID_TREE_ID,
    ROLE_ID_NEXT_TREE_ID,
    ROLE_ID_CALL_NUMBER,
    ROLE_ID_NAVI_ADDRESS_NAME,
    ROLE_ID_NAVI_ADDRESS_ID,
    ROLE_ID_AUDIO_SONG_NAME,
    ROLE_ID_AUDIO_SONG_ID,
    ROLE_ID_ALL_FLAG
};

enum SHOWTYPE
{
    SHOW_TYPE_TELEPHONE_HINT = 0,
    SHOW_TYPE_SPEAK_PHONE_NUMBER,
    SHOW_TYPE_CONFIRM_PHONE,
    SHOW_TYPE_SPEAK_DIGITS,
    SHOE_TYPE_SPEAK_NAME_OR_NUMBER,
    SHOE_TYPE_PHONE_NUMBER_LIST
};

#endif // VOICEVOICERECOGMODELDEF_H
/* EOF */
