#ifndef VRCONST_H
#define VRCONST_H

#include <stdio.h>
#include <QString>
#include <map>
#include "VoiceVoiceRecogDef.h"

extern const int VR_ERROR_CODE;
extern const int VR_DEFAULT_TASKID;
extern const int VR_INVALID_ID;
extern const int VR_COUNT_PROTECTION;
extern const u_int64_t VOICERECOG_IMPL_PROXY_CALL_ID_ZERO;

extern const QString FC_VR_RECOGNITION_FAILED_STATE;
extern const QString FC_VR_RECOGNITION_ACTION_RESULT_FAILED;
extern const QString FC_VR_RECOGNITION_INVAILED_SOURCE_ID;
extern const QString FC_VR_RECOGNITION_NULL_STRING;

extern const std::string FC_METER_SERVICE_NAME;
extern const std::string FC_BTMAP_SERVICE_NAME;
extern const std::string FC_TELEPHONY_SERVICE_NAME;

extern const std::string FC_TELEPHONY_USERNAME_VR;
extern const QString FC_VR_METER_COOPERATION_OFF_STRING;

// display tag name
extern const QString FC_VR_RESULT_DISPLAY_TAG;
// display tag agent attribute name
extern const QString FC_VR_RESULT_DISPLAY_ATTR_AGENT;
// display tag content attribute name
extern const QString FC_VR_RESULT_DISPLAY_ATTR_CONTENT;
// agent tag name
extern const QString FC_VR_RESULT_AGENT_TAG;
// content tag name
extern const QString FC_VR_RESULT_CONTENT_TAG;

extern const QString FC_VR_RESULT_ENGINETYPE_TAG;
extern const QString FC_VR_RESULT_TYPE_TAG;
extern const QString FC_VR_RESULT_STATE_TAG;
extern const QString FC_VR_RESULT_VOLUME_TAG;
extern const QString FC_VR_RESULT_RESULT_TAG;
extern const QString FC_VR_RESULT_PROMPT_TAG;
extern const QString FC_VR_RESULT_LIST_TAG;
extern const QString FC_VR_RESULT_LIST_ATTR_TYPE;
extern const QString FC_VR_RESULT_ITEMS_TAG;
extern const QString FC_VR_RESULT_DETAIL_TAG;
extern const QString FC_VR_RESULT_PHONETYPE_TAG;
extern const QString FC_VR_RESULT_PHONETYPE_TAG_AN;
extern const QString FC_VR_RESULT_MEEAGEBODY_TAG;
extern const QString FC_VR_RESULT_PHONENAME_VALUE_TAG;
extern const QString FC_VR_RESULT_HISTORYTYPE_TAG;
extern const QString FC_VR_RESULT_TIMESTAMP_TAG;
extern const QString FC_VR_RESULT_ZONE_TAG;
extern const QString FC_VR_RESULT_STREET_TAG;
extern const QString FC_VR_RESULT_HOUSENUMBER_TAG;
extern const QString FC_VR_RESULT_DISTRICT_TAG;
extern const QString FC_VR_RESULT_CITY_TAG;
extern const QString FC_VR_RESULT_ADDRESS_TAG;
extern const QString FC_VR_RESULT_CONTACT_NAME_TAG_AN;
extern const QString FC_VR_RESULT_PROMPTVALUE;
extern const QString FC_VR_RESULT_LATITUDE_TAG;
extern const QString FC_VR_RESULT_LONGITUDE_TAG;
extern const QString FC_VR_RESULT_INDEX_TAG;
extern const QString FC_VR_RESULT_MESSAGEID_TAG;
extern const QString FC_VR_RESULT_PHRASE_TAG;
extern const QString FC_VR_RESULT_STEP_TAG;
extern const QString FC_VR_RESULT_TAG_TAG;
extern const QString FC_VR_RESULT_BODY_TAG;
extern const QString FC_VR_RESULT_PHONENUMBER_TAG;
extern const QString FC_VR_RESULT_MSGAVAILABLE_TAG;
extern const QString FC_VR_RESULT_NEXTITEM_TAG;
extern const QString FC_VR_RESULT_PREVIOUSITEM_TAG;
extern const QString FC_VR_RESULT_CALLTYPE_TAG;
extern const QString FC_VR_RESULT_VOLUME_STATUS_TAG;
extern const QString FC_VR_RESULT_ENABLE_TAG;
extern const QString FC_VR_RESULT_TONES_TAG;
extern const QString FC_VR_RESULT_PHONE_CONTACT_TYPE_NAME_TAG;
extern const QString FC_VR_RESULT_NBEST_TAG;
extern const QString FC_VR_RESULT_ALIGNEDADDRESS_TAG;
extern const QString FC_VR_RESULT_UNIT_TAG;
extern const QString FC_VR_RESULT_METER_COOPERATION_TAG;
extern const QString FC_VR_RESULT_IPOD_DISPLAY_TAG;

// voicetag tag define as following
extern const QString FC_VR_RESULT_CONTACTNAME_TAG;
extern const QString FC_VR_RESULT_CANDIDATA_ONE_NUM_TAG;
extern const QString FC_VR_RESULT_CANDIDATA_TWO_NUM_TAG;
extern const QString FC_VR_RESULT_CANDIDATA_THERE_NUM_TAG;
extern const QString FC_VR_RESULT_CANDIDATA_FOUR_NUM_TAG;
extern const QString FC_VR_RESULT_CANDIDATA_ONE_TYPE_TAG;
extern const QString FC_VR_RESULT_CANDIDATA_TWO_TYPE_TAG;
extern const QString FC_VR_RESULT_CANDIDATA_THERE_TYPE_TAG;
extern const QString FC_VR_RESULT_CANDIDATA_FOUR_TYPE_TAG;

// Uniform tag as following:
// name
extern const QString FC_VR_RESULT_NAME_TAG;
extern const QString FC_VR_RESULT_APPNAME_TAG;
extern const QString FC_VR_RESULT_APP_NAME_TAG;
extern const QString FC_VR_RESULT_FORMAL_NAME_TAG;
extern const QString FC_VR_RESULT_CONTACT_NAME_TAG;
extern const QString FC_VR_RESULT_DIGITS_TAG;
extern const QString FC_VR_RESULT_NUMBER_TAG;
extern const QString FC_VR_RESULT_ARTIST_NAME_TAG;
extern const QString FC_VR_RESULT_ALBUM_NAME_TAG;
extern const QString FC_VR_RESULT_SONG_NAME_TAG;
extern const QString FC_VR_RESULT_PLAYLIST_NAME_TAG;
// extern const QString FC_VR_RESULT_CONTACTNAME_TAG;
extern const QString FC_VR_RESULT_POI_CATEGORY_NAME_TAG;

// title
extern const QString FC_VR_RESULT_TITLE_TAG;

// command
extern const QString FC_VR_RESULT_COMMAND_TAG;
extern const QString FC_VR_RESULT_GENRE_NAME_TAG;
// extern const QString FC_VR_RESULT_ARTIST_NAME_TAG;
// extern const QString FC_VR_RESULT_ALBUM_NAME_TAG;
// extern const QString FC_VR_RESULT_SONG_NAME_TAG;
// extern const QString FC_VR_RESULT_PLAYLIST_NAME_TAG;
extern const QString FC_VR_RESULT_STATION_NAME_TAG;

// subcommand

// display tag agent attribute value
extern const QString FC_VR_AGENT_ATTRI_COMMON_VALUE;
// agent tag value
extern const QString FC_VR_AGENT_VALUE_TOP_MENU;
extern const QString FC_VR_AGENT_VALUE_NAVI;
extern const QString FC_VR_AGENT_VALUE_PHONE;
extern const QString FC_VR_AGENT_VALUE_MEDIA;
extern const QString FC_VR_AGENT_VALUE_APPS;
extern const QString FC_VR_AGENT_VALUE_SENDTONE;
extern const QString FC_VR_AGENT_VALUE_CLIMATE;
extern const QString FC_VR_AGENT_VALUE_DICTATION;
extern const QString FC_VR_AGENT_VALUE_VOICETAG;
extern const QString FC_VR_AGENT_VALUE_HELP;
extern const QString FC_VR_AGENT_VALUE_ADAPTION;
extern const QString FC_VR_AGENT_VALUE_TUNER;
extern const QString FC_VR_AGENT_VALUE_INFORMATION;

// display tag content attribute value
extern const QString FC_VR_RESULT_COMMON_VR_STATE;
extern const QString FC_VR_RESULT_COMMON_VOLUME;
extern const QString FC_VR_RESULT_COMMON_POP_MSG;
extern const QString FC_VR_RESULT_COMMON_SCRENN_DISPLAY;
extern const QString FC_VR_RESULT_COMMON_SHOW_POP_MSG;
extern const QString FC_VR_RESULT_COMMON_DISMISS_POP_MSG;
extern const QString FC_VR_RESULT_COMMON_FOCUSLISTITEM;
extern const QString FC_VR_RESULT_COMMON_QUIT_VRAPP;
extern const QString FC_VR_RESULT_COMMON_HINTS_DISPLAY;
extern const QString FC_VR_RESULT_COMMON_TSL_STATE;
extern const QString FC_VR_RESULT_COMMON_ENDTASK_STATE;
extern const QString FC_VR_RESULT_DISTANCE_UNIT;
extern const QString FC_VR_RESULT_UPDATE_ERROR_ONS;

// Vr quit const string
extern const QString FC_VR_QUIT_STATUS;

extern const int FC_VR_PARSE_XML_RESULT_ERROR;
extern const int FC_VR_PARSE_XML_RESULT_OK;

// used for geting phone type
extern const QString FC_VR_MAP_SEARCHCONTACT_BY_NUMBER;
extern const QString FC_VR_MAP_SEARCHCONTACT_BY_EMAIL;

// ACTION USING
extern const QString FC_VR_RESULT_ALL_ACTION_TAG;
extern const QString FC_VR_RESULT_ACTION_OP;

// The action for my own use
extern const QString FC_VR_ACTION_RETURN_ENGINE;
extern const QString FC_VR_ACTION_RETURN_ENGINE_MEDIA;
extern const QString FC_VR_ACTION_RETURN_ENGINE_PLAY;
extern const QString FC_VR_ACTION_RETURN_ENGINE_PLAY_BY_GENRE;
extern const QString FC_VR_ACTION_RETURN_ENGINE_PLAY_BY_NAME;
extern const QString FC_VR_ACTION_RETURN_ENGINE_PLAY_BY_PRESET;

extern const QString FC_VR_ACTION_RETURN_ENGINE_CLIMATE;
extern const QString FC_VR_ACTION_RETURN_ENGINE_SHOW;

extern const QString FC_VR_ACTION_RETURN_ENGINE_PHONE;
extern const QString FC_VR_ACTION_RETURN_ENGINE_DIAL;

extern const QString FC_VR_ACTION_RETURN_ENGINE_APPS;
extern const QString FC_VR_ACTION_RETURN_ENGINE_HELP;

extern const QString FC_VR_ACTION_RETURN_ENGINE_WEATHER;

extern const QString FC_VR_ACTION_RETURN_ENGINE_NAVI;

// nbest tag value
extern const QString FC_VR_NBEST_TAG_VALUE_TRUE;

// ------------------------------TopMenu VRState(content tag value) ------------------------------------------
// Common
extern const QString FC_VR_STATE_TOP_MENU_IDLE;
extern const QString FC_VR_STATE_TOP_MENU_MORE_HINTS;
// EU
extern const QString FC_VR_STATE_EU_TOP_MENU_IDLE;
extern const QString FC_VR_STATE_EU_TOP_MENU_HELP;
// NA
extern const QString FC_VR_STATE_NA_TOP_MENU_IDLE;
extern const QString FC_VR_STATE_NA_TOP_MENU_MORE_HINTS;

// If you want to build index for adding tag, please refer as following:
extern const QString FC_VR_STATE_TOP_MENU_EXAMPLE;

// TopMenu index enum define
enum TOP_MENU_INDEX
{
    // Common
    FC_VR_STATE_TOP_MENU_IDLE_INDEX = 0,         ///< idle
    FC_VR_STATE_TOP_MENU_MORE_HINTS_INDEX,       ///< more hints
    // EU
    FC_VR_STATE_EU_TOP_MENU_IDLE_INDEX,          ///< idle in Europe
    FC_VR_STATE_EU_TOP_MENU_HELP_INDEX,          ///< more hints in Europe
    // NA
    FC_VR_STATE_NA_TOP_MENU_IDLE_INDEX,          ///< idle in North America
    FC_VR_STATE_NA_TOP_MENU_MORE_HINTS_INDEX,    ///< more hints in North America
    // If you want to build index for adding tag, please refer as following:
    FC_VR_STATE_TOP_MENU_EXAMPLE_INDEX,          ///< an examlpe

    FC_VR_STATE_TOP_MENU_MAX_INDEX               ///< max enum value
};

extern const std::map<QString, int> TopMenuVrStateMap;

// ------------------------------Navi VRState(content tag value) ------------------------------------------
// Common
extern const QString FC_VR_STATE_NAVI_IDLE;
extern const QString FC_VR_STATE_NAVI_MORE_HINTS;
extern const QString FC_VR_STATE_NAVI_SPEAK_ENTRUES_ADDRESS;
extern const QString FC_VR_STATE_NAVI_SPEAK_CITY;
extern const QString FC_VR_STATE_NAVI_SPEAK_HOUSE_NUMBER;
extern const QString FC_VR_STATE_NAVI_SPEAK_STATE;
extern const QString FC_VR_STATE_NAVI_SPEAK_STREET;
extern const QString FC_VR_STATE_NAVI_ADDRESS_CONFIRM;
extern const QString FC_VR_STATE_NAVI_ADDRESS_STREET_SELECT;
extern const QString FC_VR_STATE_NAVI_ADDRESS_DISTRICT_SELECT;
extern const QString FC_VR_STATE_NAVI_ADDRESS_HOUSE_SELECT;
extern const QString FC_VR_STATE_NAVI_ADDRESS_CITY_SELECT;
extern const QString FC_VR_STATE_NAVI_ADDRESS_STATE_SELECT;
extern const QString FC_VR_STATE_NAVI_ADDRESS_RESULT_SELECT;
extern const QString FC_VR_STATE_NAVI_SPEAK_POI;
extern const QString FC_VR_STATE_NAVI_POI_LIST_SELECT;
extern const QString FC_VR_STATE_NAVI_POI_ALONG_ROUTE_SELECT;
extern const QString FC_VR_STATE_NAVI_POI_NEAR_DEST_SELECT;
extern const QString FC_VR_STATE_NAVI_POI_CONFIRM;
extern const QString FC_VR_STATE_NAVI_CONFIRM_DESTINATION;
extern const QString FC_VR_STATE_NAVI_CONFIRM_ASSIST;
extern const QString FC_VR_STATE_NAVI_DESTINATION_SELECT;
extern const QString FC_VR_STATE_NAVI_CONFIRM_DELETE_DESTINATION;
extern const QString FC_VR_STATE_NAVI_DESTINATION_DELETE_SELECT;
extern const QString FC_VR_STATE_NAVI_SET_ROUTE;
extern const QString FC_VR_STATE_NAVI_SET_ROUTE_CONFIRM;
extern const QString FC_VR_STATE_NAVI_POI_CATEGORY_CANDIDATES;
extern const QString FC_VR_STATE_NAVI_POI_SHOW_CANDIDATES;
extern const QString FC_VR_STATE_NAVI_POI_HIDE_CANDIDATES;

// China
extern const QString FC_VR_STATE_CN_NAVI_SPEAK_CITY;
extern const QString FC_VR_STATE_CN_NAVI_SPEAK_DISTRICT;
extern const QString FC_VR_STATE_CN_NAVI_SPEAK_HOUSE_NUMBER;
extern const QString FC_VR_STATE_CN_NAVI_SPEAK_STREET;
extern const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_WEBSEARCH_START;
extern const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_SELECT;
extern const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_WEB_SELECT;
extern const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_LOCAL_SELECT;
extern const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_ALONG_ROUTE_SELECT;
extern const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_NEAR_DEST_SELECT;
extern const QString FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_SELECT;
extern const QString FC_VR_STATE_CN_NAVI_POI_NAME_WEB_SEARCH_START;
extern const QString FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_LOCAL_SELECT;
extern const QString FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_WEB_SELECT;
extern const QString FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_INCITY_SELECT;
extern const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_INCITY_SELECT;
extern const QString FC_VR_STATE_NAVI_CONFIRM_CALL_ASSIST;
// If you want to build index for adding tag, please refer as following:
extern const QString FC_VR_STATE_NAVI_EXAMPLE;

// NAVI state index enum define
enum NAVI_INDEX
{
    // Common
    FC_VR_STATE_NAVI_IDLE_INDEX = 0,                      ///< idle
    FC_VR_STATE_NAVI_MORE_HINTS_INDEX,                    ///< more hints
    FC_VR_STATE_NAVI_SPEAK_ENTRUES_ADDRESS_INDEX,         ///< speak entrues address
    FC_VR_STATE_NAVI_SPEAK_CITY_INDEX,                    ///< speak city
    FC_VR_STATE_NAVI_SPEAK_HOUSE_NUMBER_INDEX,            ///< speak house number
    FC_VR_STATE_NAVI_SPEAK_STATE_INDEX,                   ///< speak state
    FC_VR_STATE_NAVI_SPEAK_STREET_INDEX,                  ///< speak street
    FC_VR_STATE_NAVI_ADDRESS_CONFIRM_INDEX,               ///< address confirm
    FC_VR_STATE_NAVI_ADDRESS_STREET_SELECT_INDEX,         ///< address street select
    FC_VR_STATE_NAVI_ADDRESS_DISTRICT_SELECT_INDEX,       ///< address district select
    FC_VR_STATE_NAVI_ADDRESS_HOUSE_SELECT_INDEX,          ///< address house select
    FC_VR_STATE_NAVI_ADDRESS_CITY_SELECT_INDEX,           ///< address city select
    FC_VR_STATE_NAVI_ADDRESS_STATE_SELECT_INDEX,          ///< address state select
    FC_VR_STATE_NAVI_ADDRESS_RESULT_SELECT_INDEX,         ///< address result select
    FC_VR_STATE_NAVI_SPEAK_POI_INDEX,                     ///< speak poi
    FC_VR_STATE_NAVI_POI_LIST_SELECT_INDEX,               ///< poi list select
    FC_VR_STATE_NAVI_POI_ALONG_ROUTE_SELECT_INDEX,        ///< poi along route select
    FC_VR_STATE_NAVI_POI_NEAR_DEST_SELECT_INDEX,          ///< poi near dest select
    FC_VR_STATE_NAVI_POI_CONFIRM_INDEX,                   ///< poi confirm
    FC_VR_STATE_NAVI_CONFIRM_DESTINATION_INDEX,           ///< confirm destination
    FC_VR_STATE_NAVI_CONFIRM_ASSIST_INDEX,                ///< confirm assist
    FC_VR_STATE_NAVI_DESTINATION_SELECT_INDEX,            ///< destination select
    FC_VR_STATE_NAVI_CONFIRM_DELETE_DESTINATION_INDEX,    ///< confirm delee destination
    FC_VR_STATE_NAVI_DESTINATION_DELETE_SELECT_INDEX,     ///< destination delete select
    FC_VR_STATE_NAVI_SET_ROUTE_INDEX,                     ///< set route
    FC_VR_STATE_NAVI_SET_ROUTE_CONFIRM_INDEX,             ///< set route confirm
    FC_VR_STATE_NAVI_POI_CATEGORY_CANDIDATES_INDEX,       ///< poi category candidates
    FC_VR_STATE_NAVI_POI_SHOW_CANDIDATES_INDEX,           ///< poi show candidates
    FC_VR_STATE_NAVI_POI_HIDE_CANDIDATES_INDEX,           ///< poi hide candidates

    // China
    FC_VR_STATE_CN_NAVI_SPEAK_CITY_INDEX,                 ///< cn speak city
    FC_VR_STATE_CN_NAVI_SPEAK_DISTRICT_INDEX,             ///< cn speak district
    FC_VR_STATE_CN_NAVI_SPEAK_HOUSE_NUMBER_INDEX,         ///< cn speak house number
    FC_VR_STATE_CN_NAVI_SPEAK_STREET_INDEX,               ///< cn speak street
    FC_VR_STATE_CN_NAVI_POI_CATEGORY_WEBSEARCH_START_INDEX,             ///< cn poi category websearc start
    FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_SELECT_INDEX,               ///< cn poi category result select
    FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_WEB_SELECT_INDEX,           ///< cn poi category result_web select
    FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_LOCAL_SELECT_INDEX,         ///< cn poi category result local select
    FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_ALONG_ROUTE_SELECT_INDEX,   ///< cn poi category result along route select
    FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_NEAR_DEST_SELECT_INDEX,     ///< cn poi category result near dest select
    FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_SELECT_INDEX,                   ///< cn poi name result select
    FC_VR_STATE_CN_NAVI_POI_NAME_WEB_SEARCH_START_INDEX,                ///< cn poi name web_searc start
    FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_LOCAL_SELECT_INDEX,             ///< cn poi name result local select
    FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_WEB_SELECT_INDEX,               ///< cn poi name result web select
    FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_INCITY_SELECT_INDEX,            ///< cn poi name result incity select
    FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_INCITY_SELECT_INDEX,        ///< cn poi category result incity select
    FC_VR_STATE_NAVI_CONFIRM_CALL_ASSIST_INDEX,                         ///< cn call assist
    // If you want to build index for adding tag, please refer as following:
    FC_VR_STATE_NAVI_EXAMPLE_INDEX,

    FC_VR_STATE_NAVI_MAX_INDEX
};

extern const std::map<QString, int> NaviVrStateMap;


// ------------------------------Phone VRState(content tag value) ------------------------------------------
// Common
extern const QString FC_VR_STATE_PHONE_IDLE;
extern const QString FC_VR_STATE_PHONE_MORE_HINTS;
extern const QString FC_VR_STATE_PHONE_SPEAK_PHONE_NUMBER;
extern const QString FC_VR_STATE_PHONE_SPEAK_DIGITS;
extern const QString FC_VR_STATE_PHONE_CONFIRM_CALL_NUMBER;
extern const QString FC_VR_STATE_PHONE_SPEAK_CONTACT;
extern const QString FC_VR_STATE_PHONE_CONTACT_SELECT;
extern const QString FC_VR_STATE_PHONE_CONFIRM_CALL_CONTACT;
extern const QString FC_VR_STATE_PHONE_TYPE_SELECT;
extern const QString FC_VR_STATE_PHONE_CONFIRM_CALLBACK_NUMBER;
extern const QString FC_VR_STATE_PHONE_CONFIRM_CALLBACK_CONTACT;
extern const QString FC_VR_STATE_PHONE_CONFIRM_REDIAL_NUMBER;
extern const QString FC_VR_STATE_PHONE_CONFIRM_REDIAL_CONTACT;
// EU
extern const QString FC_VR_STATE_EU_PHONE_NUMBER_SPEAK;
extern const QString FC_VR_STATE_EU_PHONE_DIGITS_SPEAK;
extern const QString FC_VR_STATE_EU_PHONE_ANYSPEECH_SPEAK;
extern const QString FC_VR_STATE_EU_PHONE_ENTRY_SPEAK;
extern const QString FC_VR_STATE_EU_PHONE_NAME_SELECT;
extern const QString FC_VR_STATE_EU_PHONE_CATEGORY_SELECT;
extern const QString FC_VR_STATE_EU_PHONE_CONTACT_SELECT;
extern const QString FC_VR_STATE_EU_PHONE_HELP_LIST;
// NA
extern const QString FC_VR_STATE_NA_PHONE_IDLE;
extern const QString FC_VR_STATE_NA_PHONE_IN_CALL;
extern const QString FC_VR_STATE_NA_PHONE_IN_MESSAGE;
extern const QString FC_VR_STATE_NA_PHONE_MORE_HINTS;
extern const QString FC_VR_STATE_NA_PHONE_CONTACT_SELECT_NAME;
extern const QString FC_VR_STATE_NA_PHONE_CONTACT_SELECT_NUMBER;
extern const QString FC_VR_STATE_NA_PHONE_CONTACT_SELECT_DIGITS;
extern const QString FC_VR_STATE_NA_PHONE_SPEAK_PHONE_NUMBER;
extern const QString FC_VR_STATE_NA_PHONE_SPEAK_DIGITS;
extern const QString FC_VR_STATE_NA_PHONE_CONFIRM_CALL_NUMBER;
extern const QString FC_VR_STATE_NA_PHONE_SPEAK_CONTACT;
extern const QString FC_VR_STATE_NA_PHONE_CONFIRM_CALL_CONTACT;
extern const QString FC_VR_STATE_NA_PHONE_CONTACT_TYPE_SELECT;
extern const QString FC_VR_STATE_NA_PHONE_SELECT_NAME_MATCHES_CALL_SMS;
extern const QString FC_VR_STATE_NA_PHONE_CONFIRM_REPLY_SEND_MSG;
extern const QString FC_VR_STATE_NA_PHONE_SEARCH_CONTACTS_SMS;
extern const QString FC_VR_STATE_NA_PHONE_CONFIRM_SMS_RECIPIENT;
extern const QString FC_VR_STATE_NA_PHONE_CALL_SPEAK_NAME_NUMBER;
extern const QString FC_VR_STATE_NA_PHONE_DICTATE_SMS;
extern const QString FC_VR_STATE_NA_PHONE_LIST_RECENT_CALLS;
extern const QString FC_VR_STATE_NA_PHONE_LIST_MESSAGES;
extern const QString FC_VR_STATE_NA_PHONE_SELECT_QUICK_REPLY;
extern const QString FC_VR_STATE_NA_PHONE_ONE_CALL_CONTACT_MESSAGE_SELECTED;
extern const QString FC_VR_STATE_NA_PHONE_ONE_MESSAGE_SELECTED;
extern const QString FC_VR_STATE_NA_PHONE_SELECT_NAME_AND_TYPE_MATCHES_CALL_SMS;
extern const QString FC_VR_STATE_NA_PHONE_SEND_DTMF;
// If you want to build index for adding tag, please refer as following:
extern const QString FC_VR_STATE_PHONE_EXAMPLE;

// phone vr state index enum define
enum PHONE_INDEX
{
    // Common
    FC_VR_STATE_PHONE_IDLE_INDEX = 0,                                 ///< idle
    FC_VR_STATE_PHONE_MORE_HINTS_INDEX,                               ///< more hints
    FC_VR_STATE_PHONE_SPEAK_PHONE_NUMBER_INDEX,                       ///< speak phone number
    FC_VR_STATE_PHONE_SPEAK_DIGITS_INDEX,                             ///< speak digits
    FC_VR_STATE_PHONE_CONFIRM_CALL_NUMBER_INDEX,                      ///< confirm call number
    FC_VR_STATE_PHONE_SPEAK_CONTACT_INDEX,                            ///< speak contact
    FC_VR_STATE_PHONE_CONTACT_SELECT_INDEX,                           ///< contact select
    FC_VR_STATE_PHONE_CONFIRM_CALL_CONTACT_INDEX,                     ///< confirm call contact
    FC_VR_STATE_PHONE_TYPE_SELECT_INDEX,                              ///< type select
    FC_VR_STATE_PHONE_CONFIRM_CALLBACK_NUMBER_INDEX,                  ///< confirm callback number
    FC_VR_STATE_PHONE_CONFIRM_CALLBACK_CONTACT_INDEX,                 ///< confirm callback contact
    FC_VR_STATE_PHONE_CONFIRM_REDIAL_NUMBER_INDEX,                    ///< confirm redial number
    FC_VR_STATE_PHONE_CONFIRM_REDIAL_CONTACT_INDEX,                   ///< confirm redial contact
    // EU
    FC_VR_STATE_EU_PHONE_NUMBER_SPEAK_INDEX,                          ///< eu number speak
    FC_VR_STATE_EU_PHONE_DIGITS_SPEAK_INDEX,                          ///< eu digits speak
    FC_VR_STATE_EU_PHONE_ANYSPEECH_SPEAK_INDEX,                       ///< eu anyspeech speak
    FC_VR_STATE_EU_PHONE_ENTRY_SPEAK_INDEX,                           ///< eu entry speak
    FC_VR_STATE_EU_PHONE_NAME_SELECT_INDEX,                           ///< eu name select
    FC_VR_STATE_EU_PHONE_CATEGORY_SELECT_INDEX,                       ///< eu category select
    FC_VR_STATE_EU_PHONE_CONTACT_SELECT_INDEX,                        ///< eu contact select
    FC_VR_STATE_EU_PHONE_HELP_LIST_INDEX,                             ///< eu help list
    // NA
    FC_VR_STATE_NA_PHONE_IDLE_INDEX,                                  ///< na idle
    FC_VR_STATE_NA_PHONE_IN_CALL_INDEX,                               ///< na in call
    FC_VR_STATE_NA_PHONE_IN_MESSAGE_INDEX,                            ///< na in message
    FC_VR_STATE_NA_PHONE_MORE_HINTS_INDEX,                            ///< na more hints
    FC_VR_STATE_NA_PHONE_CONTACT_SELECT_NAME_INDEX,                   ///< na contact select name
    FC_VR_STATE_NA_PHONE_CONTACT_SELECT_NUMBER_INDEX,                 ///< na contact select number
    FC_VR_STATE_NA_PHONE_CONTACT_SELECT_DIGITS_INDEX,                 ///< na contact select digits
    FC_VR_STATE_NA_PHONE_SPEAK_PHONE_NUMBER_INDEX,                    ///< na speak phone number
    FC_VR_STATE_NA_PHONE_SPEAK_DIGITS_INDEX,                          ///< na speak digits
    FC_VR_STATE_NA_PHONE_CONFIRM_CALL_NUMBER_INDEX,                   ///< na confirm call number
    FC_VR_STATE_NA_PHONE_SPEAK_CONTACT_INDEX,                         ///< na speak contact
    FC_VR_STATE_NA_PHONE_CONFIRM_CALL_CONTACT_INDEX,                  ///< na confirm call contact
    FC_VR_STATE_NA_PHONE_CONTACT_TYPE_SELECT_INDEX,                   ///< na contact type select
    FC_VR_STATE_NA_PHONE_SELECT_NAME_MATCHES_CALL_SMS_INDEX,          ///< na select name matches call SMS
    FC_VR_STATE_NA_PHONE_CONFIRM_REPLY_SEND_MSG_INDEX,                ///< na confirm reply send MSG
    FC_VR_STATE_NA_PHONE_SEARCH_CONTACTS_SMS_INDEX,                   ///< na search contacts SMS
    FC_VR_STATE_NA_PHONE_CONFIRM_SMS_RECIPIENT_INDEX,                 ///< na confirm SMS recipient
    FC_VR_STATE_NA_PHONE_CALL_SPEAK_NAME_NUMBER_INDEX,                ///< na call speak name number
    FC_VR_STATE_NA_PHONE_DICTATE_SMS_INDEX,                           ///< na dictate SMS
    FC_VR_STATE_NA_PHONE_LIST_RECENT_CALLS_INDEX,                     ///< na list recent calls
    FC_VR_STATE_NA_PHONE_LIST_MESSAGES_INDEX,                         ///< na list messages
    FC_VR_STATE_NA_PHONE_SELECT_QUICK_REPLY_INDEX,                    ///< na select quick reply
    FC_VR_STATE_NA_PHONE_ONE_CALL_CONTACT_MESSAGE_SELECTED_INDEX,     ///< na one call contact message sekected
    FC_VR_STATE_NA_PHONE_ONE_MESSAGE_SELECTED_INDEX,                  ///< na one mesage selected
    FC_VR_STATE_NA_PHONE_SELECT_NAME_AND_TYPE_MATCHES_CALL_SMS_INDEX, ///< na select name and type matches call SMS
    FC_VR_STATE_NA_PHONE_SEND_DTMF_INDEX,                             ///< na send dtmf
    // If you want to build index for adding tag, please refer as following:
    FC_VR_STATE_PHONE_EXAMPLE_INDEX,

    FC_VR_STATE_PHONE_MAX_INDEX
};

extern const std::map<QString, int> PhoneVrStateMap;


// ------------------------------Media VRState(content tag value) ------------------------------------------
// Common
extern const QString FC_VR_STATE_MEDIA_IDLE;
extern const QString FC_VR_STATE_MEDIA_MORE_HINTS;
extern const QString FC_VR_STATE_MEDIA_MUSIC_SPEAK_ARTIST_NAME;
extern const QString FC_VR_STATE_MEDIA_MUSIC_ARTIST_SELECT;
extern const QString FC_VR_STATE_MEDIA_MUSIC_SPEAK_ALBUM_NAME;
extern const QString FC_VR_STATE_MEDIA_MUSIC_ALBUM_SELECT;
extern const QString FC_VR_STATE_MEDIA_MUSIC_SPEAK_SONG_NAME;
extern const QString FC_VR_STATE_MEDIA_MUSIC_SONG_SELECT;
extern const QString FC_VR_STATE_MEDIA_MUSIC_PLAY_LIST_SELECT;
extern const QString FC_VR_STATE_MEDIA_MUSIC_SELECT_SONG_FROM_PLAYLIST;
extern const QString FC_VR_STATE_MEDIA_RADIO_SPEAK_RADIO_FREQUENCY;
extern const QString FC_VR_STATE_MEDIA_RADIO_SPEAK_PRESET_NUMBER;
// EU
extern const QString FC_VR_STATE_EU_MEDIA_GENRE_NAME_SPEAK;
extern const QString FC_VR_STATE_EU_MEDIA_GENRE_NAME_SELECT;
extern const QString FC_VR_STATE_EU_MEDIA_GENRE_CANDIDATE_SELECT;
extern const QString FC_VR_STATE_EU_MEDIA_ARTIST_NAME_SPEAK;
extern const QString FC_VR_STATE_EU_MEDIA_ARTIST_NAME_SELECT;
extern const QString FC_VR_STATE_EU_MEDIA_ARTIST_CANDIDATE_SELECT;
extern const QString FC_VR_STATE_EU_MEDIA_ALBUM_NAME_SPEAK;
extern const QString FC_VR_STATE_EU_MEDIA_ALBUM_NAME_SELECT;
extern const QString FC_VR_STATE_EU_MEDIA_ALBUM_CANDIDATE_SELECT;
extern const QString FC_VR_STATE_EU_MEDIA_TITLE_NAME_SPEAK;
extern const QString FC_VR_STATE_EU_MEDIA_TITLE_NAME_SELECT;
extern const QString FC_VR_STATE_EU_MEDIA_TITLE_MUSIC_SELECT;
extern const QString FC_VR_STATE_EU_MEDIA_PLAYLIST_NAME_SPEAK;
extern const QString FC_VR_STATE_EU_MEDIA_PLAYLIST_NAME_SELECT;
extern const QString FC_VR_STATE_EU_MEDIA_PLAYLIST_MUSIC_SELECT;
extern const QString FC_VR_STATE_EU_MEDIA_ONESHOT_NAME_SPEAK;
extern const QString FC_VR_STATE_EU_MEDIA_ONESHOT_ARTIST_SELECT;
extern const QString FC_VR_STATE_EU_MEDIA_ONESHOT_MUSIC_SELECT;
extern const QString FC_VR_STATE_EU_MEDIA_HELP_LIST;
// NA
extern const QString FC_VR_STATE_NA_MEDIA_IDLE;
extern const QString FC_VR_STATE_NA_MEDIA_MORE_HINTS;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_ARTIST_NAME;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_ALBUM_NAME;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_SONG_NAME;
extern const QString FC_VR_STATE_NA_MEDIA_NBEST_SELECT;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_PLAY_LIST_SELECT;
extern const QString FC_VR_STATE_NA_MEDIA_RADIO_SPEAK_RADIO_FREQUENCY;
extern const QString FC_VR_STATE_NA_MEDIA_RADIO_SPEAK_PRESET_NUMBER;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ARTIST_FOR_ALBUM;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ARTIST_FOR_SONG;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_A_CATEGORY;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ALBUM_FOR_SONG;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_ALBUM_SONG_SELECT;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_ARTIST_ALBUM_SELECT;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_ARTIST_SONG_SELECT;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_AUDIOBOOKS_NAME;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_COMPOSER_NAME;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_COMPOSER_SONG_SELECT;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_GENRE_NAME;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_GENRE_ARTIST_SELECT;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_PLAY_LIST_SONG_SELECT;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_PODCASTNAME;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_SOURCE_SELECT;
extern const QString FC_VR_STATE_NA_MEDIA_MUSIC_PODCAST_ITEM_SELECT;
extern const QString FC_VR_STATE_NA_MEDIA_RADIO_GENRE_SELECT;
extern const QString FC_VR_STATE_NA_MEDIA_RADIO_SATELLITE_CHANNEL_SELECT;

// If you want to build index for adding tag, please refer as following:
extern const QString FC_VR_STATE_MEDIA_EXAMPLE;

// Media VRState index enum define
enum MEDIA_INDEX
{
    // Common
    FC_VR_STATE_MEDIA_IDLE_INDEX = 0,                                   ///< idle
    FC_VR_STATE_MEDIA_MORE_HINTS_INDEX,                                 ///< more hints
    FC_VR_STATE_MEDIA_MUSIC_SPEAK_ARTIST_NAME_INDEX,                    ///< music speak artist name
    FC_VR_STATE_MEDIA_MUSIC_ARTIST_SELECT_INDEX,                        ///< music artist select
    FC_VR_STATE_MEDIA_MUSIC_SPEAK_ALBUM_NAME_INDEX,                     ///< music speak album name
    FC_VR_STATE_MEDIA_MUSIC_ALBUM_SELECT_INDEX,                         ///< music album select
    FC_VR_STATE_MEDIA_MUSIC_SPEAK_SONG_NAME_INDEX,                      ///< music speak song name
    FC_VR_STATE_MEDIA_MUSIC_SONG_SELECT_INDEX,                          ///< music song select
    FC_VR_STATE_MEDIA_MUSIC_PLAY_LIST_SELECT_INDEX,                     ///< music play list select
    FC_VR_STATE_MEDIA_MUSIC_SELECT_SONG_FROM_PLAYLIST_INDEX,            ///< mucic select song from palylist
    FC_VR_STATE_MEDIA_RADIO_SPEAK_RADIO_FREQUENCY_INDEX,                ///< radio speak radio frequency
    FC_VR_STATE_MEDIA_RADIO_SPEAK_PRESET_NUMBER_INDEX,                  ///< radio speak preset number
    // EU
    FC_VR_STATE_EU_MEDIA_GENRE_NAME_SPEAK_INDEX,                        ///< eu genre name speak
    FC_VR_STATE_EU_MEDIA_GENRE_NAME_SELECT_INDEX,                       ///< en genre name select
    FC_VR_STATE_EU_MEDIA_GENRE_CANDIDATE_SELECT_INDEX,                  ///< eu gener candidate select
    FC_VR_STATE_EU_MEDIA_ARTIST_NAME_SPEAK_INDEX,                       ///< eu artist name speak
    FC_VR_STATE_EU_MEDIA_ARTIST_NAME_SELECT_INDEX,                      ///< eu artist name select
    FC_VR_STATE_EU_MEDIA_ARTIST_CANDIDATE_SELECT_INDEX,                 ///< eu artist candidate select
    FC_VR_STATE_EU_MEDIA_ALBUM_NAME_SPEAK_INDEX,                        ///< eu album name speak
    FC_VR_STATE_EU_MEDIA_ALBUM_NAME_SELECT_INDEX,                       ///< eu album name select
    FC_VR_STATE_EU_MEDIA_ALBUM_CANDIDATE_SELECT_INDEX,                  ///< eu album candidate select
    FC_VR_STATE_EU_MEDIA_TITLE_NAME_SPEAK_INDEX,                        ///< eu title name spaek
    FC_VR_STATE_EU_MEDIA_TITLE_NAME_SELECT_INDEX,                       ///< eu title name select
    FC_VR_STATE_EU_MEDIA_TITLE_MUSIC_SELECT_INDEX,                      ///< eu title music select
    FC_VR_STATE_EU_MEDIA_PLAYLIST_NAME_SPEAK_INDEX,                     ///< eu palylist name speak
    FC_VR_STATE_EU_MEDIA_PLAYLIST_NAME_SELECT_INDEX,                    ///< eu palylist name select
    FC_VR_STATE_EU_MEDIA_PLAYLIST_MUSIC_SELECT_INDEX,                   ///< eu playlist music select
    FC_VR_STATE_EU_MEDIA_ONESHOT_NAME_SPEAK_INDEX,                      ///< eu oneshot name speak
    FC_VR_STATE_EU_MEDIA_ONESHOT_ARTIST_SELECT_INDEX,                   ///< eu oneshot artist select
    FC_VR_STATE_EU_MEDIA_ONESHOT_MUSIC_SELECT_INDEX,                    ///< eu oneshot music select
    FC_VR_STATE_EU_MEDIA_HELP_LIST_INDEX,                               ///< eu help list
    // NA
    FC_VR_STATE_NA_MEDIA_IDLE_INDEX,                                    ///< na idle
    FC_VR_STATE_NA_MEDIA_MORE_HINTS_INDEX,                              ///< na more hints
    FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_ARTIST_NAME_INDEX,                 ///< na music speak artist name
    FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_ALBUM_NAME_INDEX,                  ///< na music speak album name
    FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_SONG_NAME_INDEX,                   ///< na music speak song name index
    FC_VR_STATE_NA_MEDIA_NBEST_SELECT_INDEX,                            ///< na nbest select
    FC_VR_STATE_NA_MEDIA_MUSIC_PLAY_LIST_SELECT_INDEX,                  ///< na music playlist select
    FC_VR_STATE_NA_MEDIA_RADIO_SPEAK_RADIO_FREQUENCY_INDEX,             ///< na radio speak radio frequency
    FC_VR_STATE_NA_MEDIA_RADIO_SPEAK_PRESET_NUMBER_INDEX,               ///< na radio speak preset number
    FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ARTIST_FOR_ALBUM_INDEX,            ///< na music which artist for album
    FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ARTIST_FOR_SONG_INDEX,             ///< na music which artist for song
    FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_A_CATEGORY_INDEX,                  ///< na music speak a category
    FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ALBUM_FOR_SONG_INDEX,              ///< na music which album for song
    FC_VR_STATE_NA_MEDIA_MUSIC_ALBUM_SONG_SELECT_INDEX,                 ///< na album song select
    FC_VR_STATE_NA_MEDIA_MUSIC_ARTIST_ALBUM_SELECT_INDEX,               ///< na nusic artist album select
    FC_VR_STATE_NA_MEDIA_MUSIC_ARTIST_SONG_SELECT_INDEX,                ///< na music artist song select
    FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_AUDIOBOOKS_NAME_INDEX,             ///< na music speak audiobooks name
    FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_COMPOSER_NAME_INDEX,               ///< na music speak composer name
    FC_VR_STATE_NA_MEDIA_MUSIC_COMPOSER_SONG_SELECT_INDEX,              ///< na music composer song select
    FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_GENRE_NAME_INDEX,                  ///< na music speak genre name
    FC_VR_STATE_NA_MEDIA_MUSIC_GENRE_ARTIST_SELECT_INDEX,               ///< na music genre artist select
    FC_VR_STATE_NA_MEDIA_MUSIC_PLAY_LIST_SONG_SELECT_INDEX,             ///< na music play list song select
    FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_PODCASTNAME_INDEX,                 ///< na music speak podcastname
    FC_VR_STATE_NA_MEDIA_MUSIC_SOURCE_SELECT_INDEX,                     ///< na music source select
    FC_VR_STATE_NA_MEDIA_MUSIC_PODCAST_ITEM_SELECT_INDEX,               ///< na music podcast item select
    FC_VR_STATE_NA_MEDIA_RADIO_GENRE_SELECT_INDEX,                      ///< na radio genre select
    FC_VR_STATE_NA_MEDIA_RADIO_SATELLITE_CHANNEL_SELECT_INDEX,          ///< na radio satellite channel select
    // If you want to build index for adding tag, please refer as following:
    FC_VR_STATE_MEDIA_EXAMPLE_INDEX,

    FC_VR_STATE_MEDIA_MAX_INDEX
};

extern const std::map<QString, int> MediaVrStateMap;

// ------------------------------Apps VRState(content tag value) ------------------------------------------
// Common
extern const QString FC_VR_STATE_APPS_IDLE;
extern const QString FC_VR_STATE_APPS_MORE_HINTS;
extern const QString FC_VR_STATE_APPS_APPS_LIST_SELECT;
extern const QString FC_VR_STATE_APPS_APP_CANDIDATES_SELECT;
// NA
extern const QString FC_VR_STATE_NA_APPS_IDLE;
extern const QString FC_VR_STATE_NA_APPS_MORE_HINTS;
extern const QString FC_VR_STATE_NA_APPS_APPS_LIST_SELECT;
extern const QString FC_VR_STATE_NA_APPS_APP_CANDIDATES_SELECT;
// If you want to build index for adding tag, please refer as following:
extern const QString FC_VR_STATE_APPS_EXAMPLE;

// App VRState index enum define
enum APPS_INDEX
{
    // Common
    FC_VR_STATE_APPS_IDLE_INDEX = 0,                        ///< idle
    FC_VR_STATE_APPS_MORE_HINTS_INDEX,                      ///< more hints
    FC_VR_STATE_APPS_APPS_LIST_SELECT_INDEX,                ///< apps list select
    FC_VR_STATE_APPS_APP_CANDIDATES_SELECT_INDEX,           ///< app candidates select
    // NA
    FC_VR_STATE_NA_APPS_IDLE_INDEX,                         ///< na idle
    FC_VR_STATE_NA_APPS_MORE_HINTS_INDEX,                   ///< na more hints
    FC_VR_STATE_NA_APPS_APPS_LIST_SELECT_INDEX,             ///< na apps list select
    FC_VR_STATE_NA_APPS_APP_CANDIDATES_SELECT_INDEX,        ///< na app candidates select
    // If you want to build index for adding tag, please refer as following:
    FC_VR_STATE_APPS_EXAMPLE_INDEX,

    FC_VR_STATE_APPS_MAX_INDEX
};

extern const std::map<QString, int> AppsVrStateMap;

// ------------------------------SendTones VRState(content tag value) ------------------------------------------
extern const QString FC_VR_STATE_SENDTONE_SPEAK_TONES;
extern const QString FC_VR_STATE_SENDTONE_CONFIRM_TONES;

// If you want to build index for adding tag, please refer as following:
extern const QString FC_VR_STATE_SENDTONE_EXAMPLE;

// SendTones VRState index enum define
enum SEND_TONES_INDEX
{
    FC_VR_STATE_SENDTONE_SPEAK_TONES_INDEX = 0,             ///< sendtone speak tones
    FC_VR_STATE_SENDTONE_CONFIRM_TONES_INDEX,               ///< sendtone confirm tones
    // If you want to build index for adding tag, please refer as following:
    FC_VR_STATE_SENDTONE_EXAMPLE_INDEX,

    FC_VR_STATE_SENDTONE_MAX_INDEX
};

extern const std::map<QString, int> SendToneVrStateMap;


// ------------------------------VoiceTag VRState(content tag value) ------------------------------------------
extern const QString FC_VR_STATE_VOICETAG_IDLE;
extern const QString FC_VR_STATE_VOICETAG_CONTACT_SELECT;
extern const QString FC_VR_STATE_VOICETAG_DETAIL_SELECT;

extern const QString FC_VR_STATE_VOICETAG_ERR_TAG_NONE;
extern const QString FC_VR_STATE_VOICETAG_ERR_PHONE_NOT_REGISTER;
extern const QString FC_VR_STATE_VOICETAG_ERR_PHONE_NOT_CONNECTED;
extern const QString FC_VR_STATE_VOICETAG_EXIT_IDLE;
extern const QString FC_VR_STATE_VOICETAG_EXIT_NAME;
extern const QString FC_VR_STATE_VOICETAG_EXIT_TYPE;

// If you want to build index for adding tag, please refer as following:
extern const QString FC_VR_STATE_VOICETAG_EXAMPLE;

// VoiceTag VRState index enum define
enum VOICETAG_INDEX
{
    FC_VR_STATE_VOICETAG_IDLE_INDEX = 0,                    ///< idle
    FC_VR_STATE_VOICETAG_CONTACT_SELECT_INDEX,              ///< contact select
    FC_VR_STATE_VOICETAG_DETAIL_SELECT_INDEX,               ///< detail select

    FC_VR_STATE_VOICETAG_ERR_TAG_NONE_INDEX,                ///< voicetag err tag none
    FC_VR_STATE_VOICETAG_ERR_PHONE_NOT_REGISTER_INDEX,      ///< voicetag err phone not register
    FC_VR_STATE_VOICETAG_ERR_PHONE_NOT_CONNECTED_INDEX,     ///< voicetag err phone not connected
    FC_VR_STATE_VOICETAG_EXIT_IDLE_INDEX,                   ///< voicetag exit idle
    FC_VR_STATE_VOICETAG_EXIT_NAME_INDEX,                   ///< voicetag exit name
    FC_VR_STATE_VOICETAG_EXIT_TYPE_INDEX,                   ///< voicetag exit type

    // If you want to build index for adding tag, please refer as following:
    FC_VR_STATE_VOICETAG_EXAMPLE_INDEX,

    FC_VR_STATE_VOICETAG_MAX_INDEX
};

extern const std::map<QString, int> VoiceTagVrStateMap;

// ------------------------------Climate VRState(content tag value) ------------------------------------------
// Common
extern const QString FC_VR_STATE_CLIMATE_IDLE;
extern const QString FC_VR_STATE_CLIMATE_MORE_HINTS;

// NA
extern const QString FC_VR_STATE_NA_CLIMATE_IDLE;
extern const QString FC_VR_STATE_NA_CLIMATE_MORE_HINTS;
extern const QString FC_VR_STATE_NA_CLIMATE_SET_THE_TEMPERATURE;
extern const QString FC_VR_STATE_NA_CLIMATE_SET_THE_FAN_SPEED;

// If you want to build index for adding tag, please refer as following:
extern const QString FC_VR_STATE_CLIMATE_EXAMPLE;

// Climate VRState index enum define
enum CLIMATE_INDEX
{
    // Common
    FC_VR_STATE_CLIMATE_IDLE_INDEX = 0,                     ///< idle
    FC_VR_STATE_CLIMATE_MORE_HINTS_INDEX,                   ///< more hints
    // NA
    FC_VR_STATE_NA_CLIMATE_IDLE_INDEX,                      ///< na idle
    FC_VR_STATE_NA_CLIMATE_MORE_HINTS_INDEX,                ///< na more hints
    FC_VR_STATE_NA_CLIMATE_SET_THE_TEMPERATURE_INDEX,       ///< na set the temparature
    FC_VR_STATE_NA_CLIMATE_SET_THE_FAN_SPEED_INDEX,         ///< na set the fan speed
    // If you want to build index for adding tag, please refer as following:
    FC_VR_STATE_CLIMATE_EXAMPLE_INDEX,

    FC_VR_STATE_CLIMATE_MAX_INDEX
};

extern const std::map<QString, int> ClimateVrStateMap;

// ------------------------------Help VRState(content tag value) ------------------------------------------
extern const QString FC_VR_STATE_NA_HELP_TUTORIAL_CONFIRMATION;
extern const QString FC_VR_STATE_NA_HELP_TRAIN_VOICE_RECOGNITION;
extern const QString FC_VR_STATE_INFORMATION_SELECT;
extern const QString FC_VR_STATE_INFORMATION_IDLE;
extern const QString FC_VR_STATE_INFORMATION_MORE_HINTS;
extern const QString FC_VR_STATE_NA_HELP_MORE_HINTS;

// If you want to build index for adding tag, please refer as following:
extern const QString FC_VR_STATE_HELP_EXAMPLE;

// Help VRState index enum define
enum HELP_INDEX
{
    FC_VR_STATE_NA_HELP_TUTORIAL_CONFIRMATION_INDEX = 0,            ///< na help tutorial confirmation
    FC_VR_STATE_NA_HELP_TRAIN_VOICE_RECOGNITION_INDEX,              ///< na help train voice recognition
    FC_VR_STATE_INFORMATION_SELECT_INDEX,                           ///< information select
    FC_VR_STATE_INFORMATION_IDLE_INDEX,                             ///< information idle
    FC_VR_STATE_INFORMATION_MORE_HINTS_INDEX,                       ///< information more hints
    FC_VR_STATE_NA_HELP_MORE_HINTS_INDEX,                           ///< na help more hints
    // If you want to build index for adding tag, please refer as following:
    FC_VR_STATE_HELP_EXAMPLE_INDEX,

    FC_VR_STATE_HELP_MAX_INDEX
};

extern const std::map<QString, int> HelpVrStateMap;


// ------------------------------Adaption VRState(content tag value) ------------------------------------------
extern const QString FC_VR_STATE_NA_ADAPTION;

// If you want to build index for adding tag, please refer as following:
extern const QString FC_VR_STATE_ADAPTION_EXAMPLE;

// Adaption VRState index enum define
enum ADAPTION_INDEX
{
    FC_VR_STATE_NA_ADAPTION_INDEX = 0,              ///< na adaptation
    // If you want to build index for adding tag, please refer as following:
    FC_VR_STATE_ADAPTION_EXAMPLE_INDEX,             ///< an example for adding new tag

    FC_VR_STATE_ADAPTION_MAX_INDEX
};

extern const std::map<QString, int> AdaptionVrStateMap;

// ------------------------------Dictation VRState(content tag value) ------------------------------------------
// NA
extern const QString FC_VR_STATE_NA_DICTATION_CITIES_KEYBOARD;
extern const QString FC_VR_STATE_NA_DICTATION_GENERIC_KEYBOARD;
extern const QString FC_VR_STATE_NA_DICTATION_HFD_KEYBOARD;
extern const QString FC_VR_STATE_NA_DICTATION_MESSAGE;
extern const QString FC_VR_STATE_NA_DICTATION_MUSIC_KEYBOARD;
extern const QString FC_VR_STATE_NA_DICTATION_NAVIGATION_KEYBOARD;
extern const QString FC_VR_STATE_NA_DICTATION_POI_KEYBOARD;
extern const QString FC_VR_STATE_NA_DICTATION_STATES_KEYBOARD;
extern const QString FC_VR_STATE_NA_DICTATION_STREETS_KEYBOARD;

// ------------------------------Tuner VRState(content tag value) ------------------------------------------
// EU
extern const QString FC_VR_STATE_EU_TUNER_STATION_NAME_INPUT;
extern const QString FC_VR_STATE_EU_TUNER_STATION_NAME_SELECT;
extern const QString FC_VR_STATE_EU_TUNER_STATION_SELECT;
extern const QString FC_VR_STATE_EU_TUNER_HELP_LIST;
// If you want to build index for adding tag, please refer as following:
extern const QString FC_VR_STATE_EU_TUNER_EXAMPLE;

// Tuner VRState index enum define
enum Tuner_INDEX
{
    FC_VR_STATE_EU_TUNER_STATION_NAME_INPUT_INDEX = 0,          ///< eu tuner station name input
    FC_VR_STATE_EU_TUNER_STATION_NAME_SELECT_INDEX,             ///< eu tuner station name select
    FC_VR_STATE_EU_TUNER_STATION_SELECT_INDEX,                  ///< eu tuner station select
    FC_VR_STATE_EU_TUNER_HELP_LIST_INDEX,                       ///< eu tuner help list
    // If you want to build index for adding tag, please refer as following:
    FC_VR_STATE_EU_TUNER_EXAMPLE_INDEX,                         ///< an example for adding new tag

    FC_VR_STATE_EU_TUNER_MAX_INDEX
};

extern const std::map<QString, int> TunerVrStateMap;


// ---------------------------Button operation value define(Service using)
extern const QString FC_VR_BTNOPER_VALUE_SELECT_ONE;
extern const QString FC_VR_BTNOPER_VALUE_SELECT_TWO;
extern const QString FC_VR_BTNOPER_VALUE_SELECT_THREE;
extern const QString FC_VR_BTNOPER_VALUE_SELECT_FOUR;
extern const QString FC_VR_BTNOPER_VALUE_SELECT_FIVE;
extern const QString FC_VR_BTNOPER_VALUE_SELECT_SIX;
extern const QString FC_VR_BTNOPER_VALUE_PHONE;
extern const QString FC_VR_BTNOPER_VALUE_NAVI;
extern const QString FC_VR_BTNOPER_VALUE_APPS;
extern const QString FC_VR_BTNOPER_VALUE_AUDIO;
extern const QString FC_VR_BTNOPER_VALUE_CLIMATE;
extern const QString FC_VR_BTNOPER_VALUE_HELP;
extern const QString FC_VR_BTNOPER_VALUE_INFO;
extern const QString FC_VR_BTNOPER_VALUE_GO_BACK;
extern const QString FC_VR_BTNOPER_VALUE_START_OVER;
extern const QString FC_VR_BTNOPER_VALUE_PAUSE;
extern const QString FC_VR_BTNOPER_VALUE_RESUME;
extern const QString FC_VR_BTNOPER_VALUE_CANCEL;
extern const QString FC_VR_BTNOPER_VALUE_MORE_HINTS;
extern const QString FC_VR_BTNOPER_VALUE_PRE_PAGE;
extern const QString FC_VR_BTNOPER_VALUE_NEXT_PAGE;
extern const QString FC_VR_BTNOPER_VALUE_FIRST_PAGE;
extern const QString FC_VR_BTNOPER_VALUE_END_PAGE;
extern const QString FC_VR_BTNOPER_VALUE_YES;
extern const QString FC_VR_BTNOPER_VALUE_NO;
extern const QString FC_VR_BTNOPER_VALUE_OK;
extern const QString FC_VR_BTNOPER_VALUE_START;
extern const QString FC_VR_BTNOPER_VALUE_BEGINNING;
extern const QString FC_VR_BTNOPER_VALUE_END;
extern const QString FC_VR_BTNOPER_VALUE_GO_DIRECTLY;
extern const QString FC_VR_BTNOPER_VALUE_ADD_TO_ROUTE;
extern const QString FC_VR_BTNOPER_VALUE_CALL;
extern const QString FC_VR_BTNOPER_VALUE_REPLY;
extern const QString FC_VR_BTNOPER_VALUE_SEND_MESSAGE;
extern const QString FC_VR_BTNOPER_VALUE_NEXT;
extern const QString FC_VR_BTNOPER_VALUE_PREVIOUS;
extern const QString FC_VR_BTNOPER_VALUE_RETRY;
extern const QString FC_VR_BTNOPER_VALUE_TUTORIALS;
extern const QString FC_VR_BTNOPER_VALUE_VOICE_TRAINING;
extern const QString FC_VR_BTNOPER_VALUE_ALONG_ROUTE;
extern const QString FC_VR_BTNOPER_VALUE_NEAR_DESTINATION;
extern const QString FC_VR_BTNOPER_VALUE_NEAR_HERE;
extern const QString FC_VR_BTNOPER_VALUE_ALONG_MY_ROUTE;
extern const QString FC_VR_BTNOPER_VALUE_ALONG_THIS_ROUTE;
extern const QString FC_VR_BTNOPER_VALUE_ALONG_A_SAVED_ROUTE;
extern const QString FC_VR_BTNOPER_VALUE_ALBUM;
extern const QString FC_VR_BTNOPER_VALUE_ARTIST;
extern const QString FC_VR_BTNOPER_VALUE_SONG;
extern const QString FC_VR_BTNOPER_VALUE_COMPOSE;
extern const QString FC_VR_BTNOPER_VALUE_GENRE;
extern const QString FC_VR_BTNOPER_VALUE_PODCASE;
extern const QString FC_VR_BTNOPER_VALUE_PLAY_LIST;
extern const QString FC_VR_BTNOPER_VALUE_AUDIOBOOK;
extern const QString FC_VR_BTNOPER_VALUE_CANDIDATE1_NUM2;
extern const QString FC_VR_BTNOPER_VALUE_CANDIDATE1_NUM3;
extern const QString FC_VR_BTNOPER_VALUE_CANDIDATE1_NUM4;
extern const QString FC_VR_BTNOPER_VALUE_CANDIDATE2;
extern const QString FC_VR_BTNOPER_VALUE_CANDIDATE3;
extern const QString FC_VR_BTNOPER_VALUE_CANDIDATE_NUM2;
extern const QString FC_VR_BTNOPER_VALUE_CANDIDATE_NUM3;
extern const QString FC_VR_BTNOPER_VALUE_CANDIDATE_NUM4;
extern const QString FC_VR_BTNOPER_VALUE_HARD_KEY_OFF_HOOK_SHORT_PRESS;
extern const QString FC_VR_BTNOPER_VALUE_HARD_KEY_OFF_HOOK_LONG_PRESS;
extern const QString FC_VR_BTNOPER_VALUE_HARD_KEY_TEL_SHORT_PRESS;
extern const QString FC_VR_BTNOPER_VALUE_HARD_KEY_TEL_LONG_PRESS;
extern const QString FC_VR_BTNOPER_VALUE_DO_NOT_TELL_ME_AGAIN;
extern const QString FC_VR_BTNOPER_VALUE_SET_PVR_FLAG;
extern const QString FC_VR_BTNOPER_VALUE_PTT_HARD_KEY_SHORT_PRESS;
extern const QString FC_VR_BTNOPER_VALUE_PTT_HARD_KEY_LONG_PRESS;
extern const QString FC_VR_BTNOPER_VALUE_BACK_LONG_PRESS;
extern const QString FC_VR_BTNOPER_VALUE_BACK_SHORT_PRESS;
extern const QString FC_VR_BTNOPER_VALUE_STOP_READING;

extern const QString FC_VR_BTNOPER_VALUE_HARD_KEY_ENTER_LONG_PRESS;
extern const QString FC_VR_BTNOPER_VALUE_HARD_KEY_ENTER_SHORT_PRESS;

extern const QString FC_VR_BTNOPER_VALUE_DEBUG_INPUT_ON;
extern const QString FC_VR_BTNOPER_VALUE_DEBUG_INPUT_OFF;
extern const QString FC_VR_BTNOPER_VALUE_DEBUG_OUTPUT_ON;
extern const QString FC_VR_BTNOPER_VALUE_DEBUG_OUTPUT_OFF;

extern const QString FC_VR_BTNOPER_VALUE_WEB_SEARCH;

extern const QString FC_VR_BTNOPER_VALUE_METER_HARD_KEY_BACK_SHORT_PRESS;
extern const QString FC_VR_BTNOPER_VALUE_METER_HARD_KEY_BACK_LONG_PRESS;

extern const QString FC_VR_BTNOPER_VALUE_HARD_KEY_ENTER_NORMAL_PRESS;
extern const QString FC_VR_BTNOPER_VALUE_METER_HARD_KEY_BACK_NORMAL_PRESS;
extern const QString FC_VR_BTNOPER_VALUE_PTT_HARD_SHORT_PRESS_SPECIAL;
extern const QString FC_VR_BTNOPER_VALUE_HARD_KEY_CANCEL_VR;
extern const QString  FC_VR_BTNOPER_VALUE_PTT_HARD_KEY_PRESS_SPECIAL_IN_ENDTASKSTATUS;

// vr inner using
extern const QString FC_VR_BTNOPER_VALUE_SETTING_VOICE_TRAINING_START;

extern const std::map<int, QString> ButtonValueMap;

// VR implement Key enum define
enum VR_IMPL_KEY
{
    VR_COMMON_IMPL_KEY = 0,             ///< common impl
    VR_APP_IMPL_KEY,                    ///< APP impl
    VR_DICTATION_IMPL_KEY,              ///< dictation impl
    VR_MEDIA_IMPL_KEY,                  ///< media impl
    VR_NAVI_IMPL_KEY,                   ///< navi impl
    VR_PHONE_IMPL_KEY,                  ///< phone impl
    VR_SENDTONE_IMPL_KEY,               ///< sendtone impl
    VR_TOPMENU_IMPL_KEY,                ///< topmenu impl
    VR_CLIMATE_IMPL_KEY,                ///< climate impl
    VR_VOICETAG_IMPL_KEY,               ///< voicetag impl
    VR_HELP_IMPL_KEY,                   ///< help impl
    VR_ADAPTION_IMPL_KEY,               ///< adaption impl
    VR_METER_IMPL_KEY,                  ///< meter impl
    VR_TSL_IMPL_KEY,                    ///< tsl impl
    VR_TUNER_IMPL_KEY,                  ///< tuner impl
    VR_WEATHER_IMPL_KEY,                ///< weather impl
    VR_IMPL_KEY_MAX,
};

// ------------------------------Action Media op ------------------------------------------

extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ALBUM;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ALL;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ARTIST;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_AUDIO_BOOK;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_COMPOSER;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PLAYLIST;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PODCAST;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PODCAST_ITEM;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_SONG;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ALBUM;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ARTIST;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_COMPOSER;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ALL;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_PLAYLIST;

extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_ARTIST_ALBUM;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_ARTIST;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ARTIST_ALBUM;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_CHANGE_SOURCE;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_TURN_AUDIO_OFF;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_TURN_AUDIO_ON;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_PODCAST_BY_EPISODE;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_CHANGE_SOURCE_BY_NAME;

extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ARTIST;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ARTIST_BY_GENRE;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_BY_ARTIST;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_BY_GENRE_ARTIST;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_BY_ARTIST;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_BY_GENRE_ARTIST;

extern const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_GENRE;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_SONG;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_PLAYLIST;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_ARTIST;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_ARTIST_BY_GENRE;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM_BY_ARTIST;
extern const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM_BY_GENRE_ARTIST;

extern const QString FC_VR_ACTION_MEDIA_RADIO_CHANGE_HD_SUB_CHANNEL;
extern const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_FREQUENCY;
extern const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_HD_FREQUENCY;
extern const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_SATELLITE;
extern const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_SATELLITE_CHANNEL_NUMBER;
extern const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_AM;
extern const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_FM;
extern const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_GENRE;
extern const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_XM_CATEGORY;
extern const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_DAB_CHANNEL;
extern const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_CHANNEL;
extern const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_SATELLITE_CHANNEL;
extern const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_MIX_RADIO_PRESET;
extern const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_RADIO_PRESET;

extern const QString FC_VR_ACTION_HVAC_SHOW_FRONT_SCREEN;
extern const QString FC_VR_ACTION_HVAC_SHOW_REAR_SCREEN;
extern const QString FC_VR_ACTION_HVAC_SHOW_STEERING_SCREEN;
extern const QString FC_VR_ACTION_HVAC_SHOW_FRONT_SEAT_SCREEN;
extern const QString FC_VR_ACTION_HVAC_SHOW_REAR_SEAT_SCREEN;
extern const QString FC_VR_ACTION_HVAC_SHOW_LEXUS_CONCIERGE_SCREEN;
extern const QString FC_VR_ACTION_HVAC_SHOW_SEAT_OPERATION_SCREEN;
extern const QString FC_VR_ACTION_HVAC_SHOW_FRONT_SEAT_VENTI_SCREEN;
extern const QString FC_VR_ACTION_HVAC_SHOW_REAR_SEAT_VENTI_SCREEN;
extern const QString FC_VR_ACTION_HVAC_SHOW_FRONT_AC_SCREEN;
extern const QString FC_VR_ACTION_HVAC_SHOW_REAR_AC_SCREEN;
extern const QString FC_VR_ACTION_HVAC_SHOW_SEAT_SCREEN;
extern const QString FC_VR_ACTION_HVAC_SHOW_EXAMPLE;

extern const QString FC_VR_ACTION_MEDIA_EXAMPLE;

// Action media operation index enum define
enum ACTION_MEDIA_INDEX
{
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ALBUM_INDEX = 0,                       ///< music play by album
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ALL_INDEX,                             ///< music play by all
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ARTIST_INDEX,                          ///< music play by artist
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_AUDIO_BOOK_INDEX,                      ///< music play by audio book
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_COMPOSER_INDEX,                        ///< music play by composer
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_INDEX,                           ///< music play by genre
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PLAYLIST_INDEX,                        ///< music play by playlist
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PODCAST_INDEX,                         ///< music play by podcast
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PODCAST_ITEM_INDEX,                    ///< music play by podcast item
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_SONG_INDEX,                            ///< music play by song
    FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ALBUM_INDEX,                   ///< music shuffle play by album
    FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ARTIST_INDEX,                  ///< music shuffle play by artist
    FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_COMPOSER_INDEX,                ///< music shuffle play by composer
    FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ALL_INDEX,                     ///< music shuffle play by all
    FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_PLAYLIST_INDEX,                ///< music shuffle play by playlist

    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_ARTIST_ALBUM_INDEX,              ///< music play by genre artist album
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_ARTIST_INDEX,                    ///< music play by genre artist
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ARTIST_ALBUM_INDEX,                    ///< music play by artist album
    FC_VR_ACTION_MEDIA_MUSIC_CHANGE_SOURCE_INDEX,                           ///< music change source
    FC_VR_ACTION_MEDIA_MUSIC_TURN_AUDIO_OFF_INDEX,                          ///< music turn audio off
    FC_VR_ACTION_MEDIA_MUSIC_TURN_AUDIO_ON_INDEX,                           ///< music turn audio on
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_PODCAST_BY_EPISODE_INDEX,                 ///< music play podcast by episode
    FC_VR_ACTION_MEDIA_MUSIC_CHANGE_SOURCE_BY_NAME_INDEX,                   ///< music change source by name


    FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ARTIST_INDEX,                         ///< music play all artist
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_INDEX,                          ///< music play all album
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ARTIST_BY_GENRE_INDEX,                ///< music play all artist by genre
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_BY_ARTIST_INDEX,                ///< music play all album by artist
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_BY_GENRE_ARTIST_INDEX,          ///< music play all album by genre artist
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_INDEX,                          ///< music play the album
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_BY_ARTIST_INDEX,                ///< music play the album by artist
    FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_BY_GENRE_ARTIST_INDEX,          ///< music play the album by genre artist

    FC_VR_ACTION_MEDIA_MUSIC_SHOW_GENRE_INDEX,                              ///< music show genre
    FC_VR_ACTION_MEDIA_MUSIC_SHOW_SONG_INDEX,                               ///< music show song
    FC_VR_ACTION_MEDIA_MUSIC_SHOW_PLAYLIST_INDEX,                           ///< music show playlist
    FC_VR_ACTION_MEDIA_MUSIC_SHOW_ARTIST_INDEX,                             ///< music show artist
    FC_VR_ACTION_MEDIA_MUSIC_SHOW_ARTIST_BY_GENRE_INDEX,                    ///< music show artist by genre
    FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM_INDEX,                              ///< music show album
    FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM_BY_ARTIST_INDEX,                    ///< music show album by artist
    FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM_BY_GENRE_ARTIST_INDEX,              ///< music show album by genre artist


    FC_VR_ACTION_MEDIA_RADIO_CHANGE_HD_SUB_CHANNEL_INDEX,                   ///< radio change HD sub channel
    FC_VR_ACTION_MEDIA_RADIO_TUNE_FREQUENCY_INDEX,                          ///< radio tune frequency
    FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_HD_FREQUENCY_INDEX,                    ///< radio tune FM HD frequency
    FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_SATELLITE_INDEX,                     ///< radio tune last satellite
    FC_VR_ACTION_MEDIA_RADIO_TUNE_SATELLITE_CHANNEL_NUMBER_INDEX,           ///< radio tune  satellite channel number
    FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_AM_INDEX,                            ///< radio tune last AM
    FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_FM_INDEX,                            ///< radio tune last FM
    FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_GENRE_INDEX,                           ///< radio tune FM genre
    FC_VR_ACTION_MEDIA_RADIO_TUNE_XM_CATEGORY_INDEX,                        ///< radio tune XM category
    FC_VR_ACTION_MEDIA_RADIO_TUNE_DAB_CHANNEL_INDEX,                        ///< radio tune DAB channel
    FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_CHANNEL_INDEX,                         ///< radio tune FM channel
    FC_VR_ACTION_MEDIA_RADIO_TUNE_SATELLITE_CHANNEL_INDEX,                  ///< radio tune satellite channel
    FC_VR_ACTION_MEDIA_RADIO_TUNE_MIX_RADIO_PRESET_INDEX,                   ///< radio tune mix radio preset
    FC_VR_ACTION_MEDIA_RADIO_TUNE_RADIO_PRESET_INDEX,                       ///< radio tune radio preset

    FC_VR_ACTION_MEDIA_EXAMPLE_INDEX
};

extern const std::map<QString, int> VrActioMediaMap;

// Action hvac index enum define
enum ACTION_HVAC_INDEX
{
    FC_VR_ACTION_HVAC_SHOW_FRONT_SCREEN_INDEX = 0,                  ///< show front screen
    FC_VR_ACTION_HVAC_SHOW_REAR_SCREEN_INDEX,                       ///< show rear screen
    FC_VR_ACTION_HVAC_SHOW_STEERING_SCREEN_INDEX,                   ///< show steering screen
    FC_VR_ACTION_HVAC_SHOW_FRONT_SEAT_SCREEN_INDEX,                 ///< show front seat screen
    FC_VR_ACTION_HVAC_SHOW_REAR_SEAT_SCREEN_INDEX,                  ///< show rear seat screen
    FC_VR_ACTION_HVAC_SHOW_LEXUS_CONCIERGE_SCREEN_INDEX,            ///< show lexus concierge screen
    FC_VR_ACTION_HVAC_SHOW_SEAT_OPERATION_SCREEN_INDEX,             ///< show seat operation screen
    FC_VR_ACTION_HVAC_SHOW_FRONT_SEAT_VENTI_SCREEN_INDEX,           ///< show front seat venti screen
    FC_VR_ACTION_HVAC_SHOW_REAR_SEAT_VENTI_SCREEN_INDEX,            ///< show rear seat venti screen
    FC_VR_ACTION_HVAC_SHOW_FRONT_AC_SCREEN_INDEX,                   ///< show front ac screen
    FC_VR_ACTION_HVAC_SHOW_REAR_AC_SCREEN_INDEX,                    ///< show rear ac screen
    FC_VR_ACTION_HVAC_SHOW_SEAT_SCREEN_INDEX,                       ///< show seat screen
    FC_VR_ACTION_HVAC_SHOW_EXAMPLE_INDEX                            ///< show example
};

extern const std::map<QString, int> VrActionHvacMap;

// ------------------------------Action Phone op ------------------------------------------

extern const QString FC_VR_ACTION_PHONE_DIAL_CALL;
extern const QString FC_VR_ACTION_PHONE_DIAL_CALL_NUM;
extern const QString FC_VR_ACTION_PHONE_DIAL_CALL_RECENT;
extern const QString FC_VR_ACTION_PHONE_DIAL_Call_SHORTRING;
extern const QString FC_VR_ACTION_PHONE_DIAL_REDIAL;
extern const QString FC_VR_ACTION_PHONE_SHOW_RECENT_CALL_LIST;
extern const QString FC_VR_ACTION_PHONE_SEND_DTMF_TONES;
extern const QString FC_VR_ACTION_PHONE_SHOW_CONTACT_LIST;
extern const QString FC_VR_ACTION_PHONE_SHOW_FAVORITE_CONTACT_LIST;
extern const QString FC_VR_ACTION_PHONE_SEND_MESSAGE;
extern const QString FC_VR_ACTION_PHONE_MUTE_CALL;
extern const QString FC_VR_ACTION_PHONE_MUTE_OFF;
extern const QString FC_VR_ACTION_PHONE_ADD_VOICE_TAG;
extern const QString FC_VR_ACTION_PHONE_GET_MESSAGE_DEATIL;
extern const QString FC_VR_ACTION_PHONE_GET_MESSAGE_STATE;
extern const QString FC_VR_ACTION_PHONE_STATE;
extern const QString FC_VR_ACTION_PHONE_PB_STATE;
extern const QString FC_VR_ACTION_PHONE_GET_MSGDETAIL_STATUSNOCHANGE;
extern const QString FC_VR_ACTION_PHONE_EXAMPLE;

// Action Phone operation index enum define
enum ACTION_PHONE_INDEX
{
    FC_VR_ACTION_PHONE_DIAL_CALL_INDEX = 0,                     ///< dial call
    FC_VR_ACTION_PHONE_DIAL_CALL_NUM_INDEX,                     ///< dial call num
    FC_VR_ACTION_PHONE_DIAL_CALL_RECENT_INDEX,                  ///< dial call recent
    FC_VR_ACTION_PHONE_DIAL_CALL_SHORTRING_INDEX,               ///< dial call shortring
    FC_VR_ACTION_PHONE_DIAL_REDIAL_INDEX,                       ///< dial redial
    FC_VR_ACTION_PHONE_SHOW_RECENT_CALL_LIST_INDEX,             ///< show recent call list
    FC_VR_ACTION_PHONE_SEND_DTMF_TONES_INDEX,                   ///< send DTMF tones
    FC_VR_ACTION_PHONE_SHOW_CONTACT_LIST_INDEX,                 ///< show contact list
    FC_VR_ACTION_PHONE_SHOW_FAVORITE_CONTACT_LIST_INDEX,        ///< show favorite contact list
    FC_VR_ACTION_PHONE_SEND_MESSAGE_INDEX,                      ///< send message
    FC_VR_ACTION_PHONE_MUTE_CALL_INDEX,                         ///< mute call
    FC_VR_ACTION_PHONE_MUTE_OFF_INDEX,                          ///< mute off
    FC_VR_ACTION_PHONE_ADD_VOICE_TAG_INDEX,                     ///< show add voice tag UI
    FC_VR_ACTION_PHONE_GET_MESSAGE_DEATIL_INDEX,                ///< get message detail
    FC_VR_ACTION_PHONE_GET_MESSAGE_STATE_INDEX,                 ///< get message state
    FC_VR_ACTION_PHONE_STATE_INDEX,                             ///< get phone state
    FC_VR_ACTION_PHONE_PB_STATE_INDEX,                          ///< get phone book state
    FC_VR_ACTION_PHONE_GET_MSGDETAIL_STATUSNOCHANGE_INDEX,      ///< get msg detai while status no change
    FC_VR_ACTION_PHONE_EXAMPLE_INDEX                            ///< an example
};

extern const std::map<QString, int> VrActionPhoneMap;

// ------------------------------Action apps op ------------------------------------------
extern const QString FC_VR_ACTION_APPS_LAUNCH;
extern const QString FC_VR_ACTION_APPS_EXAMPLE;

// action apps operation index enum define
enum ACTION_APPS_INDEX
{
    FC_VR_ACTION_APPS_LAUNCH_INDEX = 0,         ///< launch app
    FC_VR_ACTION_APPS_EXAMPLE_INDEX             ///< an example
};

extern const std::map<QString, int> VrActionAppsMap;

// ------------------------------Action Help op ------------------------------------------

extern const QString FC_VR_ACTION_HELP_SHOW_VOICE_SETTINGS_UI;
extern const QString FC_VR_ACTION_HELP_SHOW_LEXUS_INSIDER_UI;
extern const QString FC_VR_ACTION_HELP_SHOW_TUTORIALS_UI;
extern const QString FC_VR_ACTION_HELP_TRAINING_END_MSG;

// action help operation index enum define
enum ACTION_HELP_INDEX
{
    FC_VR_ACTION_HELP_SHOW_VOICE_SETTINGS_UI_INDEX = 0,         ///< show voice settings UI
    FC_VR_ACTION_HELP_SHOW_LEXUS_INSIDER_UI_INDEX,              ///< show lexus insider UI
    FC_VR_ACTION_HELP_SHOW_TUTORIALS_UI_INDEX,                   ///< show tutorial UI
    FC_VR_ACTION_HELP_SHOW_TRAINING_END_MSG_INDEX,              ///< show training end msg
    FC_VR_ACTION_HELP_MAX_INDEX
};

extern const std::map<QString, int> VrActionHelpMap;

// ------------------------------Action Weather op --------------------------------------

extern const QString FC_VR_ACTION_INFO_SHOW_CURRENT_WEATHER;
extern const QString FC_VR_ACTION_INFO_SHOW_NATIONAL_WEATHER;
extern const QString FC_VR_ACTION_INFO_SHOW_EXAMPLE;
//
enum ACTION_WEATHER_INDEX
{
    FC_VR_ACTION_INFO_SHOW_CURRENT_WEATHER_INDEX   =  0,
    FC_VR_ACTION_INFO_SHOW_NATIONAL_WEATHER_INDEX,
    FC_VR_ACTION_WEATHER_MAX_INDEX
};

extern const std::map<QString, int> VrActionWeatherMap;

// ------------------------------Action Navi op ------------------------------------------
extern const QString FC_VR_ACTION_NAVI_SHOW_POI_ICON;
extern const QString FC_VR_ACTION_NAVI_HIDE_POI_ICON;
extern const QString FC_VR_ACTION_NAVI_CALC_ROUTE;
extern const QString FC_VR_ACTION_NAVI_DEL_DESTINATION;
extern const QString FC_VR_ACTION_NAVI_SHOW_POI_ICON_NUM;
extern const QString FC_VR_ACTION_NAVI_ADD_TO_ROUTE;
extern const QString FC_VR_ACTION_SHOW_DESTINATION_ASSIST;

// action navi operation index enum define
enum ACTION_NAVI_INDEX
{
    FC_VR_ACTION_NAVI_SHOW_POI_ICON_INDEX = 0,                  ///< show poi icon
    FC_VR_ACTION_NAVI_HIDE_POI_ICON_INDEX,                      ///< hide poi icon
    FC_VR_ACTION_NAVI_CALC_ROUTE_INDEX,                         ///< calculate route
    FC_VR_ACTION_NAVI_DEL_DESTINATION_INDEX,                    ///< delete destination
    FC_VR_ACTION_NAVI_SHOW_POI_ICON_NUM_INDEX,                  ///< show poi icon number
    FC_VR_ACTION_NAVI_ADD_TO_ROUTE_INDEX,                       ///< add to route
    FC_VR_ACTION_SHOW_DESTINATION_ASSIST_INDEX,                 ///< call gbook assit
    FC_VR_ACTION_NAVI_MAX_INDEX
};

extern const std::map<QString, int> VrActionNaviMap;

#endif // VRCONST_H
/* EOF */
