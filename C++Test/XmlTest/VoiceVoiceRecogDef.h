#ifndef VOICEVOICERECOGDEF_H
#define VOICEVOICERECOGDEF_H

#include <QObject>

// FC Define
#define FC_VOICE_TSL_APP_NAME                      QString("VR_TSL_APP")
#define FC_VOICE_NATIVE_APP_NAME                   QString("VR_NATIVE_APP")

enum VoiceVoiceRecog_Request_Res
{
    VoiceVoiceRecog_Request_Res_OK = 0,
    VoiceVoiceRecog_Request_Res_ParamError,
    VoiceVoiceRecog_Request_Res_RpcError
};

enum VoiceVoiceRecog_OperResult
{
    VoiceVoiceRecog_OperResult_Undefined = 0,
    VoiceVoiceRecog_OperResult_OK,
    VoiceVoiceRecog_OperResult_Invalid,
};

enum VoiceVoiceRecog_DomainType
{
    VoiceVoiceRecog_DomainType_Global = 0,
    VoiceVoiceRecog_DomainType_Phone,
    VoiceVoiceRecog_DomainType_Navigation,
    VoiceVoiceRecog_DomainType_Apps,
    VoiceVoiceRecog_DomainType_Audio,
    VoiceVoiceRecog_DomainType_Info,
    VoiceVoiceRecog_DomainType_Help,
    VoiceVoiceRecog_DomainType_HVAC,
    VoiceVoiceRecog_DomainType_InCalling,
    VoiceVoiceRecog_DomainType_InMessage,
    VoiceVoiceRecog_DomainType_Training,
    VoiceVoiceRecog_DomainType_SendTone,
    VoiceVoiceRecog_DomainType_VoiceTag,
    VoiceVoiceRecog_DomainType_POI,
    VoiceVoiceRecog_DomainType_Radio,
    VoiceVoiceRecog_DomainType_DictUndefine = 100,
    VoiceVoiceRecog_DomainType_DictMusic,
    VoiceVoiceRecog_DomainType_DictHFD,
    VoiceVoiceRecog_DomainType_DictMessage,
    VoiceVoiceRecog_DomainType_DictNavigation,
    VoiceVoiceRecog_DomainType_DictState,
    VoiceVoiceRecog_DomainType_DictCity,
    VoiceVoiceRecog_DomainType_DictStreet,
    VoiceVoiceRecog_DomainType_DictPOI,
    VoiceVoiceRecog_DomainType_DictOthers
};

enum VoiceVoiceRecog_ReqPreConditionResult
{
    VoiceVoiceRecog_ReqPreConditionResult_Undefine = 0,
    VoiceVoiceRecog_ReqPreConditionResult_Success,
    VoiceVoiceRecog_ReqPreConditionResult_CreatSessionFailed,
    VoiceVoiceRecog_ReqPreConditionResult_OpenSessionFailed,
    VoiceVoiceRecog_ReqPreConditionResult_GetHintsFailed,
    VoiceVoiceRecog_ReqPreConditionResult_Max = 30,
};

enum VoiceVoiceRecog_VoiceTag_Start_Res
{
    VoiceVoiceRecog_VoiceTag_NotLogin = 0,
    VoiceVoiceRecog_VoiceTag_Phone_NotLogin,
    VoiceVoiceRecog_VoiceTag_Phone_NotConnected,
    VoiceVoiceRecog_VoiceTag_ReadyTo_Start
};

enum VoiceVoiceRecog_TSLPhoneCallActionStatus
{
    VoiceVoiceRecog_TSLPhoneCallActionStatus_Interrupt = 0,
    VoiceVoiceRecog_TSLPhoneCallActionStatus_Wait,
    VoiceVoiceRecog_TSLPhoneCallActionStatus_Execute
};

// Button operation  value (UI using)
enum VoiceVoiceRecog_BtnOper_Value
{
    VoiceVoiceRecog_BtnOper_Value_Min = 0,
    VoiceVoiceRecog_BtnOper_Value_Select_One,
    VoiceVoiceRecog_BtnOper_Value_Select_Two,
    VoiceVoiceRecog_BtnOper_Value_Select_Three,
    VoiceVoiceRecog_BtnOper_Value_Select_Four,
    VoiceVoiceRecog_BtnOper_Value_Select_Five,
    VoiceVoiceRecog_BtnOper_Value_Select_Six,
    VoiceVoiceRecog_BtnOper_Value_Phone,
    VoiceVoiceRecog_BtnOper_Value_Navi,
    VoiceVoiceRecog_BtnOper_Value_Apps,
    VoiceVoiceRecog_BtnOper_Value_Audio,
    VoiceVoiceRecog_BtnOper_Value_Climate,
    VoiceVoiceRecog_BtnOper_Value_Help,
    VoiceVoiceRecog_BtnOper_Value_Info,
    VoiceVoiceRecog_BtnOper_Value_Go_Back,
    VoiceVoiceRecog_BtnOper_Value_Start_Over,
    VoiceVoiceRecog_BtnOper_Value_Pause,
    VoiceVoiceRecog_BtnOper_Value_Resume,
    VoiceVoiceRecog_BtnOper_Value_Cancel,
    VoiceVoiceRecog_BtnOper_Value_More_Hints,
    VoiceVoiceRecog_BtnOper_Value_Pre_Page,
    VoiceVoiceRecog_BtnOper_Value_Next_Page,
    VoiceVoiceRecog_BtnOper_Value_First_Page,
    VoiceVoiceRecog_BtnOper_Value_End_Page,
    VoiceVoiceRecog_BtnOper_Value_Yes,
    VoiceVoiceRecog_BtnOper_Value_No,
    VoiceVoiceRecog_BtnOper_Value_Ok,
    VoiceVoiceRecog_BtnOper_Value_Start,
    VoiceVoiceRecog_BtnOper_Value_Beginning,
    VoiceVoiceRecog_BtnOper_Value_End,
    VoiceVoiceRecog_BtnOper_Value_Go_Directly,
    VoiceVoiceRecog_BtnOper_Value_Add_To_Route,
    VoiceVoiceRecog_BtnOper_Value_Call,
    VoiceVoiceRecog_BtnOper_Value_Reply,
    VoiceVoiceRecog_BtnOper_Value_Send_Message,
    VoiceVoiceRecog_BtnOper_Value_Next,
    VoiceVoiceRecog_BtnOper_Value_Previous,
    VoiceVoiceRecog_BtnOper_Value_Retry,
    VoiceVoiceRecog_BtnOper_Value_Tutorials,
    VoiceVoiceRecog_BtnOper_Value_Voice_Training,
    VoiceVoiceRecog_BtnOper_Value_Along_Route,
    VoiceVoiceRecog_BtnOper_Value_Near_Destination,
    VoiceVoiceRecog_BtnOper_Value_Near_Here,
    VoiceVoiceRecog_BtnOper_Value_Along_My_Route,
    VoiceVoiceRecog_BtnOper_Value_Along_This_Road,
    VoiceVoiceRecog_BtnOper_Value_Along_A_Saved_Route,
    VoiceVoiceRecog_BtnOper_Value_Album,
    VoiceVoiceRecog_BtnOper_Value_Artist,
    VoiceVoiceRecog_BtnOper_Value_Song,
    VoiceVoiceRecog_BtnOper_Value_Compose,
    VoiceVoiceRecog_BtnOper_Value_Genre,
    VoiceVoiceRecog_BtnOper_Value_Podcase,
    VoiceVoiceRecog_BtnOper_Value_Playlist,
    VoiceVoiceRecog_BtnOper_Value_Audiobook,
    VoiceVoiceRecog_BtnOper_Value_Candidate1_Num2,
    VoiceVoiceRecog_BtnOper_Value_Candidate1_Num3,
    VoiceVoiceRecog_BtnOper_Value_Candidate1_Num4,
    VoiceVoiceRecog_BtnOper_Value_Candidate2,
    VoiceVoiceRecog_BtnOper_Value_Candidate3,
    VoiceVoiceRecog_BtnOper_Value_Candidate_Num2,
    VoiceVoiceRecog_BtnOper_Value_Candidate_Num3,
    VoiceVoiceRecog_BtnOper_Value_Candidate_Num4,
    VoiceVoiceRecog_BtnOper_Value_Hard_Key_Off_Hook_Short_Press,
    VoiceVoiceRecog_BtnOper_Value_Hard_Key_Off_Hook_Long_Press,
    VoiceVoiceRecog_BtnOper_Value_Hard_Key_Tel_Short_Press,
    VoiceVoiceRecog_BtnOper_Value_Hard_Key_Tel_Long_Press,
    VoiceVoiceRecog_BtnOper_Value_Do_Not_Tell_Me_Again,
    VoiceVoiceRecog_BtnOper_Value_Set_PVR_Flag,
    VoiceVoiceRecog_BtnOper_Value_PTT_Hard_Key_Short_Press,
    VoiceVoiceRecog_BtnOper_Value_PTT_Hard_Key_Long_Press,
    VoiceVoiceRecog_BtnOper_Value_Back_Long_Press,
    VoiceVoiceRecog_BtnOper_Value_Back_Short_Press,
    VoiceCoiceRecog_BtnOper_Value_Stop_Reading,
    VoiceVoiceRecog_BtnOper_Value_Hard_Key_Enter_Long_Press,
    VoiceVoiceRecog_BtnOper_Value_Hard_Key_Enter_Short_Press,
    VoiceVoiceRecog_BtnOper_Value_Debug_Input_On,
    VoiceVoiceRecog_BtnOper_Value_Debug_Input_Off,
    VoiceVoiceRecog_BtnOper_Value_Debug_Output_On,
    VoiceVoiceRecog_BtnOper_Value_Debug_Output_Off,
    VoiceVoiceRecog_BtnOper_Value_Web_Search,
    VoiceVoiceRecog_BtnOper_Value_Meter_Back_Short_Press,
    VoiceVoiceRecog_BtnOper_Value_Meter_Back_Long_Press,
    VoiceVoiceRecog_BtnOper_Value_Hard_Key_Enter_Normal_Press,
    VoiceVoiceRecog_BtnOper_Value_Meter_Back_Normal_Press,
    VoiceVoiceRecog_BtnOper_Value_PTT_Hard_Key_Short_Press_Special,
    VoiceVoiceRecog_BtnOper_Value_PTT_Hard_Key_Press_Special_In_EndTaskStatus,
    VoiceVoiceRecog_BtnOper_Value_Hard_Key_Cancel_VR,

    VoiceVoiceRecog_BtnOper_Value_Max
};

enum VoiceVoiceRecog_MediaInfo_SrcId
{
    VoiceVoiceRecog_MediaInfo_SrcID_Invalid     = 0,
    VoiceVoiceRecog_MediaInfo_SrcID_AUX         = 2,
    VoiceVoiceRecog_MediaInfo_SrcID_USB1        = 3,
    VoiceVoiceRecog_MediaInfo_SrcID_USB2        = 4,
    VoiceVoiceRecog_MediaInfo_SrcID_BTA         = 5,
    VoiceVoiceRecog_MediaInfo_SrcID_HFCall      = 6,
    VoiceVoiceRecog_MediaInfo_SrcID_HFDialIn    = 7,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps        = 8,
    VoiceVoiceRecog_MediaInfo_SrcID_MailReadout = 9,
    VoiceVoiceRecog_MediaInfo_SrcID_Siri        = 10,
    VoiceVoiceRecog_MediaInfo_SrcID_FM          = 11,
    VoiceVoiceRecog_MediaInfo_SrcID_AM          = 12,
    VoiceVoiceRecog_MediaInfo_SrcID_RSE         = 13,
    VoiceVoiceRecog_MediaInfo_SrcID_SXM         = 14,
    VoiceVoiceRecog_MediaInfo_SrcID_Radio       = 15,
    VoiceVoiceRecog_MediaInfo_SrcID_TV          = 16,
    VoiceVoiceRecog_MediaInfo_SrcID_DTV         = 17,
    VoiceVoiceRecog_MediaInfo_SrcID_DAB         = 18,
    VoiceVoiceRecog_MediaInfo_SrcID_Disc        = 21,
    VoiceVoiceRecog_MediaInfo_SrcID_Miracast    = 22,
    VoiceVoiceRecog_MediaInfo_SrcID_Mirrorlink  = 23,
    VoiceVoiceRecog_MediaInfo_SrcID_Off         = 25,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps1       = 26,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps2       = 27,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps3       = 28,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps4       = 29,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps5       = 30,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps6       = 31,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps7       = 32,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps8       = 33,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps9       = 34,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps10      = 35,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps11      = 36,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps12      = 37,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps13      = 38,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps14      = 39,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps15      = 40,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps16      = 41,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps17      = 42,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps18      = 43,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps19      = 44,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps20      = 45,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps21      = 46,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps22      = 47,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps23      = 48,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps24      = 49,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps25      = 50,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps26      = 51,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps27      = 52,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps28      = 53,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps29      = 54,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps30      = 55,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps31      = 56,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps32      = 57,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps33      = 58,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps34      = 59,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps35      = 60,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps36      = 61,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps37      = 62,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps38      = 63,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps39      = 64,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps40      = 65,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps41      = 66,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps42      = 67,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps43      = 68,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps44      = 69,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps45      = 70,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps46      = 71,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps47      = 72,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps48      = 73,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps49      = 74,
    VoiceVoiceRecog_MediaInfo_SrcID_Apps50      = 75,
    VoiceVoiceRecog_MediaInfo_SrcID_Ipod        = 76,
    VoiceVoiceRecog_MediaInfo_SrcID_Num,
    VoiceVoiceRecog_MediaInfo_SrcID_Ipod1,
    VoiceVoiceRecog_MediaInfo_SrcID_Ipod2,
};

enum VoiceVoiceRecog_VrServiceStatus
{
    VoiceVoiceRecog_VrServiceStatus_Avaiable                = 1,
    VoiceVoiceRecog_VrServiceStatus_SearchFuncError         = 2,
    VoiceVoiceRecog_VrServiceStatus_DictDataError           = 3,
    VoiceVoiceRecog_VrServiceStatus_LangDataError           = 4,
    VoiceVoiceRecog_VrServiceStatus_ContactDataError        = 5,
    VoiceVoiceRecog_VrServiceStatus_MediaVOCSDataError      = 6,
    VoiceVoiceRecog_VrServiceStatus_MicrophoneError         = 7,
    VoiceVoiceRecog_VrServiceStatus_PTTSWError              = 8,
    VoiceVoiceRecog_VrServiceStatus_HigherInterruptError    = 9,
    VoiceVoiceRecog_VrServiceStatus_CNLanguage_Error        = 10,
    VoiceVoiceRecog_VrServiceStatus_Service_NoStart_Error   = 29,
    VoiceVoiceRecog_VrServiceStatus_Unknown                 = 30,
};

enum VoiceVoiceRecog_VrServerStatus
{
    VoiceVoiceRecog_VrServerStatus_Avaiable    = 1,
    VoiceVoiceRecog_VrServerStatus_Unavaiable  = 2,
    VoiceVoiceRecog_VrServerStatus_Unknown     = 30,
};

enum VoiceVoiceRecog_VrDictionResultCode
{
    VoiceVoiceRecog_DictionResultCode_Success   = 0,
    VoiceVoiceRecog_DictionResultCode_Error     = 1,
    VoiceVoiceRecog_DictionResultCode_Failure   = 2,
    VoiceVoiceRecog_DictionResultCode_Cancel    = 3,
};

enum VoiceVoiceRecog_TelCall_Interrupt_Type
{
    VoiceVoiceRecog_TelCall_Interrupt_Rereleased = 0,
    // refer to NITelInterruptType (enum value is 16,17,18,19,20)
    VoiceVoiceRecog_TelCall_Interrupt_Type_Help_And_Safely_Connecting,
    // refer to NITelInterruptType (enum value is 48)
    VoiceVoiceRecog_TelCall_Interrupt_Type_Operator_And_Destination_Assist,
    // refer to GBook
    VoiceVoiceRecog_TelCall_Interrupt_Type_CallRecording_And_Contact_Manual_Updating //
};

#define FC_VOICE_VOICERECOG_SERVICE                                     QString("fcVoiceRecognizerService")
#define FC_METER_SERVICE                                                QString("fcMeterService")
#define FC_BTMAP_SERVICE                                                QString("fcBtMapService")
#define FC_POISEARCH_SERVICE                                            QString("fcPoiSearchService")
#define FC_VOICE_TSL_SERVICE                                            QString("fcVoiceTSLService")
#define FC_TELEPHONY_SERVICE                                            QString("fcTelephonyService")

// Display status
#define FC_VOICE_DISPLAYSTATUS_STATUS_PVR_ENTER                         QString("PVREnter")
#define FC_VOICE_DISPLAYSTATUS_STATUS_PVR_EXIT                          QString("PVRExit")
#define FC_VOICE_DISPLAYSTATUS_RESULT_OK                                QString("ok")
#define FC_VOICE_DISPLAYSTATUS_RESULT_FAILED                            QString("failed")

// Hybrid button operation result value
#define FC_VOICE_HYBRID_BUTTON_RESULT_YES                               QString("Hybrid_Button_Ok")
#define FC_VOICE_HYBRID_BUTTON_RESULT_NO                                QString("Hybrid_Button_No")
#define FC_VOICE_HYBRID_BUTTON_RESULT_BACK                              QString("Hybrid_Button_Back")

// VRActionResult status
#define FC_VOICE_VRACTIONRESULT_RESULT_SUCCESS                          QString("success")
#define FC_VOICE_VRACTIONRESULT_RESULT_FAILED                           QString("failed")

// agent value as following
#define FC_VOICE_AGENT_VALUE_TOP_MENU                        QString("topmenu")
#define FC_VOICE_AGENT_VALUE_NAVI                            QString("navi")
#define FC_VOICE_AGENT_VALUE_PHONE                           QString("phone")
#define FC_VOICE_AGENT_VALUE_MEDIA                           QString("media")
#define FC_VOICE_AGENT_VALUE_APPS                            QString("apps")
#define FC_VOICE_AGENT_VALUE_SENDTONE                        QString("sendtone")
#define FC_VOICE_AGENT_VALUE_CLIMATE                         QString("climate")
#define FC_VOICE_AGENT_VALUE_DICTATION                       QString("dictation")
#define FC_VOICE_AGENT_VALUE_VOICETAG                        QString("voicetag")
#define FC_VOICE_AGENT_VALUE_HELP                            QString("help")
#define FC_VOICE_AGENT_VALUE_ADAPTION                        QString("adaptation")
#define FC_VOICE_AGENT_VALUE_TUNER                           QString("tuner")
#define FC_VOICE_AGENT_VALUE_INFORMATION                     QString("information")

// PopMsg Type define as following
#define FC_VOICE_POP_MSG_TYPE_NORMAL                         QString("normal")
#define FC_VOICE_POP_MSG_TYPE_PHONE_NOT_CONNECT              QString("err_phone_not_connected")
#define FC_VOICE_POP_MSG_TYPE_PHONE_NOT_REGISTER             QString("err_phone_not_register")
#define FC_VOICE_POP_MSG_TYPE_VOICETAG_NONE                  QString("err_voice_tag_none")
#define FC_VOICE_POP_MSG_TYPE_ACTION_EXIT                    QString("action_exit")

// ------------------------------TopMenu VRState------------------------------------------

// Common
#define FC_VOICE_STATE_TOP_MENU_IDLE                                    QString("topmenu_idle")
#define FC_VOICE_STATE_TOP_MENU_MORE_HINTS                              QString("topmenu_more_hints")
// EU
#define FC_VOICE_STATE_EU_TOP_MENU_IDLE                                 QString("eu_topmenu_idle")
#define FC_VOICE_STATE_EU_TOP_MENU_HELP                                 QString("eu_topmenu_help")
// NA
#define FC_VOICE_STATE_NA_TOP_MENU_IDLE                                 QString("na_topmenu_idle")
#define FC_VOICE_STATE_NA_TOP_MENU_MORE_HINTS                           QString("na_topmenu_more_hints")

// ------------------------------Navi VRState ------------------------------------------
// Common
#define FC_VOICE_STATE_NAVI_IDLE                                        QString("navi_idle")
#define FC_VOICE_STATE_NAVI_MORE_HINTS                                  QString("navi_more_hints")
#define FC_VOICE_STATE_NAVI_SPEAK_ENTRUES_ADDRESS                       QString("navi_speak_entries_address")
#define FC_VOICE_STATE_NAVI_SPEAK_CITY                                  QString("navi_speak_city")
#define FC_VOICE_STATE_NAVI_SPEAK_HOUSE_NUMBER                          QString("navi_speak_house_number")
#define FC_VOICE_STATE_NAVI_SPEAK_STATE                                 QString("navi_speak_state")
#define FC_VOICE_STATE_NAVI_SPEAK_STREET                                QString("navi_speak_street")
#define FC_VOICE_STATE_NAVI_ADDRESS_CONFIRM                             QString("navi_address_confirm")
#define FC_VOICE_STATE_NAVI_ADDRESS_STREET_SELECT                       QString("navi_address_street_select")
#define FC_VOICE_STATE_NAVI_ADDRESS_DISTRICT_SELECT                     QString("navi_address_district_select")
#define FC_VOICE_STATE_NAVI_ADDRESS_HOUSE_SELECT                        QString("navi_address_house_select")
#define FC_VOICE_STATE_NAVI_ADDRESS_CITY_SELECT                         QString("navi_address_city_select")
#define FC_VOICE_STATE_NAVI_ADDRESS_STATE_SELECT                        QString("navi_address_state_select")
#define FC_VOICE_STATE_NAVI_ADDRESS_RESULT_SELECT                       QString("navi_address_result_select")
#define FC_VOICE_STATE_NAVI_SPEAK_POI                                   QString("navi_speak_poi")
#define FC_VOICE_STATE_NAVI_POI_LIST_SELECT                             QString("navi_poi_list_select")
#define FC_VOICE_STATE_NAVI_POI_ALONG_ROUTE_SELECT                      QString("navi_poi_along_route_select")
#define FC_VOICE_STATE_NAVI_POI_NEAR_DEST_SELECT                        QString("navi_poi_near_dest_select")
#define FC_VOICE_STATE_NAVI_POI_CONFIRM                                 QString("navi_poi_confirm")
#define FC_VOICE_STATE_NAVI_CONFIRM_DESTINATION                         QString("navi_confirm_destination")
#define FC_VOICE_STATE_NAVI_CONFIRM_ASSIST                              QString("navi_confirm_assist")
#define FC_VOICE_STATE_NAVI_DESTINATION_SELECT                          QString("navi_destination_select")
#define FC_VOICE_STATE_NAVI_CONFIRM_DELETE_DESTINATION                  QString("navi_confirm_delete_destination")
#define FC_VOICE_STATE_NAVI_DESTINATION_DELETE_SELECT                   QString("navi_destination_delete_select")
#define FC_VOICE_STATE_NAVI_SET_ROUTE                                   QString("navi_set_route")
#define FC_VOICE_STATE_NAVI_SET_ROUTE_CONFIRM                           QString("navi_set_route_confirm")
#define FC_VOICE_STATE_NAVI_POI_CATEGORY_CANDIDATES                     QString("navi_poi_category_candidates")
#define FC_VOICE_STATE_NAVI_POI_SHOW_CANDIDATES                         QString("navi_poi_show_candidates")
#define FC_VOICE_STATE_NAVI_POI_HIDE_CANDIDATES                         QString("navi_poi_hide_candidates")

// China
#define FC_VOICE_STATE_CN_NAVI_SPEAK_POI                                QString("cn_navi_speak_poi")
#define FC_VOICE_STATE_CN_NAVI_SPEAK_CITY                               QString("cn_navi_speak_city")
#define FC_VOICE_STATE_CN_NAVI_SPEAK_DISTRICT                           QString("cn_navi_speak_district")
#define FC_VOICE_STATE_CN_NAVI_SPEAK_HOUSE_NUMBER                       QString("cn_navi_speak_house_number")
#define FC_VOICE_STATE_CN_NAVI_SPEAK_STREET                             QString("cn_navi_speak_street")

#define FC_VOICE_STATE_CN_NAVI_POI_CATEGORY_WEBSEARCH_START                QString("cn_navi_poi_category_websearch_start")
#define FC_VOICE_STATE_CN_NAVI_POI_CATEGORY_RESULT_SELECT                  QString("cn_navi_poi_category_result_select")
#define FC_VOICE_STATE_CN_NAVI_POI_CATEGORY_RESULT_WEB_SELECT              QString("cn_navi_poi_category_result_web_select")
#define FC_VOICE_STATE_CN_NAVI_POI_CATEGORY_RESULT_LOCAL_SELECT            QString("cn_navi_poi_category_result_local_select")
#define FC_VOICE_STATE_CN_NAVI_POI_CATEGORY_RESULT_ALONG_ROUTE_SELECT      QString("cn_navi_poi_category_result_along_route_select")
#define FC_VOICE_STATE_CN_NAVI_POI_CATEGORY_RESULT_NEAR_DEST_SELECT        QString("cn_navi_poi_category_result_near_dest_select")
#define FC_VOICE_STATE_CN_NAVI_POI_NAME_RESULT_SELECT                      QString("cn_navi_poi_name_result_select")
#define FC_VOICE_STATE_CN_NAVI_POI_NAME_WEB_SEARCH_START                   QString("cn_navi_poi_name_web_search_start")
#define FC_VOICE_STATE_CN_NAVI_POI_NAME_RESULT_LOCAL_SELECT                QString("cn_navi_poi_name_result_local_select")
#define FC_VOICE_STATE_CN_NAVI_POI_NAME_RESULT_WEB_SELECT                  QString("cn_navi_poi_name_result_web_select")
#define FC_VOICE_STATE_CN_NAVI_POI_NAME_RESULT_INCITY_SELECT               QString("cn_navi_poi_name_result_incity_select")
#define FC_VOICE_STATE_CN_NAVI_POI_CATEGORY_RESULT_INCITY_SELECT           QString("cn_navi_poi_category_result_incity_select")
#define FC_VOICE_STATE_NAVI_CONFIRM_CALL_ASSIST                            QString("navi_confirm_call_assist")

// ------------------------------Phone VRState(content tag value) ------------------------------------------
// Common
#define FC_VOICE_STATE_PHONE_IDLE                                       QString("phone_idle")
#define FC_VOICE_STATE_PHONE_MORE_HINTS                                 QString("phone_more_hints")
#define FC_VOICE_STATE_PHONE_SPEAK_PHONE_NUMBER                         QString("phone_speak_phone_number")
#define FC_VOICE_STATE_PHONE_SPEAK_DIGITS                               QString("phone_speak_digits")
#define FC_VOICE_STATE_PHONE_CONFIRM_CALL_NUMBER                        QString("phone_confirm_call_number")
#define FC_VOICE_STATE_PHONE_SPEAK_CONTACT                              QString("phone_speak_contact")
#define FC_VOICE_STATE_PHONE_CONTACT_SELECT                             QString("phone_contact_select")
#define FC_VOICE_STATE_PHONE_CONFIRM_CALL_CONTACT                       QString("phone_confirm_call_contact")
#define FC_VOICE_STATE_PHONE_TYPE_SELECT                                QString("phone_contact_type_select")
#define FC_VOICE_STATE_PHONE_CONFIRM_CALLBACK_NUMBER                    QString("phone_confirm_callback_number")
#define FC_VOICE_STATE_PHONE_CONFIRM_CALLBACK_CONTACT                   QString("phone_confirm_callback_contact")
#define FC_VOICE_STATE_PHONE_CONFIRM_REDIAL_NUMBER                      QString("phone_confirm_redial_number")
#define FC_VOICE_STATE_PHONE_CONFIRM_REDIAL_CONTACT                     QString("phone_confirm_redial_contact")
// EU
#define FC_VOICE_STATE_EU_PHONE_NUMBER_SPEAK                               QString("eu_phone_number_speak")
#define FC_VOICE_STATE_EU_PHONE_DIGITS_SPEAK                               QString("eu_phone_digits_speak")
#define FC_VOICE_STATE_EU_PHONE_ANYSPEECH_SPEEK                            QString("eu_phone_anyspeech_speak")
#define FC_VOICE_STATE_EU_PHONE_ENTRY_SPEAK                                QString("eu_phone_entry_speak")
#define FC_VOICE_STATE_EU_PHONE_NAME_SELECT                                QString("eu_phone_name_select")
#define FC_VOICE_STATE_EU_PHONE_CATEGORY_SELECT                            QString("eu_phone_category_select")
#define FC_VOICE_STATE_EU_PHONE_CONTACT_SELECT                             QString("eu_phone_contact_select")
#define FC_VOICE_STATE_EU_PHONE_HELP_LIST                                  QString("eu_phone_help_list")
// NA
#define FC_VOICE_STATE_NA_PHONE_IDLE                                       QString("na_phone_idle")
#define FC_VOICE_STATE_NA_PHONE_IN_CALL                                    QString("na_phone_in_call")
#define FC_VOICE_STATE_NA_PHONE_IN_MESSAGE                                 QString("na_phone_in_message")
#define FC_VOICE_STATE_NA_PHONE_MORE_HINTS                                 QString("na_phone_more_hints")
#define FC_VOICE_STATE_NA_PHONE_CONTACT_SELECT_NAME                        QString("na_phone_contact_select_name")
#define FC_VOICE_STATE_NA_PHONE_CONTACT_SELECT_NUMBER                      QString("na_phone_contact_select_number")
#define FC_VOICE_STATE_NA_PHONE_CONTACT_SELECT_DIGITS                      QString("na_phone_contact_select_digits")
#define FC_VOICE_STATE_NA_PHONE_SPEAK_PHONE_NUMBER                         QString("na_phone_speak_phone_number")
#define FC_VOICE_STATE_NA_PHONE_SPEAK_DIGITS                               QString("na_phone_speak_digits")
#define FC_VOICE_STATE_NA_PHONE_CONFIRM_CALL_NUMBER                        QString("na_phone_confirm_call_number")
#define FC_VOICE_STATE_NA_PHONE_SPEAK_CONTACT                              QString("na_phone_speak_contact")
#define FC_VOICE_STATE_NA_PHONE_CONFIRM_CALL_CONTACT                       QString("na_phone_confirm_call_contact")
#define FC_VOICE_STATE_NA_PHONE_CONTACT_TYPE_SELECT                        QString("na_phone_contact_type_select")
#define FC_VOICE_STATE_NA_PHONE_SELECT_NAME_MATCHES_CALL_SMS               QString("na_phone_select_name_matches_call_sms")
#define FC_VOICE_STATE_NA_PHONE_CONFIRM_REPLY_SEND_MSG                     QString("na_phone_confirm_reply_send_msg")
#define FC_VOICE_STATE_NA_PHONE_SEARCH_CONTACTS_SMS                        QString("na_phone_search_contacts_sms")
#define FC_VOICE_STATE_NA_PHONE_CONFIRM_SMS_RECIPIENT                      QString("na_phone_confirm_sms_recipient")
#define FC_VOICE_STATE_NA_PHONE_CALL_SPEAK_NAME_NUMBER                     QString("na_phone_call_speak_name_number")
#define FC_VOICE_STATE_NA_PHONE_DICTATE_SMS                                QString("na_phone_dictate_sms")
#define FC_VOICE_STATE_NA_PHONE_LIST_RECENT_CALLS                          QString("na_phone_list_recent_calls")
#define FC_VOICE_STATE_NA_PHONE_LIST_MESSAGES                              QString("na_phone_list_messages")
#define FC_VOICE_STATE_NA_PHONE_SELECT_QUICK_REPLY                         QString("na_phone_select_quick_reply")
#define FC_VOICE_STATE_NA_PHONE_ONE_CALL_CONTACT_MESSAGE_SELECTED          QString("na_phone_one_call_contact_message_selected")
#define FC_VOICE_STATE_NA_PHONE_ONE_MESSAGE_SELECTED                       QString("na_phone_one_message_selected")
#define FC_VOICE_STATE_NA_PHONE_SELECT_NAME_AND_TYPE_MATCHES_CALL_SMS      QString("na_phone_select_name_and_type_matches_call_sms")
#define FC_VOICE_STATE_NA_PHONE_SEND_DTMF                                  QString("na_phone_send_dtmf")

// ------------------------------Media VRState(content tag value) ------------------------------------------
// Common
#define FC_VOICE_STATE_MEDIA_IDLE                                          QString("media_idle")
#define FC_VOICE_STATE_MEDIA_MORE_HINTS                                    QString("media_more_hints")
#define FC_VOICE_STATE_MEDIA_MUSIC_SPEAK_ARTIST_NAME                       QString("media_music_speak_artist_name")
#define FC_VOICE_STATE_MEDIA_MUSIC_ARTIST_SELECT                           QString("media_music_artist_select")
#define FC_VOICE_STATE_MEDIA_MUSIC_SPEAK_ALBUM_NAME                        QString("media_music_speak_album_name")
#define FC_VOICE_STATE_MEDIA_MUSIC_ALBUM_SELECT                            QString("media_music_album_select")
#define FC_VOICE_STATE_MEDIA_MUSIC_SPEAK_SONG_NAME                         QString("media_music_speak_song_name")
#define FC_VOICE_STATE_MEDIA_MUSIC_SONG_SELECT                             QString("media_music_song_select")
#define FC_VOICE_STATE_MEDIA_MUSIC_PLAY_LIST_SELECT                        QString("media_music_play_list_select")
#define FC_VOICE_STATE_MEDIA_MUSIC_SELECT_SONG_FROM_PLAYLIST               QString("media_music_select_song_from_playlist")
#define FC_VOICE_STATE_MEDIA_RADIO_SPEAK_RADIO_FREQUENCY                   QString("media_radio_speak_radio_frequency")
#define FC_VOICE_STATE_MEDIA_RADIO_SPEAK_PRESET_NUMBER                     QString("media_radio_speak_preset_number")
// EU
#define FC_VOICE_STATE_EU_MEDIA_GENRE_NAME_SPEAK                              QString("eu_media_genre_name_speak")
#define FC_VOICE_STATE_EU_MEDIA_GENRE_NAME_SELECT                             QString("eu_media_genre_name_select")
#define FC_VOICE_STATE_EU_MEDIA_GENRE_CANDIDATE_SELECT                        QString("eu_media_genre_candidate_select")
#define FC_VOICE_STATE_EU_MEDIA_ARTIST_NAME_SPEAK                             QString("eu_media_artist_name_speak")
#define FC_VOICE_STATE_EU_MEDIA_ARTIST_NAME_SELECT                            QString("eu_media_artist_name_select")
#define FC_VOICE_STATE_EU_MEDIA_ARTIST_CANDIDATE_SELECT                       QString("eu_media_artist_candidate_select")
#define FC_VOICE_STATE_EU_MEDIA_ALBUM_NAME_SPEAK                              QString("eu_media_album_name_speak")
#define FC_VOICE_STATE_EU_MEDIA_ALBUM_NAME_SELECT                             QString("eu_media_album_name_select")
#define FC_VOICE_STATE_EU_MEDIA_ALBUM_CANDIDATE_SELECT                        QString("eu_media_album_candidate_select")
#define FC_VOICE_STATE_EU_MEDIA_TITLE_NAME_SPEAK                              QString("eu_media_title_name_speak")
#define FC_VOICE_STATE_EU_MEDIA_TITLE_NAME_SELECT                             QString("eu_media_title_name_select")
#define FC_VOICE_STATE_EU_MEDIA_TITLE_MUSIC_SELECT                            QString("eu_media_title_music_select")
#define FC_VOICE_STATE_EU_MEDIA_PLAYLIST_NAME_SPEAK                           QString("eu_media_playlist_name_speak")
#define FC_VOICE_STATE_EU_MEDIA_PLAYLIST_NAME_SELECT                          QString("eu_media_playlist_name_select")
#define FC_VOICE_STATE_EU_MEDIA_PLAYLIST_MUSIC_SELECT                         QString("eu_media_playlist_music_select")
#define FC_VOICE_STATE_EU_MEDIA_ONESHOT_NAME_SPEAK                            QString("eu_media_oneshot_name_speak")
#define FC_VOICE_STATE_EU_MEDIA_ONESHOT_ARTIST_SELECT                         QString("eu_media_oneshot_artist_select")
#define FC_VOICE_STATE_EU_MEDIA_ONESHOT_MUSIC_SELECT                          QString("eu_media_oneshot_music_select")
#define FC_VOICE_STATE_EU_MEDIA_HELP_LIST                                     QString("eu_media_help_list")
// NA
#define FC_VOICE_STATE_NA_MEDIA_IDLE                                          QString("na_media_idle")
#define FC_VOICE_STATE_NA_MEDIA_MORE_HINTS                                    QString("na_media_more_hints")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_SPEAK_ARTIST_NAME                       QString("na_media_music_speak_artist_name")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_SPEAK_ALBUM_NAME                        QString("na_media_music_speak_album_name")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_SPEAK_SONG_NAME                         QString("na_media_music_speak_song_name")
#define FC_VOICE_STATE_NA_MEDIA_NBEST_SELECT                                  QString("na_media_music_nbest_select")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_PLAY_LIST_SELECT                        QString("na_media_music_play_list_select")
#define FC_VOICE_STATE_NA_MEDIA_RADIO_SPEAK_RADIO_FREQUENCY                   QString("na_media_radio_speak_radio_frequency")
#define FC_VOICE_STATE_NA_MEDIA_RADIO_SPEAK_PRESET_NUMBER                     QString("na_media_radio_speak_preset_number")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_WHICH_ARTIST_FOR_ALBUM                  QString("na_media_music_which_artist_for_album")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_WHICH_ARTIST_FOR_SONG                   QString("na_media_music_which_artist_for_song")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_SPEAK_A_CATEGORY                        QString("na_media_music_speak_a_category")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_WHICH_ALBUM_FOR_SONG                    QString("na_media_music_which_album_for_song")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_ALBUM_SONG_SELECT                       QString("na_media_music_album_song_select")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_ARTIST_ALBUM_SELECT                     QString("na_media_music_artist_album_select")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_ARTIST_SONG_SELECT                      QString("na_media_music_artist_song_select")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_SPEAK_AUDIOBOOKS_NAME                   QString("na_media_music_speak_audiobooks_name")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_SPEAK_COMPOSER_NAME                     QString("na_media_music_speak_composer_name")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_COMPOSER_SONG_SELECT                    QString("na_media_music_composer_song_select")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_SPEAK_GENRE_NAME                        QString("na_media_music_speak_genre_name")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_GENRE_ARTIST_SELECT                     QString("na_media_music_genre_artist_select")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_PLAY_LIST_SONG_SELECT                   QString("na_media_music_play_list_song_select")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_SPEAK_PODCASTNAME                       QString("na_media_music_speak_podcastname")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_SOURCE_SELECT                           QString("na_media_music_source_select")
#define FC_VOICE_STATE_NA_MEDIA_MUSIC_PODCAST_ITEM_SELECT                     QString("na_media_music_podcast_item_select")
#define FC_VOICE_STATE_NA_MEDIA_RADIO_GENRE_SELECT                            QString("na_media_radio_genre_select")
#define FC_VOICE_STATE_NA_MEDIA_RADIO_SATELLITE_CHANNEL_SELECT                QString("na_media_radio_satellite_channel_select")

// ------------------------------Apps VRState(content tag value) ------------------------------------------
// Common
#define FC_VOICE_STATE_APPS_IDLE                                QString("apps_idle")
#define FC_VOICE_STATE_APPS_MORE_HINTS                          QString("apps_more_hints")
#define FC_VOICE_STATE_APPS_APPS_LIST_SELECT                    QString("apps_apps_list_select")
#define FC_VOICE_STATE_APPS_APP_CANDIDATES_SELECT               QString("apps_app_candidates_select")
// NA
#define FC_VOICE_STATE_NA_APPS_IDLE                             QString("na_apps_idle")
#define FC_VOICE_STATE_NA_APPS_MORE_HINTS                       QString("na_apps_more_hints")
#define FC_VOICE_STATE_NA_APPS_APPS_LIST_SELECT                 QString("na_apps_apps_list_select")
#define FC_VOICE_STATE_NA_APPS_APP_CANDIDATES_SELECT            QString("na_apps_app_candidates_select")

// ------------------------------VoiceTag VRState(content tag value) ------------------------------------------
#define FC_VOICE_STATE_VOICETAG_IDLE                            QString("voicetag_idle")
#define FC_VOICE_STATE_VOICETAG_CONTACT_SELECT                  QString("voicetag_contact_select")
#define FC_VOICE_STATE_VOICETAG_DETAIL_SELECT                   QString("voicetag_detail_select")

#define FC_VOICE_STATE_VOICETAG_ERR_TAG_NONE                    QString("voicetag_err_tag_none")
#define FC_VOICE_STATE_VOICETAG_ERR_PHONE_NOT_REGISTER          QString("voicetag_err_phone_not_register")
#define FC_VOICE_STATE_VOICETAG_ERR_PHONE_NOT_CONNECTED         QString("voicetag_err_phone_not_connected")
#define FC_VOICE_STATE_VOICETAG_EXIT_IDLE                       QString("voicetag_exit_idle")
#define FC_VOICE_STATE_VOICETAG_EXIT_NAME                       QString("voicetag_exit_name")
#define FC_VOICE_STATE_VOICETAG_EXIT_TYPE                       QString("voicetag_exit_type")

// ------------------------------SendTones VRState(content tag value) ------------------------------------------
// Common
#define FC_VOICE_STATE_SENDTONE_SPEAK_TONES                     QString("sendtone_speak_tones")
#define FC_VOICE_STATE_SENDTONE_CONFIRM_TONES                   QString("sendtone_confirm_tones")

// ------------------------------Vehicle VRState(content tag value) ------------------------------------------
// Common
#define FC_VOICE_STATE_VEHICLE_IDLE                             QString("vehicle_idle")

// ------------------------------Help VRState(content tag value) ------------------------------------------
// NA
#define FC_VOICE_STATE_NA_HELP_TUTORIAL_CONFIRMATION            QString("na_help_tutorial_confirmation")
#define FC_VOICE_STATE_NA_HELP_TRAIN_VOICE_RECOGNITION          QString("na_help_train_voice_recognition")
#define FC_VOICE_STATE_INFORMATION_SELECT                       QString("information_select")
#define FC_VOICE_STATE_INFORMATION_IDLE                         QString("information_idle")
#define FC_VOICE_STATE_INFORMATION_MORE_HINTS                   QString("information_more_hints")
#define FC_VOICE_STATE_NA_HELP_MORE_HINTS                       QString("na_help_more_hints")

// ------------------------------Adaption VRState(content tag value) ------------------------------------------
// NA
#define FC_VOICE_STATE_NA_ADAPTION                                 QString("na_adaptation")

// ------------------------------Climate VRState(content tag value) ------------------------------------------
// Common
#define FC_VOICE_STATE_CLIMATE_IDLE                             QString("climate_idle")
#define FC_VOICE_STATE_CLIMATE_MORE_HINTS                       QString("climate_more_hints")
// NA
#define FC_VOICE_STATE_NA_CLIMATE_IDL                           QString("na_climate_idle")
#define FC_VOICE_STATE_NA_CLIMATE_IDLE                          QString("na_climate_idle")
#define FC_VOICE_STATE_NA_CLIMATE_MORE_HINTS                    QString("na_climate_more_hints")
#define FC_VOICE_STATE_NA_CLIMATE_SET_THE_TEMPERATURE           QString("na_climate_set_the_temperature")
#define FC_VOICE_STATE_NA_CLIMATE_SER_THE_FAN_SPEED             QString("na_climate_set_the_fan_speed")

// ------------------------------Dictation VRState(content tag value) ------------------------------------------
// NA
#define FC_VOICE_STATE_NA_DICTATION_CITIES_KEYBOARD             QString("na_dictation_cities_keyboard")
#define FC_VOICE_STATE_NA_DICTATION_GENERIC_KEYBOARD            QString("na_dictation_generic_keyboard")
#define FC_VOICE_STATE_NA_DICTATION_HFD_KEYBOARD                QString("na_dictation_hfd_keyboard")
#define FC_VOICE_STATE_NA_DICTATION_MESSAGE                     QString("na_dictation_message")
#define FC_VOICE_STATE_NA_DICTATION_MUSIC_KEYBOARD              QString("na_dictation_music_keyboard")
#define FC_VOICE_STATE_NA_DICTATION_NAVIGATION_KEYBOARD         QString("na_dictation_navigation_keyboard")
#define FC_VOICE_STATE_NA_DICTATION_POI_KEYBOARD                QString("na_dictation_poi_keyboard")
#define FC_VOICE_STATE_NA_DICTATION_STATES_KEYBOARD             QString("na_dictation_states_keyboard")
#define FC_VOICE_STATE_NA_DICTATION_STREETS_KEYBOARD            QString("na_dictation_streets_keyboard")

// ------------------------------Tuner VRState(content tag value) ------------------------------------------
// EU
#define FC_VOICE_STATE_EU_TUNER_STATION_NAME_INPUT              QString("eu_tuner_station_name_input")
#define FC_VOICE_STATE_EU_TUNER_STATION_NAME_SELECT             QString("eu_tuner_station_name_select")
#define FC_VOICE_STATE_EU_TUNER_STATION_SELECT                  QString("eu_tuner_station_select")
#define FC_VOICE_STATE_EU_TUNER_HELP_LIST                       QString("eu_tuner_help_list")

// -----------ASR State--------------------------------------------------
#define FC_VOICE_ASR_STATE_IDLE                                 QString("idle")
#define FC_VOICE_ASR_STATE_PROMPTPLAYING                        QString("promptPlaying")
#define FC_VOICE_ASR_STATE_LISTENINGFORBARGEIN                  QString("listeningForBargeIn")
#define FC_VOICE_ASR_STATE_LISTENING                            QString("listening")
#define FC_VOICE_ASR_STATE_RECOGNIZING                          QString("recognizing")
#define FC_VOICE_ASR_STATE_DONE                                 QString("done")
#define FC_VOICE_ASR_STATE_PROCESSING                           QString("processing")
#define FC_VOICE_ASR_STATE_FINISHED                             QString("finished")
#define FC_VOICE_ASR_STATE_PAUSED                               QString("paused")
#define FC_VOICE_ASR_STATE_RESUME                               QString("resume")
#define FC_VOICE_ASR_STATE_QUIT                                 QString("quit")
#define FC_VOICE_ASR_STATE_LOCAL                                QString("local")
#define FC_VOICE_ASR_STATE_SERVER                               QString("server")
#define FC_VOICE_ASR_STATE_SPEECHBEGIN                          QString("speechBegin")
#define FC_VOICE_ASR_STATE_READING                              QString("reading")
#define FC_VOICE_ASR_STATE_PROMPTWITHBARGEIN                    QString("promptWithBargein")
#define FC_VOICE_ASR_STATE_COMPLETE                             QString("complete")
#define FC_VOICE_ASR_STATE_ENDTASK_START                        QString("endtaskstart")
#define FC_VOICE_ASR_STATE_ENDTASK_FINISHED                     QString("endtaskfinished")

// ----------Volume value define ---------------------------------------------
#define FC_VOICE_VOLUME_VALUE_MIN                                   0
#define FC_VOICE_VOLUME_SUITABLE_VALUE_MIN                          10
#define FC_VOICE_VOLUME_SUITABLE_VALUE_MAX                          90
#define FC_VOICE_VOLUME_VALUE_MAX                                   100
#define FC_VOICE_VOLUME_TOOQUIET_STATUS                         QString("tooQuiet")
#define FC_VOICE_VOLUME_SUITABLE_STATUS                         QString("suitable")
#define FC_VOICE_VOLUME_TOOLOUD_STATUS                          QString("tooLoud")

// ---------PhoneType String define--------------------------------------------
#define FC_VOICE_PHONE_TYPE_MOBILE_STRING                       "0"
#define FC_VOICE_PHONE_TYPE_HOME_STRING                         "1"
#define FC_VOICE_PHONE_TYPE_WORK_STRING                         "2"
#define FC_VOICE_PHONE_TYPE_OTHER_STRING                        "3"

#define FC_VOICE_PHONE_TYPE_MOBILE1_STRING                      "4"
#define FC_VOICE_PHONE_TYPE_MOBILE2_STRING                      "8"
#define FC_VOICE_PHONE_TYPE_MOBILE3_STRING                      "12"
#define FC_VOICE_PHONE_TYPE_MOBILE4_STRING                      "16"
#define FC_VOICE_PHONE_TYPE_HOME1_STRING                        "5"
#define FC_VOICE_PHONE_TYPE_HOME2_STRING                        "9"
#define FC_VOICE_PHONE_TYPE_HOME3_STRING                        "13"
#define FC_VOICE_PHONE_TYPE_HOME4_STRING                        "17"
#define FC_VOICE_PHONE_TYPE_WORK1_STRING                        "6"
#define FC_VOICE_PHONE_TYPE_WORK2_STRING                        "10"
#define FC_VOICE_PHONE_TYPE_WORK3_STRING                        "14"
#define FC_VOICE_PHONE_TYPE_WORK4_STRING                        "18"
#define FC_VOICE_PHONE_TYPE_OTHER1_STRING                       "7"
#define FC_VOICE_PHONE_TYPE_OTHER2_STRING                       "11"
#define FC_VOICE_PHONE_TYPE_OTHER3_STRING                       "15"
#define FC_VOICE_PHONE_TYPE_OTHER4_STRING                       "19"
#define FC_VOICE_PHONE_TYPE_CALLIN_STRING                       "1"
#define FC_VOICE_PHONE_TYPE_CALLOUT_STRING                      "0"
#define FC_VOICE_PHONE_TYPE_MISSED_CALL_STRING                  "2"
#define FC_VOICE_PHONE_TYPE_CALLIN_REJECT_STRING                ""
#define FC_VOICE_PHONE_CONTACT_REGISTER_STRING                    ""
#define FC_VOICE_PHONE_CONTACT_UNREGISTER_STRING                ""
#define FC_VOICE_PHONE_NONOTIFY_CALLIN_STRING                   ""

#define FC_VOICE_ICON_STATUS_SPEAKING_STRING                    ""
#define FC_VOICE_ICON_STATUS_LISTENING_STRING                   ""
#define FC_VOICE_ICON_STATUS_THINKING_STRING                    ""
#define FC_VOICE_ICON_STATUS_LOADING_STRING                     ""

#define FC_VOICE_LIST_TYPE_MEDIA_STRING                         ""
#define FC_VOICE_LIST_TYPE_PHONE_STRING                         ""
#define FC_VOICE_LIST_TYPE_TUNER_STRING                         ""

#define FC_VOICE_VEHICLE_TYPE_RUNNING_STRING                    ""
#define FC_VOICE_PHONE_CALL_ASSIST_STRING                       ""

#define FC_VOICE_PHONE_TYPE_CANDIDATA1_MOBILE1_STRING                      ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_MOBILE2_STRING                      ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_MOBILE3_STRING                      ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_MOBILE4_STRING                      ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_HOME1_STRING                        ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_HOME2_STRING                        ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_HOME3_STRING                        ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_HOME4_STRING                        ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_WORK1_STRING                        ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_WORK2_STRING                        ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_WORK3_STRING                        ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_WORK4_STRING                        ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_OTHER1_STRING                       ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_OTHER2_STRING                       ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_OTHER3_STRING                       ""
#define FC_VOICE_PHONE_TYPE_CANDIDATA1_OTHER4_STRING                       ""

// ----------tag key of action define ---------------------------------------------
#define FC_VOICE_ACTION_TYPE                                        QString("actionType")
// music
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_BY_ALBUM                   QString("playByMusicAlbum")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_BY_ALL                     QString("playByMusicAll")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_BY_ATRIST                  QString("playByMusicArtist")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_BY_AUDIO_BOOK              QString("playByMusicAudioBook")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_BY_COMPOSER                QString("playByMusicComposer")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE                   QString("playByMusicGenre")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_BY_PLAYLIST                QString("playByMusicPlaylist")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_BY_PODCAST                 QString("playByMusicPodcast")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_BY_PODCAST_ITEM            QString("playByMusicPodcastItem")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_BY_SONG                    QString("playByMusicSong")
#define FC_VOICE_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ALBUM           QString("shufflePlayByMusicAlbum")
#define FC_VOICE_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ARTIST          QString("shufflePlayByMusicArtist")
#define FC_VOICE_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_COMPOSER        QString("shufflePlayByMusicComposer")
#define FC_VOICE_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ALL             QString("shufflePlayByMusicAll")
#define FC_VOICE_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_PLAYLIST        QString("shufflePlayByMusicPlaylist")

#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_ARTIST_ALBUM      QString("playByGenreArtistAndAlbum")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_ARTIST            QString("playByGenreAndArtist")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_BY_ATRIST_ALBUM            QString("playByArtistAndAlbum")

#define FC_VOICE_ACTION_MEDIA_MUSIC_CHANGE_SOURCE                   QString("changeSource")
#define FC_VOICE_ACTION_MEDIA_MUSIC_AUDIO_OFF                       QString("turnAudioOff")
#define FC_VOICE_ACTION_MEDIA_MUSIC_AUDIO_ON                        QString("turnAudioOn")

#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_PODCAST_BY_EPISODE         QString("playPodcastEpisode")
#define FC_VOICE_ACTION_MEDIA_MUSIC_CHANGE_SOURCE_BY_NAME           QString("changeSourceByName")

#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_ALL_ARTIST                         QString("PlayAllArtist")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM                          QString("PlayAllAlbum")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_ALL_ARTIST_BY_GENRE                QString("playAllArtistByGenre")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_BY_ARTIST                QString("PlayAllAlbumByArtist")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_BY_GENRE_ARTIST          QString("PlayAllAlbumByGenreArtist")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM                          QString("PlayTheAlbum")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_BY_ARTIST                QString("PlayTheAlbumByArtist")
#define FC_VOICE_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_BY_GENRE_ARTIST          QString("PlayTheAlbumByGenreArtist")

#define FC_VOICE_ACTION_MEDIA_MUSIC_SHOW_GENRE                              QString("ShowGenreScreen")
#define FC_VOICE_ACTION_MEDIA_MUSIC_SHOW_SONG                               QString("ShowSongScreen")
#define FC_VOICE_ACTION_MEDIA_MUSIC_SHOW_PLAYLIST                           QString("ShowPlaylistScreen")
#define FC_VOICE_ACTION_MEDIA_MUSIC_SHOW_ARTIST                             QString("ShowArtistScreen")
#define FC_VOICE_ACTION_MEDIA_MUSIC_SHOW_ARTIST_BY_GENRE                    QString("ShowArtistScreenByGenre")
#define FC_VOICE_ACTION_MEDIA_MUSIC_SHOW_ALBUM                              QString("ShowAlbumScreen")
#define FC_VOICE_ACTION_MEDIA_MUSIC_SHOW_ALBUM_BY_ARTIST                    QString("ShowAlbumScreenByArtist")
#define FC_VOICE_ACTION_MEDIA_MUSIC_SHOW_ALBUM_BY_GENRE_ARTIST              QString("ShowAlbumScreenByGenreArtist")

// radio
#define FC_VOICE_ACTION_MEDIA_RADIO_CHANGE_HD_SUB_CHANNEL           QString("changeHDSubChannel")
#define FC_VOICE_ACTION_MEDIA_RADIO_TUNE_FREQUENCY                  QString("tuneFrequency")
#define FC_VOICE_ACTION_MEDIA_RADIO_TUNE_FM_HD_FREQUENCY            QString("tuneFMHDFrequency")
#define FC_VOICE_ACTION_MEDIA_RADIO_TUNE_LAST_SATELLITE             QString("tuneLastSatellite")
#define FC_VOICE_ACTION_MEDIA_RADIO_TUNE_SATELLITE_CHANNEL_NUMBER   QString("tuneSatelliteChannelNumber")
#define FC_VOICE_ACTION_MEDIA_RADIO_TUNE_LAST_AM                    QString("tuneLastAM")
#define FC_VOICE_ACTION_MEDIA_RADIO_TUNE_LAST_FM                    QString("tuneLastFM")
#define FC_VOICE_ACTION_MEDIA_RADIO_TUNE_FM_GENRE                   QString("tuneFMGenre")
#define FC_VOICE_ACTION_MEDIA_RADIO_TUNE_XM_CATEGORY                QString("tuneXMCategory")
#define FC_VOICE_ACTION_MEDIA_RADIO_TUNE_DAB_CHANNEL                QString("tuneDABChannel")
#define FC_VOICE_ACTION_MEDIA_RADIO_TUNE_FM_CHANNEL                 QString("tuneFMChannel")
#define FC_VOICE_ACTION_MEDIA_RADIO_TUNE_SATELLITE_CHANNEL          QString("tuneSatelliteChannel")
#define FC_VOICE_ACTION_MEDIA_RADIO_TUNE_MIX_RADIO_PRESET           QString("tuneMixRadioPreset")
#define FC_VOICE_ACTION_MEDIA_RADIO_TUNE_RADIO_PRESET               QString("tuneRadioPreset")

// hvac
#define FC_VOICE_ACTION_HVAC_SHOW_FRONT_SCREEN                      QString("showHvacFrontScreen")
#define FC_VOICE_ACTION_HVAC_SHOW_REAR_SCREEN                       QString("showHvacRearScreen")
#define FC_VOICE_ACTION_HVAC_SHOW_STEERING_SCREEN                   QString("showHvacSteeringScreen")
#define FC_VOICE_ACTION_HVAC_SHOW_FRONT_SEAT_SCREEN                 QString("showFrontSeatScreen")
#define FC_VOICE_ACTION_HVAC_SHOW_REAR_SEAT_SCREEN                  QString("showRearSeatScreen")
#define FC_VOICE_ACTION_HVAC_SHOW_LEXUS_CONCIERGE_SCREEN            QString("showLexusConciergeScreen")
#define FC_VOICE_ACTION_HVAC_SEAT_OPERATION_SCREEN                  QString("showSeatOperationScreen")
#define FC_VOICE_ACTION_HVAC_FRONT_SEAT_VEN_SCREEN                  QString("showFrontSeatVentiScreen")
#define FC_VOICE_ACTION_HVAC_REAR_SEAT_VEN_SCREEN                   QString("showRearSeatVentiScreen")
#define FC_VOICE_ACTION_HVAC_FRONT_AC_SCREEN                        QString("showFrontACScreen")
#define FC_VOICE_ACTION_HVAC_REAR_AC_SCREEN                         QString("showRearACScreen")
#define FC_VOCIE_ACTION_HVAC_SEAT_SCREEN                            QString("showHvacSeatScreen")

// HFD
#define FC_VOICE_ACTION_PHONE_DIAL_CALL                                QString("dial")
#define FC_VOICE_ACTION_PHONE_DIAL_CALL_NUM                            QString("dial")
#define FC_VOICE_ACTION_PHONE_DIAL_CALL_RECENT                         QString("dial")
#define FC_VOICE_ACTION_PHONE_DIAL_Call_SHORTRING                      QString("dial")
#define FC_VOICE_ACTION_PHONE_DIAL_REDIAL                              QString("dial")
#define FC_VOICE_ACTION_PHONE_SHOW_RECENT_CALL_LIST                    QString("showRecentCallList")
#define FC_VOICE_ACTION_PHONE_SEND_DTMF_TONES                          QString("sendDTMFTones")
#define FC_VOICE_ACTION_PHONE_SHOW_CONTACT_LIST                        QString("showContactList")
#define FC_VOICE_ACTION_PHONE_SHOW_FAVORITE_CONTACT_LIST               QString("showFavoriteContactList")
#define FC_VOICE_ACTION_PHONE_SEND_MESSAGE                             QString("sendMessage")
#define FC_VOICE_ACTION_PHONE_MUTE_CALL                                QString("muteCall")
#define FC_VOICE_ACTION_PHONE_MUTE_OFF                                 QString("muteOff")
#define FC_VOICE_ACTION_PHONE_ADD_VOICE_TAG                            QString("showAddVoiceTagUI")
#define FC_VOICE_ACTION_PHONE_GET_MESSAGE_DEATIL                       QString("getMessageDetail")
#define FC_VOICE_ACTION_PHONE_GET_MESSAGE_STATE                        QString("getMessageState")

// Navi
#define FC_VOICE_ACTION_NAVI_SHOW_POI_ICON_TAG                             QString("showPOIIcon")
#define FC_VOICE_ACTION_NAVI_HIDE_POI_ICON_TAG                             QString("hidePOIIcon")
#define FC_VOICE_ACTION_NAVI_CACULATEROUTE_TAG                             QString("calculateRoute")
#define FC_VOICE_ACTION_NAVI_DELETE_DESTINATION_TAG                        QString("deleteDestination")
#define FC_VOICE_ACTION_NAVI_SHOW_POI_ICON_NUMBER_TAG                      QString("queryShowingPOIIconNumber")
#define FC_VOICE_ACTION_NAVI_ADD_TO_ROUTE_TAG                              QString("addToRoute")
#define FC_VOICE_ACTION_SHOW_DESTINATION_ASSIST                            QString("callDestinationAssist")

// apps
#define FC_VOICE_ACTION_APPS_LAUNCH                                    QString("launchApp")

// help op
#define FC_VOICE_ACTION_HELP_SHOW_VOICE_SETTINGS_UI             QString("showVoiceSettingsUI")
#define FC_VOICE_ACTION_HELP_SHOW_LEXUS_INSIDER_UI              QString("showLexusInsiderUI")
#define FC_VOICE_ACTION_HELP_SHOW_TUTORIALS_UI                  QString("showTutorialsUI")
#define FC_VOICE_ACTION_HELP_TRAINING_END_MSG                   QString("showTrainingEndMsg")

// weather op
#define FC_VOICE_ACTION_INFO_SHOW_CURRENT_WEATHER               QString("showCurrentWeather")
#define FC_VOICE_ACTION_INFO_SHOW_NATIONAL_WEATHER              QString("showNationalWeather")

// ----------tag key of action define ---------------------------------------------
#define FC_VOICE_ACTION_TAG_KEY_SUB_CHANNEL_NUM                 QString("subchannelNum")
#define FC_VOICE_ACTION_TAG_KEY_BAND                            QString("band")
#define FC_VOICE_ACTION_TAG_KEY_FREQUENCY                       QString("frequency")
#define FC_VOICE_ACTION_TAG_KEY_GENRE                           QString("genre")
#define FC_VOICE_ACTION_TAG_KEY_ID                              QString("id")
#define FC_VOICE_ACTION_TAG_KEY_NAME                            QString("name")
#define FC_VOICE_ACTION_TAG_KEY_NUMBER                          QString("number")
#define FC_VOICE_ACTION_TAG_KEY_PLAY_TYPE                       QString("playType")
#define FC_VOICE_ACTION_TAG_KEY_LIST_NO                         QString("listNo")

#define FC_VOICE_ACTION_TAG_KEY_SOURCE_ID                       QString("sourceid")
#define FC_VOICE_ACTION_TAG_KEY_SOURCE_NAME                     QString("sourceName")
#define FC_VOICE_ACTION_TAG_KEY_GENRE_ID                        QString("genreid")
#define FC_VOICE_ACTION_TAG_KEY_ARTIST_ID                       QString("artistid")
#define FC_VOICE_ACTION_TAG_KEY_ALBUM_ID                        QString("albumid")
#define FC_VOICE_ACTION_TAG_KEY_COMPOSER_ID                     QString("composerid")
#define FC_VOICE_ACTION_TAG_KEY_PODCAST_ID                      QString("podcastid")
#define FC_VOICE_ACTION_TAG_KEY_PODCAST_NAME                    QString("podcastName")
#define FC_VOICE_ACTION_TAG_KEY_EPISODE_ID                      QString("episodeid")
#define FC_VOICE_ACTION_TAG_KEY_EPISODE_NAME                    QString("episodeName")
#define FC_VOICE_ACTION_TAG_KEY_PLAYLIST_ID                     QString("playlistid")
#define FC_VOICE_ACTION_TAG_KEY_SONGD_ID                        QString("songid")
#define FC_VOICE_ACTION_TAG_KEY_AUDIO_BOOK_ID                   QString("audiobookid")

#define FC_VOICE_ACTION_TAG_KEY_CONTACT_ID                      QString("contactId")
#define FC_VOICE_ACTION_TAG_KEY_CONTACT_NAME                    QString("contactName")
#define FC_VOICE_ACTION_TAG_KEY_PHONE_TYPE                      QString("phoneType")
#define FC_VOICE_ACTION_TAG_KEY_LIST_TYPE                       QString("listType")
#define FC_VOICE_ACTION_TAG_KEY_MESSAGE_INFO                    QString("messageInfo")
#define FC_VOICE_ACTION_TAG_KEY_INSTANCE_ID                     QString("instanceId")
#define FC_VOICE_ACTION_TAG_KEY_MESSAGE_ID                      QString("messageId")
#define FC_VOICE_ACTION_TAG_KEY_TONES                           QString("tones")
#define FC_VOICE_ACTION_TAG_KEY_MESSAGE_BODY                    QString("messageBody")
#define FC_VOICE_ACTION_TAG_KEY_MESSAGE_TYPE                    QString("messageType")
#define FC_VOICE_ACTION_TAG_KEY_PHONE_TYPE_ID                   QString("phoneTypeId")
#define FC_VOICE_ACTION_TAG_KEY_TIMES_TAMP                      QString("timesTamp")
#define FC_VOICE_ACTION_TAG_KEY_STATUS                          QString("status")

#define FC_VOICE_ACTION_CATEGORY_ID                             QString("categoryId")
#define FC_VOICE_ACTION_SET_FLAG                                QString("setFlag")
#define FC_VOICE_ACTION_CALCULATE_TYPE                          QString("calculateType")
#define FC_VOICE_ACTION_CALCULATE_TYPE_REROUTE                  QString("REROUTE")
#define FC_VOICE_ACTION_CALCULATE_TYPE_ADD_TO_ROUTE             QString("ADD_TO_ROUTE")
#define FC_VOICE_ACTION_DROP_POINT_ID                           QString("dropPointId")
#define FC_VOICE_ACTION_LONGITUDE                               QString("longitude")
#define FC_VOICE_ACTION_LATITUDE                                QString("latitude")
#define FC_VOICE_ACTION_POI_ID                                  QString("poiId")
#define FC_VOICE_ACTION_AREA_ID                                 QString("areaId")
#define FC_VOICE_ACTION_GUIDE_LONGITUDE                         QString("guideLongitude")
#define FC_VOICE_ACTION_GUIDE_LATITUDE                          QString("guideLatitude")
#define FC_VOICE_ACTION_GUIDE_LINKID                            QString("guideLinkId")
#define FC_VOICE_ACTION_DISPLAY_GUIDE_TYPE                      QString("displayGuideType")
#define FC_VOICE_ACTION_COUNTRY_NAME                            QString("country_name")
#define FC_VOICE_ACTION_PROVINCE_NAME                           QString("province_name")
#define FC_VOICE_ACTION_CITY_NAME                               QString("city_name")
#define FC_VOICE_ACTION_COUNTY_NAME                             QString("county_name")
#define FC_VOICE_ACTION_TOWNSHIP_NAME                           QString("township_name")
#define FC_VOICE_ACTION_ROAD_NAME                               QString("road_name")
#define FC_VOICE_ACTION_HOUSE_NO                                QString("house_no")
#define FC_VOICE_ACTION_POINT_RECORD_TYPE                       QString("ptRecType")
#define FC_VOICE_ACTION_GUIDE_GUIDE_TYPE                        QString("guideType")
#define FC_VOICE_ACTION_GUIDE_LIST                              QString("list")
#define FC_VOICE_ACTION_GUIDE_POINT_NUMBER                      QString("guidPointNumber")
#define FC_VOICE_ACTION_PHONE_IN_CALL                           QString("phoneInCall")
#define FC_VOICE_ACTION_PHONE_PB_MODE                           QString("phonePbMode")

#define FC_VOICE_ACTION_TAG_KEY_CITY_ID                         QString("cityid")

#define FC_VOICE_ACTION_TAG_KEY_APP_ID                          QString("appid")
#define FC_VOICE_ACTION_TAG_KEY_DATA_SIZE                       QString("dataSize")
#define FC_VOICE_ACTION_TAG_KEY_DATA                            QString("data")
#define FC_VOICE_ACTION_TAG_KEY_LINKID                          QString("linkId")
#define FC_VOICE_ACTION_TAG_KEY_ROUTE_ADDRESS                   QString("routeAddress")
#define FC_VOICE_ACTION_TAG_KEY_ROUTE_TEL_NUMBER                QString("routeTelNumber")

// Navi Data Adapter constant define
#define FC_VOICE_NAVI_ADAPTER_CONSTANT_FREEWAY                  QString("FREEWAY")
#define FC_VOICE_NAVI_ADAPTER_CONSTANT_TUNNEL                   QString("TUNNEL")
#define FC_VOICE_NAVI_ADAPTER_CONSTANT_BRIDGE                   QString("BRIDGE")
#define FC_VOICE_NAVI_ADAPTER_CONSTANT_FERRY_ROUTE              QString("FERRY_ROUTE")
#define FC_VOICE_NAVI_ADAPTER_CONSTANT_TOLL_ROAD                QString("TOLL_ROAD")
#define FC_VOICE_NAVI_ADAPTER_CONSTANT_URBAN                    QString("URBAN")
#define FC_VOICE_NAVI_ADAPTER_CONSTANT_VIADUCT                  QString("VIADUCT")

#define FC_VOICE_NAVI_ADAPTER_CONSTANT_HOME                     QString("HOME")
#define FC_VOICE_NAVI_ADAPTER_CONSTANT_PRESET1                  QString("PRESET1")
#define FC_VOICE_NAVI_ADAPTER_CONSTANT_PRESET2                  QString("PRESET2")
#define FC_VOICE_NAVI_ADAPTER_CONSTANT_PRESET3                  QString("PRESET3")
#define FC_VOICE_NAVI_ADAPTER_CONSTANT_PRESET4                  QString("PRESET4")
#define FC_VOICE_NAVI_ADAPTER_CONSTANT_PRESET5                  QString("PRESET5")

// convert point record type to need of navi
enum FC_POINT_RECORD_TYPE
{
    FC_POINT_RECORD_TYPE_HISTORY     = 0,     ///< NAVI_ROUTE_POINT_SOURCE_RECENT
    FC_POINT_RECORD_TYPE_REGISTER    = 1,     ///< NAVI_ROUTE_POINT_SOURCE_FAVORITE
    FC_POINT_RECORD_TYPE_CAMERA      = 2,     ///< 17CY has no this item
    FC_POINT_RECORD_TYPE_HOME        = 3,     ///< NAVI_ROUTE_POINT_SOURCE_HOME
    FC_POINT_RECORD_TYPE_COMPANY     = 4,     ///< 17CY has no this item
    FC_POINT_RECORD_TYPE_PRESET1     = 5,     ///< NAVI_ROUTE_POINT_SOURCE_PRESET
    FC_POINT_RECORD_TYPE_PRESET2     = 6,     ///< NAVI_ROUTE_POINT_SOURCE_PRESET
    FC_POINT_RECORD_TYPE_PRESET3     = 7,     ///< NAVI_ROUTE_POINT_SOURCE_PRESET
    FC_POINT_RECORD_TYPE_PRESET4     = 8,     ///< NAVI_ROUTE_POINT_SOURCE_PRESET
    FC_POINT_RECORD_TYPE_PRESET5     = 9,     ///< NAVI_ROUTE_POINT_SOURCE_PRESET
    FC_POINT_RECORD_TYPE_PRESTART    = 10,    ///< NAVI_ROUTE_POINT_SOURCE_NORMAL
    FC_POINT_RECORD_TYPE_GROUP       = 11,    ///< NAVI_ROUTE_POINT_SOURCE_NORMAL
    FC_POINT_RECORD_TYPE_AVOID_AREA  = 12,    ///< NAVI_ROUTE_POINT_SOURCE_NORMAL
    FC_POINT_RECORD_TYPE_GMEMORY     = 13,    ///< NAVI_ROUTE_POINT_SOURCE_NORMAL
    FC_POINT_RECORD_TYPE_GMAP        = 14,    ///< NAVI_ROUTE_POINT_SOURCE_NORMAL
    FC_POINT_RECORD_TYPE_INVISIBLE   = 15,    ///< NAVI_ROUTE_POINT_SOURCE_NORMAL
    FC_POINT_RECORD_TYPE_INVALID     = 255    ///< NAVI_ROUTE_POINT_SOURCE_NORMAL
};

enum FC_NaviRoutePointSource
{
    FC_NAVI_ROUTE_POINT_SOURCE_NORMAL,    ///<  from map scroll(default)
    FC_NAVI_ROUTE_POINT_SOURCE_HOME,      ///<  home
    FC_NAVI_ROUTE_POINT_SOURCE_PRESET,    ///< preset point, e.g.company
    FC_NAVI_ROUTE_POINT_SOURCE_FAVORITE,   ///< favorite point.
    FC_NAVI_ROUTE_POINT_SOURCE_RECENT,    ///< destination history
    FC_NAVI_ROUTE_POINT_SOURCE_SEARCH      ///<  from searchingaddress, telephone etc.
};

const std::map<int, int>::value_type navi_route_point_source_value[] =
{
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_HISTORY, FC_NAVI_ROUTE_POINT_SOURCE_RECENT),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_REGISTER, FC_NAVI_ROUTE_POINT_SOURCE_FAVORITE),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_HOME, FC_NAVI_ROUTE_POINT_SOURCE_HOME),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_PRESET1, FC_NAVI_ROUTE_POINT_SOURCE_PRESET),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_PRESET2, FC_NAVI_ROUTE_POINT_SOURCE_PRESET),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_PRESET3, FC_NAVI_ROUTE_POINT_SOURCE_PRESET),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_PRESET4, FC_NAVI_ROUTE_POINT_SOURCE_PRESET),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_PRESET5, FC_NAVI_ROUTE_POINT_SOURCE_PRESET),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_PRESTART, FC_NAVI_ROUTE_POINT_SOURCE_NORMAL),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_GROUP, FC_NAVI_ROUTE_POINT_SOURCE_NORMAL),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_AVOID_AREA, FC_NAVI_ROUTE_POINT_SOURCE_NORMAL),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_GMEMORY, FC_NAVI_ROUTE_POINT_SOURCE_NORMAL),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_GMAP, FC_NAVI_ROUTE_POINT_SOURCE_NORMAL),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_INVISIBLE, FC_NAVI_ROUTE_POINT_SOURCE_NORMAL),
    std::map<int, int>::value_type(FC_POINT_RECORD_TYPE_INVALID, FC_NAVI_ROUTE_POINT_SOURCE_NORMAL)
};
const static std::map<int, int> NaviRoutePointSourceMap(navi_route_point_source_value, navi_route_point_source_value+14);

enum FC_NAVI_POIDIRECTION_TYPE
{
    FC_NAVI_POIDIRECTION_TYPE_EAST = 0,
    FC_NAVI_POIDIRECTION_TYPE_NORTHEAST,
    FC_NAVI_POIDIRECTION_TYPE_NORTH,
    FC_NAVI_POIDIRECTION_TYPE_NORTHWEAT,
    FC_NAVI_POIDIRECTION_TYPE_WEST,
    FC_NAVI_POIDIRECTION_TYPE_SOUTHWEST,
    FC_NAVI_POIDIRECTION_TYPE_SOUTH,
    FC_NAVI_POIDIRECTION_TYPE_SOUTHEAST
};

// for performance test
const std::map<std::string, std::string>::value_type fc_performance_info_map[] =
{
    std::map<std::string, std::string>::value_type("call lucy", "212-1 212-119 212-125"),
    std::map<std::string, std::string>::value_type("address", "212-2 212-120 212-126"),
    std::map<std::string, std::string>::value_type("hong kong", "212-2 212-120 212-126"),
    std::map<std::string, std::string>::value_type("gauteng", "212-2 212-120 212-126"),
    std::map<std::string, std::string>::value_type("help", "212-3 215-11 212-121 212-127"),
    std::map<std::string, std::string>::value_type("play song believe", "212-4 212-122 212-128 261-200"),
    std::map<std::string, std::string>::value_type("yes", "212-5 212-123 212-129"),
    std::map<std::string, std::string>::value_type("make a call", "215-3 261-199"),
    std::map<std::string, std::string>::value_type("cancel", "215-4"),
    std::map<std::string, std::string>::value_type("more hints", "215-9"),
    std::map<std::string, std::string>::value_type("audio", "215-7"),
    std::map<std::string, std::string>::value_type("go to audio", "215-7"),
    std::map<std::string, std::string>::value_type("find a poi", "212-124 212-130"),
    std::map<std::string, std::string>::value_type("find kfc", "212-124 212-130"),
    std::map<std::string, std::string>::value_type("example", "test")
};
const static std::map<std::string, std::string> FCPerformanceInfoMap(fc_performance_info_map, fc_performance_info_map + 14);

#endif // VOICEVOICERECOGDEF_H
/* EOF */
