#include "VRConst.h"

const int VR_ERROR_CODE = -1;
const int VR_DEFAULT_TASKID = -1;
const int VR_INVALID_ID = -100;
const int VR_COUNT_PROTECTION = 1000;
const u_int64_t VOICERECOG_IMPL_PROXY_CALL_ID_ZERO = 0;

const QString FC_VR_RECOGNITION_FAILED_STATE                  = QString("failed");
const QString FC_VR_RECOGNITION_ACTION_RESULT_FAILED          = FC_VR_RECOGNITION_FAILED_STATE;
const QString FC_VR_RECOGNITION_INVAILED_SOURCE_ID            = QString("0");
const QString FC_VR_RECOGNITION_NULL_STRING                                          = QString("");
const std::string FC_TELEPHONY_USERNAME_VR                                           = "VR";
const QString FC_VR_METER_COOPERATION_OFF_STRING                                     = QString("off");

const QString FC_VR_RESULT_DISPLAY_TAG                        = QString("display");
// display tag agent attribute name
const QString FC_VR_RESULT_DISPLAY_ATTR_AGENT                 = QString("agent");
// display tag content attribute name
const QString FC_VR_RESULT_DISPLAY_ATTR_CONTENT               = QString("content");
// agent tag name
const QString FC_VR_RESULT_AGENT_TAG                          = QString("agent");
// content tag name
const QString FC_VR_RESULT_CONTENT_TAG                        = QString("content");

const QString FC_VR_RESULT_ENGINETYPE_TAG                     = QString("engineType");
const QString FC_VR_RESULT_TYPE_TAG                           = QString("type");
const QString FC_VR_RESULT_STATE_TAG                          = QString("state");
const QString FC_VR_RESULT_VOLUME_TAG                         = QString("volume");
const QString FC_VR_RESULT_RESULT_TAG                         = QString("result");
const QString FC_VR_RESULT_PROMPT_TAG                         = QString("prompt");
const QString FC_VR_RESULT_LIST_TAG                           = QString("list");
const QString FC_VR_RESULT_LIST_ATTR_TYPE                     = QString("type");
const QString FC_VR_RESULT_ITEMS_TAG                          = QString("items");
const QString FC_VR_RESULT_DETAIL_TAG                         = QString("detail");
const QString FC_VR_RESULT_PHONETYPE_TAG                      = QString("phoneType");
const QString FC_VR_RESULT_PHONETYPE_TAG_AN                   = QString("phoneType");
const QString FC_VR_RESULT_MEEAGEBODY_TAG                     = QString("messagebody");
const QString FC_VR_RESULT_PHONENAME_VALUE_TAG                = QString("phonenamevalue");
const QString FC_VR_RESULT_HISTORYTYPE_TAG                    = QString("historytype");
const QString FC_VR_RESULT_TIMESTAMP_TAG                      = QString("timestamp");
const QString FC_VR_RESULT_ZONE_TAG                           = QString("zone");
const QString FC_VR_RESULT_STREET_TAG                         = QString("street");
const QString FC_VR_RESULT_HOUSENUMBER_TAG                    = QString("houseNumber");
const QString FC_VR_RESULT_DISTRICT_TAG                       = QString("district");
const QString FC_VR_RESULT_CITY_TAG                           = QString("city");
const QString FC_VR_RESULT_ADDRESS_TAG                        = QString("address");
const QString FC_VR_RESULT_CONTACT_NAME_TAG_AN                = QString("contactName");
const QString FC_VR_RESULT_PROMPTVALUE                        = QString("promptvalue");
const QString FC_VR_RESULT_LATITUDE_TAG                       = QString("latitude");
const QString FC_VR_RESULT_LONGITUDE_TAG                      = QString("longitude");
const QString FC_VR_RESULT_INDEX_TAG                          = QString("index");
const QString FC_VR_RESULT_MESSAGEID_TAG                      = QString("messageId");
const QString FC_VR_RESULT_PHRASE_TAG                         = QString("phrase");
const QString FC_VR_RESULT_STEP_TAG                           = QString("step");
const QString FC_VR_RESULT_TAG_TAG                            = QString("tag");
const QString FC_VR_RESULT_BODY_TAG                           = QString("body");
const QString FC_VR_RESULT_PHONENUMBER_TAG                    = QString("phonenumber");
const QString FC_VR_RESULT_MSGAVAILABLE_TAG                   = QString("msgavailable");
const QString FC_VR_RESULT_NEXTITEM_TAG                       = QString("nextitem");
const QString FC_VR_RESULT_PREVIOUSITEM_TAG                   = QString("previousitem");
const QString FC_VR_RESULT_CALLTYPE_TAG                       = QString("calltype");
const QString FC_VR_RESULT_VOLUME_STATUS_TAG                  = QString("volumeStatus");
const QString FC_VR_RESULT_ENABLE_TAG                         = QString("enable");
const QString FC_VR_RESULT_TONES_TAG                          = QString("tones");
const QString FC_VR_RESULT_PHONE_CONTACT_TYPE_NAME_TAG        = QString("contact_phone_type_name");
const QString FC_VR_RESULT_NBEST_TAG                          = QString("nbest");
const QString FC_VR_RESULT_ALIGNEDADDRESS_TAG                 = QString("alignedAddress");
const QString FC_VR_RESULT_UNIT_TAG                           = QString("unit");
const QString FC_VR_RESULT_METER_COOPERATION_TAG              = QString("meterCooperation");
const QString FC_VR_RESULT_IPOD_DISPLAY_TAG                   = QString("IpodDisplay");

// voicetag tag define as following
const QString FC_VR_RESULT_CONTACTNAME_TAG                    = QString("contactName");
const QString FC_VR_RESULT_CANDIDATA_ONE_NUM_TAG              = QString("candidata1Number");
const QString FC_VR_RESULT_CANDIDATA_TWO_NUM_TAG              = QString("candidata2Number");
const QString FC_VR_RESULT_CANDIDATA_THERE_NUM_TAG            = QString("candidata3Number");
const QString FC_VR_RESULT_CANDIDATA_FOUR_NUM_TAG             = QString("candidata4Number");
const QString FC_VR_RESULT_CANDIDATA_ONE_TYPE_TAG             = QString("candidata1Type");
const QString FC_VR_RESULT_CANDIDATA_TWO_TYPE_TAG             = QString("candidata2Type");
const QString FC_VR_RESULT_CANDIDATA_THERE_TYPE_TAG           = QString("candidata3Type");
const QString FC_VR_RESULT_CANDIDATA_FOUR_TYPE_TAG            = QString("candidata4Type");

// Uniform tag as following:
// name
const QString FC_VR_RESULT_NAME_TAG                           = QString("name");
const QString FC_VR_RESULT_APPNAME_TAG                        = QString("appName");
const QString FC_VR_RESULT_APP_NAME_TAG                       = QString("app_name");
const QString FC_VR_RESULT_FORMAL_NAME_TAG                    = QString("formal_name");
const QString FC_VR_RESULT_CONTACT_NAME_TAG                   = QString("contact_name");
const QString FC_VR_RESULT_DIGITS_TAG                         = QString("digits");
const QString FC_VR_RESULT_NUMBER_TAG                         = QString("number");
const QString FC_VR_RESULT_ARTIST_NAME_TAG                    = QString("artist_name");
const QString FC_VR_RESULT_ALBUM_NAME_TAG                     = QString("album_name");
const QString FC_VR_RESULT_SONG_NAME_TAG                      = QString("song_name");
const QString FC_VR_RESULT_PLAYLIST_NAME_TAG                  = QString("playlist_name");
// const QString FC_VR_RESULT_CONTACTNAME_TAG                 = QString("contactName");
const QString FC_VR_RESULT_POI_CATEGORY_NAME_TAG              = QString("POI_category_name");

// title
const QString FC_VR_RESULT_TITLE_TAG                          = QString("screenTitle");

// command
const QString FC_VR_RESULT_COMMAND_TAG                        = QString("command");
const QString FC_VR_RESULT_GENRE_NAME_TAG                     = QString("genre_name");
const QString FC_VR_RESULT_STATION_NAME_TAG                   = QString("station_name");
const QString FC_VR_AGENT_ATTRI_COMMON_VALUE                  = QString("Common");
// agent tag value
const QString FC_VR_AGENT_VALUE_TOP_MENU                      = QString("topmenu");
const QString FC_VR_AGENT_VALUE_NAVI                          = QString("navi");
const QString FC_VR_AGENT_VALUE_PHONE                         = QString("phone");
const QString FC_VR_AGENT_VALUE_MEDIA                         = QString("media");
const QString FC_VR_AGENT_VALUE_APPS                          = QString("apps");
const QString FC_VR_AGENT_VALUE_SENDTONE                      = QString("sendtone");
const QString FC_VR_AGENT_VALUE_CLIMATE                       = QString("climate");
const QString FC_VR_AGENT_VALUE_DICTATION                     = QString("dictation");
const QString FC_VR_AGENT_VALUE_VOICETAG                      = QString("voicetag");
const QString FC_VR_AGENT_VALUE_HELP                          = QString("help");
const QString FC_VR_AGENT_VALUE_ADAPTION                      = QString("adaptation");
const QString FC_VR_AGENT_VALUE_TUNER                         = QString("tuner");
const QString FC_VR_AGENT_VALUE_INFORMATION                   = QString("information");

// display tag content attribute value
const QString FC_VR_RESULT_COMMON_VR_STATE                    = QString("VRState");
const QString FC_VR_RESULT_COMMON_VOLUME                      = QString("Volume");
const QString FC_VR_RESULT_COMMON_POP_MSG                     = QString("PopMsg");
const QString FC_VR_RESULT_COMMON_SCRENN_DISPLAY              = QString("ScreenDisplay");
const QString FC_VR_RESULT_COMMON_SHOW_POP_MSG                = QString("ShowPopupMessage");
const QString FC_VR_RESULT_COMMON_DISMISS_POP_MSG             = QString("DismissPopupMessage");
const QString FC_VR_RESULT_COMMON_FOCUSLISTITEM               = QString("FocusListItem");
const QString FC_VR_RESULT_COMMON_QUIT_VRAPP                  = QString("QuitVRApp");
const QString FC_VR_RESULT_COMMON_HINTS_DISPLAY               = QString("HintsDisplay");
const QString FC_VR_RESULT_COMMON_TSL_STATE                   = QString("TSLState");
const QString FC_VR_RESULT_COMMON_ENDTASK_STATE               = QString("EndTaskStatus");
const QString FC_VR_RESULT_DISTANCE_UNIT                      = QString("distance_unit");
const QString FC_VR_RESULT_UPDATE_ERROR_ONS                   = QString("UpdateErrorONS");

// Vr quit const string
const QString FC_VR_QUIT_STATUS                               = QString("quit");

const int FC_VR_PARSE_XML_RESULT_ERROR = -1;
const int FC_VR_PARSE_XML_RESULT_OK    = 0;

// ACTION USING
const QString FC_VR_RESULT_ALL_ACTION_TAG                     = QString("action");
const QString FC_VR_RESULT_ACTION_OP                          = QString("op");

// The action for my own use
const QString FC_VR_ACTION_RETURN_ENGINE                         = QString(
                                                                        "<action-result agent = \"%1\"  op = \"%2\""
                                                                            " errcode = \"1\" >"
                                                                         "</action-result>"
                                                                      );
const QString FC_VR_ACTION_RETURN_ENGINE_MEDIA                   = QString("media");
const QString FC_VR_ACTION_RETURN_ENGINE_PLAY                    = QString("play");
const QString FC_VR_ACTION_RETURN_ENGINE_PLAY_BY_GENRE           = QString("playByGenre");
const QString FC_VR_ACTION_RETURN_ENGINE_PLAY_BY_NAME            = QString("playByName");
const QString FC_VR_ACTION_RETURN_ENGINE_PLAY_BY_PRESET          = QString("playByPreset");
const QString FC_VR_ACTION_RETURN_ENGINE_CLIMATE                 = QString("climate");
const QString FC_VR_ACTION_RETURN_ENGINE_SHOW                    = QString("showScreen");
const QString FC_VR_ACTION_RETURN_ENGINE_PHONE                   = QString("phone");
const QString FC_VR_ACTION_RETURN_ENGINE_DIAL                    = QString("dial");
const QString FC_VR_ACTION_RETURN_ENGINE_APPS                    = QString("apps");
const QString FC_VR_ACTION_RETURN_ENGINE_HELP                    = QString("help");
const QString FC_VR_ACTION_RETURN_ENGINE_WEATHER                 = QString("info");
const QString FC_VR_ACTION_RETURN_ENGINE_NAVI                    = QString("navi");

// nbest tag value
const QString FC_VR_NBEST_TAG_VALUE_TRUE                             = QString("true");

// ------------------------------TopMenu VRState(content tag value) ------------------------------------------
// Common
const QString FC_VR_STATE_TOP_MENU_IDLE                        = QString("topmenu_idle");
const QString FC_VR_STATE_TOP_MENU_MORE_HINTS                  = QString("topmenu_more_hints");
// EU
const QString FC_VR_STATE_EU_TOP_MENU_IDLE                     = QString("eu_topmenu_idle");
const QString FC_VR_STATE_EU_TOP_MENU_HELP                     = QString("eu_topmenu_help");
// NA
const QString FC_VR_STATE_NA_TOP_MENU_IDLE                     = QString("na_topmenu_idle");
const QString FC_VR_STATE_NA_TOP_MENU_MORE_HINTS               = QString("na_topmenu_more_hints");

// If you want to build index for adding tag, please refer as following:
const QString FC_VR_STATE_TOP_MENU_EXAMPLE                     = QString("example");


const std::map<QString, int>::value_type top_menu_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_STATE_TOP_MENU_IDLE, FC_VR_STATE_TOP_MENU_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_TOP_MENU_MORE_HINTS, FC_VR_STATE_TOP_MENU_MORE_HINTS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_TOP_MENU_IDLE, FC_VR_STATE_EU_TOP_MENU_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_TOP_MENU_HELP, FC_VR_STATE_EU_TOP_MENU_HELP_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_TOP_MENU_IDLE, FC_VR_STATE_NA_TOP_MENU_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_TOP_MENU_MORE_HINTS, FC_VR_STATE_NA_TOP_MENU_MORE_HINTS_INDEX),
    // If you want to build index for adding tag, please refer as following:
    std::map<QString, int>::value_type(FC_VR_STATE_TOP_MENU_EXAMPLE, FC_VR_STATE_TOP_MENU_EXAMPLE_INDEX)
};
const std::map<QString, int> TopMenuVrStateMap(top_menu_init_value, top_menu_init_value+FC_VR_STATE_TOP_MENU_MAX_INDEX);


// ------------------------------Navi VRState(content tag value) ------------------------------------------
// Common
const QString FC_VR_STATE_NAVI_IDLE                        = QString("navi_idle");
const QString FC_VR_STATE_NAVI_MORE_HINTS                  = QString("navi_more_hints");
const QString FC_VR_STATE_NAVI_SPEAK_ENTRUES_ADDRESS       = QString("navi_speak_entries_address");
const QString FC_VR_STATE_NAVI_SPEAK_CITY                  = QString("navi_speak_city");
const QString FC_VR_STATE_NAVI_SPEAK_HOUSE_NUMBER          = QString("navi_speak_house_number");
const QString FC_VR_STATE_NAVI_SPEAK_STATE                 = QString("navi_speak_state");
const QString FC_VR_STATE_NAVI_SPEAK_STREET                = QString("navi_speak_street");
const QString FC_VR_STATE_NAVI_ADDRESS_CONFIRM             = QString("navi_address_confirm");
const QString FC_VR_STATE_NAVI_ADDRESS_STREET_SELECT       = QString("navi_address_street_select");
const QString FC_VR_STATE_NAVI_ADDRESS_DISTRICT_SELECT     = QString("navi_address_district_select");
const QString FC_VR_STATE_NAVI_ADDRESS_HOUSE_SELECT        = QString("navi_address_house_select");
const QString FC_VR_STATE_NAVI_ADDRESS_CITY_SELECT         = QString("navi_address_city_select");
const QString FC_VR_STATE_NAVI_ADDRESS_STATE_SELECT        = QString("navi_address_state_select");
const QString FC_VR_STATE_NAVI_ADDRESS_RESULT_SELECT       = QString("navi_address_result_select");
const QString FC_VR_STATE_NAVI_SPEAK_POI                   = QString("navi_speak_poi");
const QString FC_VR_STATE_NAVI_POI_LIST_SELECT             = QString("navi_poi_list_select");
const QString FC_VR_STATE_NAVI_POI_ALONG_ROUTE_SELECT      = QString("navi_poi_along_route_select");
const QString FC_VR_STATE_NAVI_POI_NEAR_DEST_SELECT        = QString("navi_poi_near_dest_select");
const QString FC_VR_STATE_NAVI_POI_CONFIRM                 = QString("navi_poi_confirm");
const QString FC_VR_STATE_NAVI_CONFIRM_DESTINATION         = QString("navi_confirm_destination");
const QString FC_VR_STATE_NAVI_CONFIRM_ASSIST              = QString("navi_confirm_assist");
const QString FC_VR_STATE_NAVI_DESTINATION_SELECT          = QString("navi_destination_select");
const QString FC_VR_STATE_NAVI_CONFIRM_DELETE_DESTINATION  = QString("navi_confirm_delete_destination");
const QString FC_VR_STATE_NAVI_DESTINATION_DELETE_SELECT   = QString("navi_destination_delete_select");
const QString FC_VR_STATE_NAVI_SET_ROUTE                   = QString("navi_set_route");
const QString FC_VR_STATE_NAVI_SET_ROUTE_CONFIRM           = QString("navi_set_route_confirm");
const QString FC_VR_STATE_NAVI_POI_CATEGORY_CANDIDATES     = QString("navi_poi_category_candidates");
const QString FC_VR_STATE_NAVI_POI_SHOW_CANDIDATES         = QString("navi_poi_show_candidates");
const QString FC_VR_STATE_NAVI_POI_HIDE_CANDIDATES         = QString("navi_poi_hide_candidates");

// China
const QString FC_VR_STATE_CN_NAVI_SPEAK_CITY               = QString("cn_navi_speak_city");
const QString FC_VR_STATE_CN_NAVI_SPEAK_DISTRICT           = QString("cn_navi_speak_district");
const QString FC_VR_STATE_CN_NAVI_SPEAK_HOUSE_NUMBER       = QString("cn_navi_speak_house_number");
const QString FC_VR_STATE_CN_NAVI_SPEAK_STREET             = QString("cn_navi_speak_street");
const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_WEBSEARCH_START             = QString("cn_navi_poi_category_websearch_start");
const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_SELECT               = QString("cn_navi_poi_category_result_select");
const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_WEB_SELECT           = QString("cn_navi_poi_category_result_web_select");
const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_LOCAL_SELECT         = QString("cn_navi_poi_category_result_local_select");
const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_ALONG_ROUTE_SELECT   = QString("cn_navi_poi_category_result_along_route_select");
const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_NEAR_DEST_SELECT     = QString("cn_navi_poi_category_result_near_dest_select");
const QString FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_SELECT                   = QString("cn_navi_poi_name_result_select");
const QString FC_VR_STATE_CN_NAVI_POI_NAME_WEB_SEARCH_START                = QString("cn_navi_poi_name_web_search_start");
const QString FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_LOCAL_SELECT             = QString("cn_navi_poi_name_result_local_select");
const QString FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_WEB_SELECT               = QString("cn_navi_poi_name_result_web_select");
const QString FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_INCITY_SELECT            = QString("cn_navi_poi_name_result_incity_select");
const QString FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_INCITY_SELECT        = QString("cn_navi_poi_category_result_incity_select");
const QString FC_VR_STATE_NAVI_CONFIRM_CALL_ASSIST                         = QString("navi_confirm_call_assist");
// If you want to build index for adding tag, please refer as following:
const QString FC_VR_STATE_NAVI_EXAMPLE                     = QString("example");



const std::map<QString, int>::value_type navi_init_value[] =
{
    // Common
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_IDLE, FC_VR_STATE_NAVI_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_MORE_HINTS, FC_VR_STATE_NAVI_MORE_HINTS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_SPEAK_ENTRUES_ADDRESS, FC_VR_STATE_NAVI_SPEAK_ENTRUES_ADDRESS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_SPEAK_CITY, FC_VR_STATE_NAVI_SPEAK_CITY_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_SPEAK_HOUSE_NUMBER, FC_VR_STATE_NAVI_SPEAK_HOUSE_NUMBER_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_SPEAK_STATE, FC_VR_STATE_NAVI_SPEAK_STATE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_SPEAK_STREET, FC_VR_STATE_NAVI_SPEAK_STREET_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_ADDRESS_CONFIRM, FC_VR_STATE_NAVI_ADDRESS_CONFIRM_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_ADDRESS_STREET_SELECT, FC_VR_STATE_NAVI_ADDRESS_STREET_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_ADDRESS_DISTRICT_SELECT, FC_VR_STATE_NAVI_ADDRESS_DISTRICT_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_ADDRESS_HOUSE_SELECT, FC_VR_STATE_NAVI_ADDRESS_HOUSE_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_ADDRESS_CITY_SELECT, FC_VR_STATE_NAVI_ADDRESS_CITY_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_ADDRESS_STATE_SELECT, FC_VR_STATE_NAVI_ADDRESS_STATE_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_ADDRESS_RESULT_SELECT, FC_VR_STATE_NAVI_ADDRESS_RESULT_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_SPEAK_POI, FC_VR_STATE_NAVI_SPEAK_POI_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_POI_LIST_SELECT, FC_VR_STATE_NAVI_POI_LIST_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_POI_ALONG_ROUTE_SELECT, FC_VR_STATE_NAVI_POI_ALONG_ROUTE_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_POI_NEAR_DEST_SELECT, FC_VR_STATE_NAVI_POI_NEAR_DEST_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_POI_CONFIRM, FC_VR_STATE_NAVI_POI_CONFIRM_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_CONFIRM_DESTINATION, FC_VR_STATE_NAVI_CONFIRM_DESTINATION_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_CONFIRM_ASSIST, FC_VR_STATE_NAVI_CONFIRM_ASSIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_DESTINATION_SELECT, FC_VR_STATE_NAVI_DESTINATION_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_CONFIRM_DELETE_DESTINATION, FC_VR_STATE_NAVI_CONFIRM_DELETE_DESTINATION_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_DESTINATION_DELETE_SELECT, FC_VR_STATE_NAVI_DESTINATION_DELETE_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_SET_ROUTE, FC_VR_STATE_NAVI_SET_ROUTE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_SET_ROUTE_CONFIRM, FC_VR_STATE_NAVI_SET_ROUTE_CONFIRM_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_POI_CATEGORY_CANDIDATES, FC_VR_STATE_NAVI_POI_CATEGORY_CANDIDATES_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_POI_SHOW_CANDIDATES, FC_VR_STATE_NAVI_POI_SHOW_CANDIDATES_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_POI_HIDE_CANDIDATES, FC_VR_STATE_NAVI_POI_HIDE_CANDIDATES_INDEX),

    // China
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_SPEAK_CITY, FC_VR_STATE_CN_NAVI_SPEAK_CITY_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_SPEAK_DISTRICT, FC_VR_STATE_CN_NAVI_SPEAK_DISTRICT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_SPEAK_HOUSE_NUMBER, FC_VR_STATE_CN_NAVI_SPEAK_HOUSE_NUMBER_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_SPEAK_STREET, FC_VR_STATE_CN_NAVI_SPEAK_STREET_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_POI_CATEGORY_WEBSEARCH_START, FC_VR_STATE_CN_NAVI_POI_CATEGORY_WEBSEARCH_START_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_SELECT, FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_WEB_SELECT, FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_WEB_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_LOCAL_SELECT, FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_LOCAL_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_ALONG_ROUTE_SELECT, FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_ALONG_ROUTE_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_NEAR_DEST_SELECT, FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_NEAR_DEST_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_SELECT, FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_POI_NAME_WEB_SEARCH_START, FC_VR_STATE_CN_NAVI_POI_NAME_WEB_SEARCH_START_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_LOCAL_SELECT, FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_LOCAL_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_WEB_SELECT, FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_WEB_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_INCITY_SELECT, FC_VR_STATE_CN_NAVI_POI_NAME_RESULT_INCITY_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_INCITY_SELECT, FC_VR_STATE_CN_NAVI_POI_CATEGORY_RESULT_INCITY_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_CONFIRM_CALL_ASSIST, FC_VR_STATE_NAVI_CONFIRM_CALL_ASSIST_INDEX),

    // If you want to build index for adding tag, please refer as following:
    std::map<QString, int>::value_type(FC_VR_STATE_NAVI_EXAMPLE, FC_VR_STATE_NAVI_EXAMPLE_INDEX)
};
const std::map<QString, int> NaviVrStateMap(navi_init_value, navi_init_value+FC_VR_STATE_NAVI_MAX_INDEX);



// ------------------------------Phone VRState(content tag value) ------------------------------------------
// Common
const QString FC_VR_STATE_PHONE_IDLE                                        = QString("phone_idle");
const QString FC_VR_STATE_PHONE_MORE_HINTS                                  = QString("phone_more_hints");
const QString FC_VR_STATE_PHONE_SPEAK_PHONE_NUMBER                          = QString("phone_speak_phone_number");
const QString FC_VR_STATE_PHONE_SPEAK_DIGITS                                = QString("phone_speak_digits");
const QString FC_VR_STATE_PHONE_CONFIRM_CALL_NUMBER                         = QString("phone_confirm_call_number");
const QString FC_VR_STATE_PHONE_SPEAK_CONTACT                               = QString("phone_speak_contact");
const QString FC_VR_STATE_PHONE_CONTACT_SELECT                              = QString("phone_contact_select");
const QString FC_VR_STATE_PHONE_CONFIRM_CALL_CONTACT                        = QString("phone_confirm_call_contact");
const QString FC_VR_STATE_PHONE_TYPE_SELECT                                 = QString("phone_contact_type_select");
const QString FC_VR_STATE_PHONE_CONFIRM_CALLBACK_NUMBER                     = QString("phone_confirm_callback_number");
const QString FC_VR_STATE_PHONE_CONFIRM_CALLBACK_CONTACT                    = QString("phone_confirm_callback_contact");
const QString FC_VR_STATE_PHONE_CONFIRM_REDIAL_NUMBER                       = QString("phone_confirm_redial_number");
const QString FC_VR_STATE_PHONE_CONFIRM_REDIAL_CONTACT                      = QString("phone_confirm_redial_contact");
// EU
const QString FC_VR_STATE_EU_PHONE_NUMBER_SPEAK                             = QString("eu_phone_number_speak");
const QString FC_VR_STATE_EU_PHONE_DIGITS_SPEAK                             = QString("eu_phone_digits_speak");
const QString FC_VR_STATE_EU_PHONE_ANYSPEECH_SPEAK                          = QString("eu_phone_anyspeech_speak");
const QString FC_VR_STATE_EU_PHONE_ENTRY_SPEAK                              = QString("eu_phone_entry_speak");
const QString FC_VR_STATE_EU_PHONE_NAME_SELECT                              = QString("eu_phone_name_select");
const QString FC_VR_STATE_EU_PHONE_CATEGORY_SELECT                          = QString("eu_phone_category_select");
const QString FC_VR_STATE_EU_PHONE_CONTACT_SELECT                           = QString("eu_phone_contact_select");
const QString FC_VR_STATE_EU_PHONE_HELP_LIST                                = QString("eu_phone_help_list");
// NA
const QString FC_VR_STATE_NA_PHONE_IDLE                                     = QString("na_phone_idle");
const QString FC_VR_STATE_NA_PHONE_IN_CALL                                  = QString("na_phone_in_call");
const QString FC_VR_STATE_NA_PHONE_IN_MESSAGE                               = QString("na_phone_in_message");
const QString FC_VR_STATE_NA_PHONE_MORE_HINTS                               = QString("na_phone_more_hints");
const QString FC_VR_STATE_NA_PHONE_CONTACT_SELECT_NAME                      = QString("na_phone_contact_select_name");
const QString FC_VR_STATE_NA_PHONE_CONTACT_SELECT_NUMBER                    = QString("na_phone_contact_select_number");
const QString FC_VR_STATE_NA_PHONE_CONTACT_SELECT_DIGITS                    = QString("na_phone_contact_select_digits");
const QString FC_VR_STATE_NA_PHONE_SPEAK_PHONE_NUMBER                       = QString("na_phone_speak_phone_number");
const QString FC_VR_STATE_NA_PHONE_SPEAK_DIGITS                             = QString("na_phone_speak_digits");
const QString FC_VR_STATE_NA_PHONE_CONFIRM_CALL_NUMBER                      = QString("na_phone_confirm_call_number");
const QString FC_VR_STATE_NA_PHONE_SPEAK_CONTACT                            = QString("na_phone_speak_contact");
const QString FC_VR_STATE_NA_PHONE_CONFIRM_CALL_CONTACT                     = QString("na_phone_confirm_call_contact");
const QString FC_VR_STATE_NA_PHONE_CONTACT_TYPE_SELECT                      = QString("na_phone_contact_type_select");
const QString FC_VR_STATE_NA_PHONE_SELECT_NAME_MATCHES_CALL_SMS             = QString("na_phone_select_name_matches_call_sms");
const QString FC_VR_STATE_NA_PHONE_CONFIRM_REPLY_SEND_MSG                   = QString("na_phone_confirm_reply_send_msg");
const QString FC_VR_STATE_NA_PHONE_SEARCH_CONTACTS_SMS                      = QString("na_phone_search_contacts_sms");
const QString FC_VR_STATE_NA_PHONE_CONFIRM_SMS_RECIPIENT                    = QString("na_phone_confirm_sms_recipient");
const QString FC_VR_STATE_NA_PHONE_CALL_SPEAK_NAME_NUMBER                   = QString("na_phone_call_speak_name_number");
const QString FC_VR_STATE_NA_PHONE_DICTATE_SMS                              = QString("na_phone_dictate_sms");
const QString FC_VR_STATE_NA_PHONE_LIST_RECENT_CALLS                        = QString("na_phone_list_recent_calls");
const QString FC_VR_STATE_NA_PHONE_LIST_MESSAGES                            = QString("na_phone_list_messages");
const QString FC_VR_STATE_NA_PHONE_SELECT_QUICK_REPLY                       = QString("na_phone_select_quick_reply");
const QString FC_VR_STATE_NA_PHONE_ONE_CALL_CONTACT_MESSAGE_SELECTED        = QString("na_phone_one_call_contact_message_selected");
const QString FC_VR_STATE_NA_PHONE_ONE_MESSAGE_SELECTED                     = QString("na_phone_one_message_selected");
const QString FC_VR_STATE_NA_PHONE_SELECT_NAME_AND_TYPE_MATCHES_CALL_SMS    = QString("na_phone_select_name_and_type_matches_call_sms");
const QString FC_VR_STATE_NA_PHONE_SEND_DTMF                                = QString("na_phone_send_dtmf");
// If you want to build index for adding tag, please refer as following:
const QString FC_VR_STATE_PHONE_EXAMPLE                     = QString("example");

const std::map<QString, int>::value_type phone_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_IDLE, FC_VR_STATE_PHONE_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_MORE_HINTS, FC_VR_STATE_PHONE_MORE_HINTS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_SPEAK_PHONE_NUMBER, FC_VR_STATE_PHONE_SPEAK_PHONE_NUMBER_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_SPEAK_DIGITS, FC_VR_STATE_PHONE_SPEAK_DIGITS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_CONFIRM_CALL_NUMBER, FC_VR_STATE_PHONE_CONFIRM_CALL_NUMBER_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_SPEAK_CONTACT, FC_VR_STATE_PHONE_SPEAK_CONTACT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_CONTACT_SELECT, FC_VR_STATE_PHONE_CONTACT_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_CONFIRM_CALL_CONTACT, FC_VR_STATE_PHONE_CONFIRM_CALL_CONTACT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_TYPE_SELECT, FC_VR_STATE_PHONE_TYPE_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_CONFIRM_CALLBACK_NUMBER, FC_VR_STATE_PHONE_CONFIRM_CALLBACK_NUMBER_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_CONFIRM_CALLBACK_CONTACT, FC_VR_STATE_PHONE_CONFIRM_CALLBACK_CONTACT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_CONFIRM_REDIAL_NUMBER, FC_VR_STATE_PHONE_CONFIRM_REDIAL_NUMBER_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_CONFIRM_REDIAL_CONTACT, FC_VR_STATE_PHONE_CONFIRM_REDIAL_CONTACT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_PHONE_NUMBER_SPEAK, FC_VR_STATE_EU_PHONE_NUMBER_SPEAK_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_PHONE_DIGITS_SPEAK, FC_VR_STATE_EU_PHONE_DIGITS_SPEAK_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_PHONE_ANYSPEECH_SPEAK, FC_VR_STATE_EU_PHONE_ANYSPEECH_SPEAK_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_PHONE_ENTRY_SPEAK, FC_VR_STATE_EU_PHONE_ENTRY_SPEAK_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_PHONE_NAME_SELECT, FC_VR_STATE_EU_PHONE_NAME_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_PHONE_CATEGORY_SELECT, FC_VR_STATE_EU_PHONE_CATEGORY_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_PHONE_CONTACT_SELECT, FC_VR_STATE_EU_PHONE_CONTACT_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_PHONE_HELP_LIST, FC_VR_STATE_EU_PHONE_HELP_LIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_IDLE, FC_VR_STATE_NA_PHONE_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_IN_CALL, FC_VR_STATE_NA_PHONE_IN_CALL_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_IN_MESSAGE, FC_VR_STATE_NA_PHONE_IN_MESSAGE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_MORE_HINTS, FC_VR_STATE_NA_PHONE_MORE_HINTS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_CONTACT_SELECT_NAME, FC_VR_STATE_NA_PHONE_CONTACT_SELECT_NAME_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_CONTACT_SELECT_NUMBER, FC_VR_STATE_NA_PHONE_CONTACT_SELECT_NUMBER_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_CONTACT_SELECT_DIGITS, FC_VR_STATE_NA_PHONE_CONTACT_SELECT_DIGITS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_SPEAK_PHONE_NUMBER, FC_VR_STATE_NA_PHONE_SPEAK_PHONE_NUMBER_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_SPEAK_DIGITS, FC_VR_STATE_NA_PHONE_SPEAK_DIGITS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_CONFIRM_CALL_NUMBER, FC_VR_STATE_NA_PHONE_CONFIRM_CALL_NUMBER_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_SPEAK_CONTACT, FC_VR_STATE_NA_PHONE_SPEAK_CONTACT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_CONFIRM_CALL_CONTACT, FC_VR_STATE_NA_PHONE_CONFIRM_CALL_CONTACT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_CONTACT_TYPE_SELECT, FC_VR_STATE_NA_PHONE_CONTACT_TYPE_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_SELECT_NAME_MATCHES_CALL_SMS, FC_VR_STATE_NA_PHONE_SELECT_NAME_MATCHES_CALL_SMS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_CONFIRM_REPLY_SEND_MSG, FC_VR_STATE_NA_PHONE_CONFIRM_REPLY_SEND_MSG_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_SEARCH_CONTACTS_SMS, FC_VR_STATE_NA_PHONE_SEARCH_CONTACTS_SMS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_CONFIRM_SMS_RECIPIENT, FC_VR_STATE_NA_PHONE_CONFIRM_SMS_RECIPIENT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_CALL_SPEAK_NAME_NUMBER, FC_VR_STATE_NA_PHONE_CALL_SPEAK_NAME_NUMBER_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_DICTATE_SMS, FC_VR_STATE_NA_PHONE_DICTATE_SMS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_LIST_RECENT_CALLS, FC_VR_STATE_NA_PHONE_LIST_RECENT_CALLS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_LIST_MESSAGES, FC_VR_STATE_NA_PHONE_LIST_MESSAGES_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_SELECT_QUICK_REPLY, FC_VR_STATE_NA_PHONE_SELECT_QUICK_REPLY_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_ONE_CALL_CONTACT_MESSAGE_SELECTED, FC_VR_STATE_NA_PHONE_ONE_CALL_CONTACT_MESSAGE_SELECTED_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_ONE_MESSAGE_SELECTED, FC_VR_STATE_NA_PHONE_ONE_MESSAGE_SELECTED_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_SELECT_NAME_AND_TYPE_MATCHES_CALL_SMS, FC_VR_STATE_NA_PHONE_SELECT_NAME_AND_TYPE_MATCHES_CALL_SMS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_PHONE_SEND_DTMF, FC_VR_STATE_NA_PHONE_SEND_DTMF_INDEX),
    // If you want to build index for adding tag, please refer as following:
    std::map<QString, int>::value_type(FC_VR_STATE_PHONE_EXAMPLE, FC_VR_STATE_PHONE_EXAMPLE_INDEX)
};
const std::map<QString, int> PhoneVrStateMap(phone_init_value, phone_init_value+FC_VR_STATE_PHONE_MAX_INDEX);


// ------------------------------Media VRState(content tag value) ------------------------------------------
// Common
const QString FC_VR_STATE_MEDIA_IDLE                                            = QString("media_idle");
const QString FC_VR_STATE_MEDIA_MORE_HINTS                                      = QString("media_more_hints");
const QString FC_VR_STATE_MEDIA_MUSIC_SPEAK_ARTIST_NAME                         = QString("media_music_speak_artist_name");
const QString FC_VR_STATE_MEDIA_MUSIC_ARTIST_SELECT                             = QString("media_music_artist_select");
const QString FC_VR_STATE_MEDIA_MUSIC_SPEAK_ALBUM_NAME                          = QString("media_music_speak_album_name");
const QString FC_VR_STATE_MEDIA_MUSIC_ALBUM_SELECT                              = QString("media_music_album_select");
const QString FC_VR_STATE_MEDIA_MUSIC_SPEAK_SONG_NAME                           = QString("media_music_speak_song_name");
const QString FC_VR_STATE_MEDIA_MUSIC_SONG_SELECT                               = QString("media_music_song_select");
const QString FC_VR_STATE_MEDIA_MUSIC_PLAY_LIST_SELECT                          = QString("media_music_play_list_select");
const QString FC_VR_STATE_MEDIA_MUSIC_SELECT_SONG_FROM_PLAYLIST                 = QString("media_music_select_song_from_playlist");
const QString FC_VR_STATE_MEDIA_RADIO_SPEAK_RADIO_FREQUENCY                     = QString("media_radio_speak_radio_frequency");
const QString FC_VR_STATE_MEDIA_RADIO_SPEAK_PRESET_NUMBER                       = QString("media_radio_speak_preset_number");
// EU
const QString FC_VR_STATE_EU_MEDIA_GENRE_NAME_SPEAK                            = QString("eu_media_genre_name_speak");
const QString FC_VR_STATE_EU_MEDIA_GENRE_NAME_SELECT                           = QString("eu_media_genre_name_select");
const QString FC_VR_STATE_EU_MEDIA_GENRE_CANDIDATE_SELECT                      = QString("eu_media_genre_candidate_select");
const QString FC_VR_STATE_EU_MEDIA_ARTIST_NAME_SPEAK                           = QString("eu_media_artist_name_speak");
const QString FC_VR_STATE_EU_MEDIA_ARTIST_NAME_SELECT                          = QString("eu_media_artist_name_select");
const QString FC_VR_STATE_EU_MEDIA_ARTIST_CANDIDATE_SELECT                     = QString("eu_media_artist_candidate_select");
const QString FC_VR_STATE_EU_MEDIA_ALBUM_NAME_SPEAK                            = QString("eu_media_album_name_speak");
const QString FC_VR_STATE_EU_MEDIA_ALBUM_NAME_SELECT                           = QString("eu_media_album_name_select");
const QString FC_VR_STATE_EU_MEDIA_ALBUM_CANDIDATE_SELECT                      = QString("eu_media_album_candidate_select");
const QString FC_VR_STATE_EU_MEDIA_TITLE_NAME_SPEAK                            = QString("eu_media_title_name_speak");
const QString FC_VR_STATE_EU_MEDIA_TITLE_NAME_SELECT                           = QString("eu_media_title_name_select");
const QString FC_VR_STATE_EU_MEDIA_TITLE_MUSIC_SELECT                          = QString("eu_media_title_music_select");
const QString FC_VR_STATE_EU_MEDIA_PLAYLIST_NAME_SPEAK                         = QString("eu_media_playlist_name_speak");
const QString FC_VR_STATE_EU_MEDIA_PLAYLIST_NAME_SELECT                        = QString("eu_media_playlist_name_select");
const QString FC_VR_STATE_EU_MEDIA_PLAYLIST_MUSIC_SELECT                       = QString("eu_media_playlist_music_select");
const QString FC_VR_STATE_EU_MEDIA_ONESHOT_NAME_SPEAK                          = QString("eu_media_oneshot_name_speak");
const QString FC_VR_STATE_EU_MEDIA_ONESHOT_ARTIST_SELECT                       = QString("eu_media_oneshot_artist_select");
const QString FC_VR_STATE_EU_MEDIA_ONESHOT_MUSIC_SELECT                        = QString("eu_media_oneshot_music_select");
const QString FC_VR_STATE_EU_MEDIA_HELP_LIST                                   = QString("eu_media_help_list");
// NA
const QString FC_VR_STATE_NA_MEDIA_IDLE                                        = QString("na_media_idle");
const QString FC_VR_STATE_NA_MEDIA_MORE_HINTS                                  = QString("na_media_more_hints");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_ARTIST_NAME                     = QString("na_media_music_speak_artist_name");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_ALBUM_NAME                      = QString("na_media_music_speak_album_name");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_SONG_NAME                       = QString("na_media_music_speak_song_name");
const QString FC_VR_STATE_NA_MEDIA_NBEST_SELECT                                = QString("na_media_music_nbest_select");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_PLAY_LIST_SELECT                      = QString("na_media_music_play_list_select");
const QString FC_VR_STATE_NA_MEDIA_RADIO_SPEAK_RADIO_FREQUENCY                 = QString("na_media_radio_speak_radio_frequency");
const QString FC_VR_STATE_NA_MEDIA_RADIO_SPEAK_PRESET_NUMBER                   = QString("na_media_radio_speak_preset_number");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ARTIST_FOR_ALBUM                = QString("na_media_music_which_artist_for_album");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ARTIST_FOR_SONG                 = QString("na_media_music_which_artist_for_song");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_A_CATEGORY                      = QString("na_media_music_speak_a_category");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ALBUM_FOR_SONG                  = QString("na_media_music_which_album_for_song");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_ALBUM_SONG_SELECT                     = QString("na_media_music_album_song_select");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_ARTIST_ALBUM_SELECT                   = QString("na_media_music_artist_album_select");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_ARTIST_SONG_SELECT                    = QString("na_media_music_artist_song_select");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_AUDIOBOOKS_NAME                 = QString("na_media_music_speak_audiobooks_name");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_COMPOSER_NAME                   = QString("na_media_music_speak_composer_name");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_COMPOSER_SONG_SELECT                  = QString("na_media_music_composer_song_select");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_GENRE_NAME                      = QString("na_media_music_speak_genre_name");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_GENRE_ARTIST_SELECT                   = QString("na_media_music_genre_artist_select");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_PLAY_LIST_SONG_SELECT                 = QString("na_media_music_play_list_song_select");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_PODCASTNAME                     = QString("na_media_music_speak_podcastname");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_SOURCE_SELECT                         = QString("na_media_music_source_select");
const QString FC_VR_STATE_NA_MEDIA_MUSIC_PODCAST_ITEM_SELECT                   = QString("na_media_music_podcast_item_select");
const QString FC_VR_STATE_NA_MEDIA_RADIO_GENRE_SELECT                          = QString("na_media_radio_genre_select");
const QString FC_VR_STATE_NA_MEDIA_RADIO_SATELLITE_CHANNEL_SELECT              = QString("na_media_radio_satellite_channel_select");
// If you want to build index for adding tag, please refer as following:
const QString FC_VR_STATE_MEDIA_EXAMPLE                           = QString("example");


const std::map<QString, int>::value_type media_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_STATE_MEDIA_IDLE, FC_VR_STATE_MEDIA_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_MEDIA_MORE_HINTS, FC_VR_STATE_MEDIA_MORE_HINTS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_MEDIA_MUSIC_SPEAK_ARTIST_NAME, FC_VR_STATE_MEDIA_MUSIC_SPEAK_ARTIST_NAME_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_MEDIA_MUSIC_ARTIST_SELECT, FC_VR_STATE_MEDIA_MUSIC_ARTIST_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_MEDIA_MUSIC_SPEAK_ALBUM_NAME, FC_VR_STATE_MEDIA_MUSIC_SPEAK_ALBUM_NAME_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_MEDIA_MUSIC_ALBUM_SELECT, FC_VR_STATE_MEDIA_MUSIC_ALBUM_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_MEDIA_MUSIC_SPEAK_SONG_NAME, FC_VR_STATE_MEDIA_MUSIC_SPEAK_SONG_NAME_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_MEDIA_MUSIC_SONG_SELECT, FC_VR_STATE_MEDIA_MUSIC_SONG_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_MEDIA_MUSIC_PLAY_LIST_SELECT, FC_VR_STATE_MEDIA_MUSIC_PLAY_LIST_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_MEDIA_MUSIC_SELECT_SONG_FROM_PLAYLIST, FC_VR_STATE_MEDIA_MUSIC_SELECT_SONG_FROM_PLAYLIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_MEDIA_RADIO_SPEAK_RADIO_FREQUENCY, FC_VR_STATE_MEDIA_RADIO_SPEAK_RADIO_FREQUENCY_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_MEDIA_RADIO_SPEAK_PRESET_NUMBER, FC_VR_STATE_MEDIA_RADIO_SPEAK_PRESET_NUMBER_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_GENRE_NAME_SPEAK, FC_VR_STATE_EU_MEDIA_GENRE_NAME_SPEAK_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_GENRE_NAME_SELECT, FC_VR_STATE_EU_MEDIA_GENRE_NAME_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_GENRE_CANDIDATE_SELECT, FC_VR_STATE_EU_MEDIA_GENRE_CANDIDATE_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_ARTIST_NAME_SPEAK, FC_VR_STATE_EU_MEDIA_ARTIST_NAME_SPEAK_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_ARTIST_NAME_SELECT, FC_VR_STATE_EU_MEDIA_ARTIST_NAME_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_ARTIST_CANDIDATE_SELECT, FC_VR_STATE_EU_MEDIA_ARTIST_CANDIDATE_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_ALBUM_NAME_SPEAK, FC_VR_STATE_EU_MEDIA_ALBUM_NAME_SPEAK_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_ALBUM_NAME_SELECT, FC_VR_STATE_EU_MEDIA_ALBUM_NAME_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_ALBUM_CANDIDATE_SELECT, FC_VR_STATE_EU_MEDIA_ALBUM_CANDIDATE_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_TITLE_NAME_SPEAK, FC_VR_STATE_EU_MEDIA_TITLE_NAME_SPEAK_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_TITLE_NAME_SELECT, FC_VR_STATE_EU_MEDIA_TITLE_NAME_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_TITLE_MUSIC_SELECT, FC_VR_STATE_EU_MEDIA_TITLE_MUSIC_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_PLAYLIST_NAME_SPEAK, FC_VR_STATE_EU_MEDIA_PLAYLIST_NAME_SPEAK_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_PLAYLIST_NAME_SELECT, FC_VR_STATE_EU_MEDIA_PLAYLIST_NAME_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_PLAYLIST_MUSIC_SELECT, FC_VR_STATE_EU_MEDIA_PLAYLIST_MUSIC_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_ONESHOT_NAME_SPEAK, FC_VR_STATE_EU_MEDIA_ONESHOT_NAME_SPEAK_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_ONESHOT_ARTIST_SELECT, FC_VR_STATE_EU_MEDIA_ONESHOT_ARTIST_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_ONESHOT_MUSIC_SELECT, FC_VR_STATE_EU_MEDIA_ONESHOT_MUSIC_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_MEDIA_HELP_LIST, FC_VR_STATE_EU_MEDIA_HELP_LIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_IDLE, FC_VR_STATE_NA_MEDIA_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MORE_HINTS, FC_VR_STATE_NA_MEDIA_MORE_HINTS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_ARTIST_NAME, FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_ARTIST_NAME_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_ALBUM_NAME, FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_ALBUM_NAME_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_SONG_NAME, FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_SONG_NAME_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_NBEST_SELECT, FC_VR_STATE_NA_MEDIA_NBEST_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_PLAY_LIST_SELECT, FC_VR_STATE_NA_MEDIA_MUSIC_PLAY_LIST_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_RADIO_SPEAK_RADIO_FREQUENCY, FC_VR_STATE_NA_MEDIA_RADIO_SPEAK_RADIO_FREQUENCY_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_RADIO_SPEAK_PRESET_NUMBER, FC_VR_STATE_NA_MEDIA_RADIO_SPEAK_PRESET_NUMBER_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ARTIST_FOR_ALBUM, FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ARTIST_FOR_ALBUM_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ARTIST_FOR_SONG, FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ARTIST_FOR_SONG_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_A_CATEGORY, FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_A_CATEGORY_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ALBUM_FOR_SONG, FC_VR_STATE_NA_MEDIA_MUSIC_WHICH_ALBUM_FOR_SONG_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_ALBUM_SONG_SELECT, FC_VR_STATE_NA_MEDIA_MUSIC_ALBUM_SONG_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_ARTIST_ALBUM_SELECT, FC_VR_STATE_NA_MEDIA_MUSIC_ARTIST_ALBUM_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_ARTIST_SONG_SELECT, FC_VR_STATE_NA_MEDIA_MUSIC_ARTIST_SONG_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_AUDIOBOOKS_NAME, FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_AUDIOBOOKS_NAME_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_COMPOSER_NAME, FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_COMPOSER_NAME_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_COMPOSER_SONG_SELECT, FC_VR_STATE_NA_MEDIA_MUSIC_COMPOSER_SONG_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_GENRE_NAME, FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_GENRE_NAME_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_GENRE_ARTIST_SELECT, FC_VR_STATE_NA_MEDIA_MUSIC_GENRE_ARTIST_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_PLAY_LIST_SONG_SELECT, FC_VR_STATE_NA_MEDIA_MUSIC_PLAY_LIST_SONG_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_PODCASTNAME, FC_VR_STATE_NA_MEDIA_MUSIC_SPEAK_PODCASTNAME_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_SOURCE_SELECT, FC_VR_STATE_NA_MEDIA_MUSIC_SOURCE_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_MUSIC_PODCAST_ITEM_SELECT, FC_VR_STATE_NA_MEDIA_MUSIC_PODCAST_ITEM_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_RADIO_GENRE_SELECT, FC_VR_STATE_NA_MEDIA_RADIO_GENRE_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_MEDIA_RADIO_SATELLITE_CHANNEL_SELECT, FC_VR_STATE_NA_MEDIA_RADIO_SATELLITE_CHANNEL_SELECT_INDEX),
    // If you want to build index for adding tag, please refer as following:
    std::map<QString, int>::value_type(FC_VR_STATE_MEDIA_EXAMPLE, FC_VR_STATE_MEDIA_EXAMPLE_INDEX)
};
const std::map<QString, int> MediaVrStateMap(media_init_value, media_init_value+FC_VR_STATE_MEDIA_MAX_INDEX);



// ------------------------------Apps VRState(content tag value) ------------------------------------------
// Common
const QString FC_VR_STATE_APPS_IDLE                             = QString("apps_idle");
const QString FC_VR_STATE_APPS_MORE_HINTS                       = QString("apps_more_hints");
const QString FC_VR_STATE_APPS_APPS_LIST_SELECT                 = QString("apps_apps_list_select");
const QString FC_VR_STATE_APPS_APP_CANDIDATES_SELECT            = QString("apps_app_candidates_select");
// NA
const QString FC_VR_STATE_NA_APPS_IDLE                           = QString("na_apps_idle");
const QString FC_VR_STATE_NA_APPS_MORE_HINTS                     = QString("na_apps_more_hints");
const QString FC_VR_STATE_NA_APPS_APPS_LIST_SELECT               = QString("na_apps_apps_list_select");
const QString FC_VR_STATE_NA_APPS_APP_CANDIDATES_SELECT          = QString("na_apps_app_candidates_select");
// If you want to build index for adding tag, please refer as following:
const QString FC_VR_STATE_APPS_EXAMPLE                     = QString("example");

const std::map<QString, int>::value_type apps_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_STATE_APPS_IDLE, FC_VR_STATE_APPS_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_APPS_MORE_HINTS, FC_VR_STATE_APPS_MORE_HINTS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_APPS_APPS_LIST_SELECT, FC_VR_STATE_APPS_APPS_LIST_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_APPS_APP_CANDIDATES_SELECT, FC_VR_STATE_APPS_APP_CANDIDATES_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_APPS_IDLE, FC_VR_STATE_NA_APPS_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_APPS_MORE_HINTS, FC_VR_STATE_NA_APPS_MORE_HINTS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_APPS_APPS_LIST_SELECT, FC_VR_STATE_NA_APPS_APPS_LIST_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_APPS_APP_CANDIDATES_SELECT, FC_VR_STATE_NA_APPS_APP_CANDIDATES_SELECT_INDEX),
    // If you want to build index for adding tag, please refer as following:
    std::map<QString, int>::value_type(FC_VR_STATE_APPS_EXAMPLE, FC_VR_STATE_APPS_EXAMPLE_INDEX)
};
const std::map<QString, int> AppsVrStateMap(apps_init_value, apps_init_value+FC_VR_STATE_APPS_MAX_INDEX);


// ------------------------------SendTones VRState(content tag value) ------------------------------------------
const QString FC_VR_STATE_SENDTONE_SPEAK_TONES                              = QString("sendtone_speak_tones");
const QString FC_VR_STATE_SENDTONE_CONFIRM_TONES                            = QString("sendtone_confirm_tones");
// If you want to build index for adding tag, please refer as following:
const QString FC_VR_STATE_SENDTONE_EXAMPLE                     = QString("example");

const std::map<QString, int>::value_type sendtone_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_STATE_SENDTONE_SPEAK_TONES, FC_VR_STATE_SENDTONE_SPEAK_TONES_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_SENDTONE_CONFIRM_TONES, FC_VR_STATE_SENDTONE_CONFIRM_TONES_INDEX),
    // If you want to build index for adding tag, please refer as following:
    std::map<QString, int>::value_type(FC_VR_STATE_SENDTONE_EXAMPLE, FC_VR_STATE_SENDTONE_EXAMPLE_INDEX)
};
const std::map<QString, int> SendToneVrStateMap(sendtone_init_value, sendtone_init_value+FC_VR_STATE_SENDTONE_MAX_INDEX);

// ------------------------------VoiceTag VRState(content tag value) ------------------------------------------
const QString FC_VR_STATE_VOICETAG_IDLE                       = QString("voicetag_idle");
const QString FC_VR_STATE_VOICETAG_CONTACT_SELECT             = QString("voicetag_contact_select");
const QString FC_VR_STATE_VOICETAG_DETAIL_SELECT              = QString("voicetag_detail_select");

const QString FC_VR_STATE_VOICETAG_ERR_TAG_NONE               = QString("voicetag_err_tag_none");
const QString FC_VR_STATE_VOICETAG_ERR_PHONE_NOT_REGISTER     = QString("voicetag_err_phone_not_register");
const QString FC_VR_STATE_VOICETAG_ERR_PHONE_NOT_CONNECTED    = QString("voicetag_err_phone_not_connected");
const QString FC_VR_STATE_VOICETAG_EXIT_IDLE                  = QString("voicetag_exit_idle");
const QString FC_VR_STATE_VOICETAG_EXIT_NAME                  = QString("voicetag_exit_name");
const QString FC_VR_STATE_VOICETAG_EXIT_TYPE                  = QString("voicetag_exit_type");

// If you want to build index for adding tag, please refer as following:
const QString FC_VR_STATE_VOICETAG_EXAMPLE                     = QString("example");

const std::map<QString, int>::value_type voicetag_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_STATE_VOICETAG_IDLE, FC_VR_STATE_VOICETAG_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_VOICETAG_CONTACT_SELECT, FC_VR_STATE_VOICETAG_CONTACT_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_VOICETAG_DETAIL_SELECT, FC_VR_STATE_VOICETAG_DETAIL_SELECT_INDEX),

    std::map<QString, int>::value_type(FC_VR_STATE_VOICETAG_ERR_TAG_NONE, FC_VR_STATE_VOICETAG_ERR_TAG_NONE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_VOICETAG_ERR_PHONE_NOT_REGISTER, FC_VR_STATE_VOICETAG_ERR_PHONE_NOT_REGISTER_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_VOICETAG_ERR_PHONE_NOT_CONNECTED, FC_VR_STATE_VOICETAG_ERR_PHONE_NOT_CONNECTED_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_VOICETAG_EXIT_IDLE, FC_VR_STATE_VOICETAG_EXIT_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_VOICETAG_EXIT_NAME, FC_VR_STATE_VOICETAG_EXIT_NAME_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_VOICETAG_EXIT_TYPE, FC_VR_STATE_VOICETAG_EXIT_TYPE_INDEX),

    // If you want to build index for adding tag, please refer as following:
    std::map<QString, int>::value_type(FC_VR_STATE_VOICETAG_EXAMPLE, FC_VR_STATE_VOICETAG_EXAMPLE_INDEX)
};
const std::map<QString, int> VoiceTagVrStateMap(voicetag_init_value, voicetag_init_value+FC_VR_STATE_VOICETAG_MAX_INDEX);


// ------------------------------Climate VRState(content tag value) ------------------------------------------
// Common
const QString FC_VR_STATE_CLIMATE_IDLE                           = QString("climate_idle");
const QString FC_VR_STATE_CLIMATE_MORE_HINTS                     = QString("climate_more_hints");
// NA
const QString FC_VR_STATE_NA_CLIMATE_IDLE                        = QString("na_climate_idle");
const QString FC_VR_STATE_NA_CLIMATE_MORE_HINTS                  = QString("na_climate_more_hints");
const QString FC_VR_STATE_NA_CLIMATE_SET_THE_TEMPERATURE         = QString("na_climate_set_the_temperature");
const QString FC_VR_STATE_NA_CLIMATE_SET_THE_FAN_SPEED           = QString("na_climate_set_the_fan_speed");
// If you want to build index for adding tag, please refer as following:
const QString FC_VR_STATE_CLIMATE_EXAMPLE                     = QString("example");

const std::map<QString, int>::value_type climate_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_STATE_CLIMATE_IDLE, FC_VR_STATE_CLIMATE_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_CLIMATE_MORE_HINTS, FC_VR_STATE_CLIMATE_MORE_HINTS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_CLIMATE_IDLE, FC_VR_STATE_NA_CLIMATE_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_CLIMATE_MORE_HINTS, FC_VR_STATE_NA_CLIMATE_MORE_HINTS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_CLIMATE_SET_THE_TEMPERATURE, FC_VR_STATE_NA_CLIMATE_SET_THE_TEMPERATURE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_CLIMATE_SET_THE_FAN_SPEED, FC_VR_STATE_NA_CLIMATE_SET_THE_FAN_SPEED_INDEX),
    // If you want to build index for adding tag, please refer as following:
    std::map<QString, int>::value_type(FC_VR_STATE_CLIMATE_EXAMPLE, FC_VR_STATE_CLIMATE_EXAMPLE_INDEX)
};
const std::map<QString, int> ClimateVrStateMap(climate_init_value, climate_init_value+FC_VR_STATE_CLIMATE_MAX_INDEX);


// ------------------------------Help VRState(content tag value) ------------------------------------------
const QString FC_VR_STATE_NA_HELP_TUTORIAL_CONFIRMATION       = QString("na_help_tutorial_confirmation");
const QString FC_VR_STATE_NA_HELP_TRAIN_VOICE_RECOGNITION     = QString("na_help_train_voice_recognition");
const QString FC_VR_STATE_INFORMATION_SELECT                  = QString("information_select");
const QString FC_VR_STATE_INFORMATION_IDLE                    = QString("information_idle");
const QString FC_VR_STATE_INFORMATION_MORE_HINTS              = QString("information_more_hints");

const QString FC_VR_STATE_NA_HELP_MORE_HINTS                     = QString("na_help_more_hints");

// If you want to build index for adding tag, please refer as following:
const QString FC_VR_STATE_HELP_EXAMPLE                     = QString("example");

const std::map<QString, int>::value_type help_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_STATE_NA_HELP_TUTORIAL_CONFIRMATION, FC_VR_STATE_NA_HELP_TRAIN_VOICE_RECOGNITION_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_HELP_TRAIN_VOICE_RECOGNITION, FC_VR_STATE_NA_HELP_TRAIN_VOICE_RECOGNITION_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_INFORMATION_SELECT, FC_VR_STATE_INFORMATION_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_INFORMATION_IDLE, FC_VR_STATE_INFORMATION_IDLE_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_INFORMATION_MORE_HINTS, FC_VR_STATE_INFORMATION_MORE_HINTS_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_NA_HELP_MORE_HINTS, FC_VR_STATE_NA_HELP_MORE_HINTS_INDEX),
    // If you want to build index for adding tag, please refer as following:
    std::map<QString, int>::value_type(FC_VR_STATE_HELP_EXAMPLE, FC_VR_STATE_HELP_EXAMPLE_INDEX)
};
const std::map<QString, int> HelpVrStateMap(help_init_value, help_init_value+FC_VR_STATE_HELP_MAX_INDEX);


// ------------------------------Adaption VRState(content tag value) ------------------------------------------
const QString FC_VR_STATE_NA_ADAPTION                        = QString("na_adaptation");
// If you want to build index for adding tag, please refer as following:
const QString FC_VR_STATE_ADAPTION_EXAMPLE                   = QString("example");

const std::map<QString, int>::value_type adaption_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_STATE_NA_ADAPTION, FC_VR_STATE_NA_ADAPTION_INDEX),
    // If you want to build index for adding tag, please refer as following:
    std::map<QString, int>::value_type(FC_VR_STATE_ADAPTION_EXAMPLE, FC_VR_STATE_ADAPTION_EXAMPLE_INDEX)
};
const std::map<QString, int> AdaptionVrStateMap(adaption_init_value, adaption_init_value+FC_VR_STATE_ADAPTION_MAX_INDEX);

// ------------------------------Dictation VRState(content tag value) ------------------------------------------
// NA
const QString FC_VR_STATE_NA_DICTATION_CITIES_KEYBOARD           = QString("na_dictation_cities_keyboard");
const QString FC_VR_STATE_NA_DICTATION_GENERIC_KEYBOARD          = QString("na_dictation_generic_keyboard");
const QString FC_VR_STATE_NA_DICTATION_HFD_KEYBOARD              = QString("na_dictation_hfd_keyboard");
const QString FC_VR_STATE_NA_DICTATION_MESSAGE                   = QString("na_dictation_message");
const QString FC_VR_STATE_NA_DICTATION_MUSIC_KEYBOARD            = QString("na_dictation_music_keyboard");
const QString FC_VR_STATE_NA_DICTATION_NAVIGATION_KEYBOARD       = QString("na_dictation_navigation_keyboard");
const QString FC_VR_STATE_NA_DICTATION_POI_KEYBOARD              = QString("na_dictation_poi_keyboard");
const QString FC_VR_STATE_NA_DICTATION_STATES_KEYBOARD           = QString("na_dictation_states_keyboard");
const QString FC_VR_STATE_NA_DICTATION_STREETS_KEYBOARD          = QString("na_dictation_streets_keyboard");

// ------------------------------Tuner VRState(content tag value) ------------------------------------------
// EU
const QString FC_VR_STATE_EU_TUNER_STATION_NAME_INPUT            = QString("eu_tuner_station_name_input");
const QString FC_VR_STATE_EU_TUNER_STATION_NAME_SELECT           = QString("eu_tuner_station_name_select");
const QString FC_VR_STATE_EU_TUNER_STATION_SELECT                = QString("eu_tuner_station_select");
const QString FC_VR_STATE_EU_TUNER_HELP_LIST                     = QString("eu_tuner_help_list");
// If you want to build index for adding tag, please refer as following:
const QString FC_VR_STATE_EU_TUNER_EXAMPLE                       = QString("example");

const std::map<QString, int>::value_type tuner_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_STATE_EU_TUNER_STATION_NAME_INPUT, FC_VR_STATE_EU_TUNER_STATION_NAME_INPUT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_TUNER_STATION_NAME_SELECT, FC_VR_STATE_EU_TUNER_STATION_NAME_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_TUNER_STATION_SELECT, FC_VR_STATE_EU_TUNER_STATION_SELECT_INDEX),
    std::map<QString, int>::value_type(FC_VR_STATE_EU_TUNER_HELP_LIST, FC_VR_STATE_EU_TUNER_HELP_LIST_INDEX),
    // If you want to build index for adding tag, please refer as following:
    std::map<QString, int>::value_type(FC_VR_STATE_EU_TUNER_EXAMPLE, FC_VR_STATE_EU_TUNER_EXAMPLE_INDEX)
};
const std::map<QString, int> TunerVrStateMap(tuner_init_value, tuner_init_value+FC_VR_STATE_EU_TUNER_MAX_INDEX);

// ---------------------------Button operation value define(Service using)
const QString FC_VR_BTNOPER_VALUE_SELECT_ONE          = QString("select_one");
const QString FC_VR_BTNOPER_VALUE_SELECT_TWO          = QString("select_two");
const QString FC_VR_BTNOPER_VALUE_SELECT_THREE        = QString("select_three");
const QString FC_VR_BTNOPER_VALUE_SELECT_FOUR         = QString("select_four");
const QString FC_VR_BTNOPER_VALUE_SELECT_FIVE         = QString("select_five");
const QString FC_VR_BTNOPER_VALUE_SELECT_SIX          = QString("select_six");
const QString FC_VR_BTNOPER_VALUE_PHONE               = QString("phone");
const QString FC_VR_BTNOPER_VALUE_NAVI                = QString("navi");
const QString FC_VR_BTNOPER_VALUE_APPS                = QString("apps");
const QString FC_VR_BTNOPER_VALUE_AUDIO               = QString("audio");
const QString FC_VR_BTNOPER_VALUE_CLIMATE             = QString("climate");
const QString FC_VR_BTNOPER_VALUE_HELP                = QString("help");
const QString FC_VR_BTNOPER_VALUE_INFO                = QString("info");
const QString FC_VR_BTNOPER_VALUE_GO_BACK             = QString("go_back");
const QString FC_VR_BTNOPER_VALUE_START_OVER          = QString("start_over");
const QString FC_VR_BTNOPER_VALUE_PAUSE               = QString("pause");
const QString FC_VR_BTNOPER_VALUE_RESUME              = QString("resume");
const QString FC_VR_BTNOPER_VALUE_CANCEL              = QString("cancel");
const QString FC_VR_BTNOPER_VALUE_MORE_HINTS          = QString("more_hints");
const QString FC_VR_BTNOPER_VALUE_PRE_PAGE            = QString("previous_page");
const QString FC_VR_BTNOPER_VALUE_NEXT_PAGE           = QString("next_page");
const QString FC_VR_BTNOPER_VALUE_FIRST_PAGE          = QString("first_page");
const QString FC_VR_BTNOPER_VALUE_END_PAGE            = QString("end_page");
const QString FC_VR_BTNOPER_VALUE_YES                 = QString("yes");
const QString FC_VR_BTNOPER_VALUE_NO                  = QString("no");
const QString FC_VR_BTNOPER_VALUE_OK                  = QString("ok");
const QString FC_VR_BTNOPER_VALUE_START               = QString("start");
const QString FC_VR_BTNOPER_VALUE_BEGINNING           = QString("beginning");
const QString FC_VR_BTNOPER_VALUE_END                 = QString("end");
const QString FC_VR_BTNOPER_VALUE_GO_DIRECTLY         = QString("go_directly");
const QString FC_VR_BTNOPER_VALUE_ADD_TO_ROUTE        = QString("add_to_route");
const QString FC_VR_BTNOPER_VALUE_CALL                = QString("call");
const QString FC_VR_BTNOPER_VALUE_REPLY               = QString("reply");
const QString FC_VR_BTNOPER_VALUE_SEND_MESSAGE        = QString("send_message");
const QString FC_VR_BTNOPER_VALUE_NEXT                = QString("next");
const QString FC_VR_BTNOPER_VALUE_PREVIOUS            = QString("previous");
const QString FC_VR_BTNOPER_VALUE_RETRY               = QString("retry");
const QString FC_VR_BTNOPER_VALUE_TUTORIALS           = QString("tutorials");
const QString FC_VR_BTNOPER_VALUE_VOICE_TRAINING      = QString("voice_training");
const QString FC_VR_BTNOPER_VALUE_ALONG_ROUTE         = QString("along_route");
const QString FC_VR_BTNOPER_VALUE_NEAR_DESTINATION    = QString("near_destination");
const QString FC_VR_BTNOPER_VALUE_NEAR_HERE           = QString("near_here");
const QString FC_VR_BTNOPER_VALUE_ALONG_MY_ROUTE      = QString("along_my_route");
const QString FC_VR_BTNOPER_VALUE_ALONG_THIS_ROUTE    = QString("along_this_route");
const QString FC_VR_BTNOPER_VALUE_ALONG_A_SAVED_ROUTE = QString("along_a_saved_route");
const QString FC_VR_BTNOPER_VALUE_ALBUM               = QString("album");
const QString FC_VR_BTNOPER_VALUE_ARTIST              = QString("artist");
const QString FC_VR_BTNOPER_VALUE_SONG                = QString("song");
const QString FC_VR_BTNOPER_VALUE_COMPOSE             = QString("composer");
const QString FC_VR_BTNOPER_VALUE_GENRE               = QString("genre");
const QString FC_VR_BTNOPER_VALUE_PODCASE             = QString("podcast");
const QString FC_VR_BTNOPER_VALUE_PLAY_LIST           = QString("playlist");
const QString FC_VR_BTNOPER_VALUE_AUDIOBOOK           = QString("audiobook");
const QString FC_VR_BTNOPER_VALUE_CANDIDATE1_NUM2     = QString("candidate1_num2");
const QString FC_VR_BTNOPER_VALUE_CANDIDATE1_NUM3     = QString("candidate1_num3");
const QString FC_VR_BTNOPER_VALUE_CANDIDATE1_NUM4     = QString("candidate1_num4");
const QString FC_VR_BTNOPER_VALUE_CANDIDATE2          = QString("candidate2");
const QString FC_VR_BTNOPER_VALUE_CANDIDATE3          = QString("candidate3");
const QString FC_VR_BTNOPER_VALUE_CANDIDATE_NUM2      = QString("candidate_num2");
const QString FC_VR_BTNOPER_VALUE_CANDIDATE_NUM3      = QString("candidate_num3");
const QString FC_VR_BTNOPER_VALUE_CANDIDATE_NUM4      = QString("candidate_num4");
const QString FC_VR_BTNOPER_VALUE_HARD_KEY_OFF_HOOK_SHORT_PRESS  = QString("hard_key_off_hook_short_press");
const QString FC_VR_BTNOPER_VALUE_HARD_KEY_OFF_HOOK_LONG_PRESS   = QString("hard_key_off_hook_long_press");
const QString FC_VR_BTNOPER_VALUE_HARD_KEY_TEL_SHORT_PRESS       = QString("hard_key_tel_short_press");
const QString FC_VR_BTNOPER_VALUE_HARD_KEY_TEL_LONG_PRESS        = QString("hard_key_tel_long_press");
const QString FC_VR_BTNOPER_VALUE_DO_NOT_TELL_ME_AGAIN           = QString("do_not_tell_me_again");
const QString FC_VR_BTNOPER_VALUE_SET_PVR_FLAG                   = QString("set_pvr_flag");
const QString FC_VR_BTNOPER_VALUE_PTT_HARD_KEY_SHORT_PRESS       = QString("ptt_hard_key_short_press");
const QString FC_VR_BTNOPER_VALUE_PTT_HARD_KEY_LONG_PRESS        = QString("ptt_hard_key_long_press");
const QString FC_VR_BTNOPER_VALUE_BACK_LONG_PRESS                = QString("back_long_press");
const QString FC_VR_BTNOPER_VALUE_BACK_SHORT_PRESS               = QString("back_short_press");
const QString FC_VR_BTNOPER_VALUE_STOP_READING                   = QString("stop_reading");

const QString FC_VR_BTNOPER_VALUE_HARD_KEY_ENTER_LONG_PRESS      = QString("hard_key_enter_long_press");
const QString FC_VR_BTNOPER_VALUE_HARD_KEY_ENTER_SHORT_PRESS     = QString("hard_key_enter_short_press");

const QString FC_VR_BTNOPER_VALUE_DEBUG_INPUT_ON                 = QString("Debug_Input_On");
const QString FC_VR_BTNOPER_VALUE_DEBUG_INPUT_OFF                = QString("Debug_Input_Off");
const QString FC_VR_BTNOPER_VALUE_DEBUG_OUTPUT_ON                = QString("Debug_Output_On");
const QString FC_VR_BTNOPER_VALUE_DEBUG_OUTPUT_OFF               = QString("Debug_Output_Off");

const QString FC_VR_BTNOPER_VALUE_WEB_SEARCH                     = QString("web_search");

const QString FC_VR_BTNOPER_VALUE_METER_HARD_KEY_BACK_SHORT_PRESS = QString("meter_hard_key_back_short_press");
const QString FC_VR_BTNOPER_VALUE_METER_HARD_KEY_BACK_LONG_PRESS  = QString("meter_hard_key_back_long_press");

const QString FC_VR_BTNOPER_VALUE_HARD_KEY_ENTER_NORMAL_PRESS      = QString("hard_key_enter_normal_press");
const QString FC_VR_BTNOPER_VALUE_METER_HARD_KEY_BACK_NORMAL_PRESS = QString("meter_hard_key_back_normal_press");
const QString FC_VR_BTNOPER_VALUE_PTT_HARD_SHORT_PRESS_SPECIAL     = QString("ptt_hard_key_short_press_special");
const QString FC_VR_BTNOPER_VALUE_HARD_KEY_CANCEL_VR               = QString("hard_key_cancel_vr");

const QString FC_VR_BTNOPER_VALUE_PTT_HARD_KEY_PRESS_SPECIAL_IN_ENDTASKSTATUS   = QString("ptt_hard_key_press_special_in_endtaskstatus");

// vr inner using
const QString FC_VR_BTNOPER_VALUE_SETTING_VOICE_TRAINING_START     = QString("setting_voice_training_start");

const std::map<int, QString>::value_type button_init_value[] =
{
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Select_One, FC_VR_BTNOPER_VALUE_SELECT_ONE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Select_Two, FC_VR_BTNOPER_VALUE_SELECT_TWO),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Select_Three, FC_VR_BTNOPER_VALUE_SELECT_THREE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Select_Four, FC_VR_BTNOPER_VALUE_SELECT_FOUR),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Select_Five, FC_VR_BTNOPER_VALUE_SELECT_FIVE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Select_Six, FC_VR_BTNOPER_VALUE_SELECT_SIX),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Phone, FC_VR_BTNOPER_VALUE_PHONE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Navi, FC_VR_BTNOPER_VALUE_NAVI),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Apps, FC_VR_BTNOPER_VALUE_APPS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Audio, FC_VR_BTNOPER_VALUE_AUDIO),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Climate, FC_VR_BTNOPER_VALUE_CLIMATE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Help, FC_VR_BTNOPER_VALUE_HELP),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Info, FC_VR_BTNOPER_VALUE_INFO),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Go_Back, FC_VR_BTNOPER_VALUE_GO_BACK),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Start_Over, FC_VR_BTNOPER_VALUE_START_OVER),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Pause, FC_VR_BTNOPER_VALUE_PAUSE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Resume, FC_VR_BTNOPER_VALUE_RESUME),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Cancel, FC_VR_BTNOPER_VALUE_CANCEL),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_More_Hints, FC_VR_BTNOPER_VALUE_MORE_HINTS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Pre_Page, FC_VR_BTNOPER_VALUE_PRE_PAGE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Next_Page, FC_VR_BTNOPER_VALUE_NEXT_PAGE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_First_Page, FC_VR_BTNOPER_VALUE_FIRST_PAGE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_End_Page, FC_VR_BTNOPER_VALUE_END_PAGE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Yes, FC_VR_BTNOPER_VALUE_YES),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_No, FC_VR_BTNOPER_VALUE_NO),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Ok, FC_VR_BTNOPER_VALUE_OK),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Start, FC_VR_BTNOPER_VALUE_START),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Beginning, FC_VR_BTNOPER_VALUE_BEGINNING),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_End, FC_VR_BTNOPER_VALUE_END),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Go_Directly, FC_VR_BTNOPER_VALUE_GO_DIRECTLY),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Add_To_Route, FC_VR_BTNOPER_VALUE_ADD_TO_ROUTE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Call, FC_VR_BTNOPER_VALUE_CALL),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Reply, FC_VR_BTNOPER_VALUE_REPLY),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Send_Message, FC_VR_BTNOPER_VALUE_SEND_MESSAGE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Next, FC_VR_BTNOPER_VALUE_NEXT),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Previous, FC_VR_BTNOPER_VALUE_PREVIOUS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Retry, FC_VR_BTNOPER_VALUE_RETRY),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Tutorials, FC_VR_BTNOPER_VALUE_TUTORIALS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Voice_Training, FC_VR_BTNOPER_VALUE_VOICE_TRAINING),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Along_Route, FC_VR_BTNOPER_VALUE_ALONG_ROUTE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Near_Destination, FC_VR_BTNOPER_VALUE_NEAR_DESTINATION),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Near_Here, FC_VR_BTNOPER_VALUE_NEAR_HERE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Along_My_Route, FC_VR_BTNOPER_VALUE_ALONG_MY_ROUTE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Along_This_Road, FC_VR_BTNOPER_VALUE_ALONG_THIS_ROUTE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Along_A_Saved_Route, FC_VR_BTNOPER_VALUE_ALONG_A_SAVED_ROUTE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Album, FC_VR_BTNOPER_VALUE_ALBUM),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Artist, FC_VR_BTNOPER_VALUE_ARTIST),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Song, FC_VR_BTNOPER_VALUE_SONG),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Compose, FC_VR_BTNOPER_VALUE_COMPOSE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Genre, FC_VR_BTNOPER_VALUE_GENRE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Podcase, FC_VR_BTNOPER_VALUE_PODCASE),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Playlist, FC_VR_BTNOPER_VALUE_PLAY_LIST),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Audiobook, FC_VR_BTNOPER_VALUE_AUDIOBOOK),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Candidate1_Num2, FC_VR_BTNOPER_VALUE_CANDIDATE1_NUM2),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Candidate1_Num3, FC_VR_BTNOPER_VALUE_CANDIDATE1_NUM3),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Candidate1_Num4, FC_VR_BTNOPER_VALUE_CANDIDATE1_NUM4),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Candidate2, FC_VR_BTNOPER_VALUE_CANDIDATE2),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Candidate3, FC_VR_BTNOPER_VALUE_CANDIDATE3),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Candidate_Num2, FC_VR_BTNOPER_VALUE_CANDIDATE_NUM2),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Candidate_Num3, FC_VR_BTNOPER_VALUE_CANDIDATE_NUM3),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Candidate_Num4, FC_VR_BTNOPER_VALUE_CANDIDATE_NUM4),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Hard_Key_Off_Hook_Short_Press, FC_VR_BTNOPER_VALUE_HARD_KEY_OFF_HOOK_SHORT_PRESS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Hard_Key_Off_Hook_Long_Press, FC_VR_BTNOPER_VALUE_HARD_KEY_OFF_HOOK_LONG_PRESS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Hard_Key_Tel_Short_Press, FC_VR_BTNOPER_VALUE_HARD_KEY_TEL_SHORT_PRESS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Hard_Key_Tel_Long_Press, FC_VR_BTNOPER_VALUE_HARD_KEY_TEL_LONG_PRESS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Do_Not_Tell_Me_Again, FC_VR_BTNOPER_VALUE_DO_NOT_TELL_ME_AGAIN),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Set_PVR_Flag, FC_VR_BTNOPER_VALUE_SET_PVR_FLAG),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_PTT_Hard_Key_Short_Press, FC_VR_BTNOPER_VALUE_PTT_HARD_KEY_SHORT_PRESS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_PTT_Hard_Key_Long_Press, FC_VR_BTNOPER_VALUE_PTT_HARD_KEY_LONG_PRESS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Back_Long_Press, FC_VR_BTNOPER_VALUE_BACK_LONG_PRESS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Back_Short_Press, FC_VR_BTNOPER_VALUE_BACK_SHORT_PRESS),
    std::map<int, QString>::value_type(VoiceCoiceRecog_BtnOper_Value_Stop_Reading, FC_VR_BTNOPER_VALUE_STOP_READING),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Hard_Key_Enter_Long_Press, FC_VR_BTNOPER_VALUE_HARD_KEY_ENTER_LONG_PRESS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Hard_Key_Enter_Short_Press, FC_VR_BTNOPER_VALUE_HARD_KEY_ENTER_SHORT_PRESS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Debug_Input_On, FC_VR_BTNOPER_VALUE_DEBUG_INPUT_ON),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Debug_Input_Off, FC_VR_BTNOPER_VALUE_DEBUG_INPUT_OFF),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Debug_Output_On, FC_VR_BTNOPER_VALUE_DEBUG_OUTPUT_ON),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Debug_Output_Off, FC_VR_BTNOPER_VALUE_DEBUG_OUTPUT_OFF),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Web_Search, FC_VR_BTNOPER_VALUE_WEB_SEARCH),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Meter_Back_Short_Press, FC_VR_BTNOPER_VALUE_METER_HARD_KEY_BACK_SHORT_PRESS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Meter_Back_Long_Press, FC_VR_BTNOPER_VALUE_METER_HARD_KEY_BACK_LONG_PRESS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Hard_Key_Enter_Normal_Press, FC_VR_BTNOPER_VALUE_HARD_KEY_ENTER_NORMAL_PRESS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Meter_Back_Normal_Press, FC_VR_BTNOPER_VALUE_METER_HARD_KEY_BACK_NORMAL_PRESS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_PTT_Hard_Key_Short_Press_Special, FC_VR_BTNOPER_VALUE_PTT_HARD_SHORT_PRESS_SPECIAL),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_PTT_Hard_Key_Press_Special_In_EndTaskStatus, FC_VR_BTNOPER_VALUE_PTT_HARD_KEY_PRESS_SPECIAL_IN_ENDTASKSTATUS),
    std::map<int, QString>::value_type(VoiceVoiceRecog_BtnOper_Value_Hard_Key_Cancel_VR, FC_VR_BTNOPER_VALUE_HARD_KEY_CANCEL_VR)
};
const std::map<int, QString> ButtonValueMap(button_init_value, button_init_value+VoiceVoiceRecog_BtnOper_Value_Max-1);


// ------------------------------Action Media op ------------------------------------------
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ALBUM                 = QString("playByMusicAlbum");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ALL                   = QString("playByMusicAll");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ARTIST                = QString("playByMusicArtist");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_AUDIO_BOOK            = QString("playByMusicAudioBook");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_COMPOSER              = QString("playByMusicComposer");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE                 = QString("playByMusicGenre");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PLAYLIST              = QString("playByMusicPlaylist");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PODCAST               = QString("playByMusicPodcast");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PODCAST_ITEM          = QString("playByMusicPodcastItem");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_SONG                  = QString("playByMusicSong");
const QString FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ALBUM         = QString("shufflePlayByMusicAlbum");
const QString FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ARTIST        = QString("shufflePlayByMusicArtist");
const QString FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_COMPOSER      = QString("shufflePlayByMusicComposer");
const QString FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ALL           = QString("shufflePlayByMusicAll");
const QString FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_PLAYLIST      = QString("shufflePlayByMusicPlaylist");

const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_ARTIST_ALBUM    = QString("playByGenreArtistAndAlbum");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_ARTIST          = QString("playByGenreAndArtist");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ARTIST_ALBUM          = QString("playByArtistAndAlbum");
const QString FC_VR_ACTION_MEDIA_MUSIC_CHANGE_SOURCE                 = QString("changeSource");
const QString FC_VR_ACTION_MEDIA_MUSIC_TURN_AUDIO_OFF                = QString("turnAudioOff");
const QString FC_VR_ACTION_MEDIA_MUSIC_TURN_AUDIO_ON                 = QString("turnAudioOn");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_PODCAST_BY_EPISODE       = QString("playPodcastEpisode");
const QString FC_VR_ACTION_MEDIA_MUSIC_CHANGE_SOURCE_BY_NAME         = QString("changeSourceByName");

const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ARTIST                       = QString("PlayAllArtist");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM                        = QString("PlayAllAlbum");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ARTIST_BY_GENRE              = QString("playAllArtistByGenre");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_BY_ARTIST              = QString("PlayAllAlbumByArtist");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_BY_GENRE_ARTIST        = QString("PlayAllAlbumByGenreArtist");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM                        = QString("PlayTheAlbum");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_BY_ARTIST              = QString("PlayTheAlbumByArtist");
const QString FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_BY_GENRE_ARTIST        = QString("PlayTheAlbumByGenreArtist");

const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_GENRE                            = QString("ShowGenreScreen");
const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_SONG                             = QString("ShowSongScreen");
const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_PLAYLIST                         = QString("ShowPlaylistScreen");
const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_ARTIST                           = QString("ShowArtistScreen");
const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_ARTIST_BY_GENRE                  = QString("ShowArtistScreenByGenre");
const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM                            = QString("ShowAlbumScreen");
const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM_BY_ARTIST                  = QString("ShowAlbumScreenByArtist");
const QString FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM_BY_GENRE_ARTIST            = QString("ShowAlbumScreenByGenreArtist");

const QString FC_VR_ACTION_MEDIA_RADIO_CHANGE_HD_SUB_CHANNEL         = QString("changeHDSubChannel");
const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_FREQUENCY                = QString("tuneFrequency");
const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_HD_FREQUENCY          = QString("tuneFMHDFrequency");
const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_SATELLITE           = QString("tuneLastSatellite");
const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_SATELLITE_CHANNEL_NUMBER = QString("tuneSatelliteChannelNumber");
const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_AM                  = QString("tuneLastAM");
const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_FM                  = QString("tuneLastFM");
const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_GENRE                 = QString("tuneFMGenre");
const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_XM_CATEGORY              = QString("tuneXMCategory");
const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_DAB_CHANNEL              = QString("tuneDABChannel");
const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_CHANNEL               = QString("tuneFMChannel");
const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_SATELLITE_CHANNEL        = QString("tuneSatelliteChannel");
const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_MIX_RADIO_PRESET         = QString("tuneMixRadioPreset");
const QString FC_VR_ACTION_MEDIA_RADIO_TUNE_RADIO_PRESET             = QString("tuneRadioPreset");

const QString FC_VR_ACTION_HVAC_SHOW_FRONT_SCREEN                    = QString("showHvacFrontScreen");
const QString FC_VR_ACTION_HVAC_SHOW_REAR_SCREEN                     = QString("showHvacRearScreen");
const QString FC_VR_ACTION_HVAC_SHOW_STEERING_SCREEN                 = QString("showHvacSteeringScreen");
const QString FC_VR_ACTION_HVAC_SHOW_FRONT_SEAT_SCREEN               = QString("showFrontSeatScreen");
const QString FC_VR_ACTION_HVAC_SHOW_REAR_SEAT_SCREEN                = QString("showRearSeatScreen");
const QString FC_VR_ACTION_HVAC_SHOW_LEXUS_CONCIERGE_SCREEN          = QString("showLexusConciergeScreen");
const QString FC_VR_ACTION_HVAC_SHOW_SEAT_OPERATION_SCREEN           = QString("showSeatOperationScreen");
const QString FC_VR_ACTION_HVAC_SHOW_FRONT_SEAT_VENTI_SCREEN         = QString("showFrontSeatVentiScreen");
const QString FC_VR_ACTION_HVAC_SHOW_REAR_SEAT_VENTI_SCREEN          = QString("showRearSeatVentiScreen");
const QString FC_VR_ACTION_HVAC_SHOW_FRONT_AC_SCREEN                 = QString("showFrontACScreen");
const QString FC_VR_ACTION_HVAC_SHOW_REAR_AC_SCREEN                  = QString("showRearACScreen");
const QString FC_VR_ACTION_HVAC_SHOW_SEAT_SCREEN                     = QString("showHvacSeatScreen");
const QString FC_VR_ACTION_HVAC_SHOW_EXAMPLE                         = QString("example");

const QString FC_VR_ACTION_MEDIA_EXAMPLE                             = QString("example");


const std::map<QString, int>::value_type action_media_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ALBUM,                  FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ALBUM_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ALL,                    FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ALL_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ARTIST,                 FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ARTIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_AUDIO_BOOK,             FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_AUDIO_BOOK_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_COMPOSER,               FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_COMPOSER_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE,                  FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PLAYLIST,               FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PLAYLIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PODCAST,                FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PODCAST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PODCAST_ITEM,           FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_PODCAST_ITEM_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_SONG,                   FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_SONG_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ALBUM,          FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ALBUM_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ARTIST,         FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ARTIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_COMPOSER,       FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_COMPOSER_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ALL,            FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_ALL_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_PLAYLIST,       FC_VR_ACTION_MEDIA_MUSIC_SHUFFLE_PLAY_BY_PLAYLIST_INDEX),

    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_ARTIST_ALBUM,     FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_ARTIST_ALBUM_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_ARTIST,           FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_GENRE_ARTIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ARTIST_ALBUM,           FC_VR_ACTION_MEDIA_MUSIC_PLAY_BY_ARTIST_ALBUM_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_CHANGE_SOURCE,                  FC_VR_ACTION_MEDIA_MUSIC_CHANGE_SOURCE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_TURN_AUDIO_OFF,                 FC_VR_ACTION_MEDIA_MUSIC_TURN_AUDIO_OFF_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_TURN_AUDIO_ON,                  FC_VR_ACTION_MEDIA_MUSIC_TURN_AUDIO_ON_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_PODCAST_BY_EPISODE,        FC_VR_ACTION_MEDIA_MUSIC_PLAY_PODCAST_BY_EPISODE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_CHANGE_SOURCE_BY_NAME,          FC_VR_ACTION_MEDIA_MUSIC_CHANGE_SOURCE_BY_NAME_INDEX),

    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ARTIST,                FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ARTIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM,                 FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ARTIST_BY_GENRE,       FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ARTIST_BY_GENRE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_BY_ARTIST,       FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_BY_ARTIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_BY_GENRE_ARTIST, FC_VR_ACTION_MEDIA_MUSIC_PLAY_ALL_ALBUM_BY_GENRE_ARTIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM,                 FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_BY_ARTIST,       FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_BY_ARTIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_BY_GENRE_ARTIST, FC_VR_ACTION_MEDIA_MUSIC_PLAY_THE_ALBUM_BY_GENRE_ARTIST_INDEX),

    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_SHOW_GENRE,                     FC_VR_ACTION_MEDIA_MUSIC_SHOW_GENRE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_SHOW_SONG,                      FC_VR_ACTION_MEDIA_MUSIC_SHOW_SONG_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_SHOW_PLAYLIST,                  FC_VR_ACTION_MEDIA_MUSIC_SHOW_PLAYLIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_SHOW_ARTIST,                    FC_VR_ACTION_MEDIA_MUSIC_SHOW_ARTIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_SHOW_ARTIST_BY_GENRE,           FC_VR_ACTION_MEDIA_MUSIC_SHOW_ARTIST_BY_GENRE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM,                     FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM_BY_ARTIST,           FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM_BY_ARTIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM_BY_GENRE_ARTIST,     FC_VR_ACTION_MEDIA_MUSIC_SHOW_ALBUM_BY_GENRE_ARTIST_INDEX),


    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_CHANGE_HD_SUB_CHANNEL,          FC_VR_ACTION_MEDIA_RADIO_CHANGE_HD_SUB_CHANNEL_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_TUNE_FREQUENCY,                 FC_VR_ACTION_MEDIA_RADIO_TUNE_FREQUENCY_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_HD_FREQUENCY,           FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_HD_FREQUENCY_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_SATELLITE,            FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_SATELLITE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_TUNE_SATELLITE_CHANNEL_NUMBER,  FC_VR_ACTION_MEDIA_RADIO_TUNE_SATELLITE_CHANNEL_NUMBER_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_AM,                   FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_AM_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_FM,                   FC_VR_ACTION_MEDIA_RADIO_TUNE_LAST_FM_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_GENRE,                  FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_GENRE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_TUNE_XM_CATEGORY,               FC_VR_ACTION_MEDIA_RADIO_TUNE_XM_CATEGORY_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_TUNE_DAB_CHANNEL,               FC_VR_ACTION_MEDIA_RADIO_TUNE_DAB_CHANNEL_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_CHANNEL,                FC_VR_ACTION_MEDIA_RADIO_TUNE_FM_CHANNEL_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_TUNE_SATELLITE_CHANNEL,         FC_VR_ACTION_MEDIA_RADIO_TUNE_SATELLITE_CHANNEL_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_TUNE_MIX_RADIO_PRESET,          FC_VR_ACTION_MEDIA_RADIO_TUNE_MIX_RADIO_PRESET_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_RADIO_TUNE_RADIO_PRESET,              FC_VR_ACTION_MEDIA_RADIO_TUNE_RADIO_PRESET_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_MEDIA_EXAMPLE,                              FC_VR_ACTION_MEDIA_EXAMPLE_INDEX)

};
const std::map<QString, int> VrActioMediaMap(action_media_init_value, action_media_init_value+FC_VR_ACTION_MEDIA_EXAMPLE_INDEX);

const std::map<QString, int>::value_type action_havc_init_map[] =
{
    std::map<QString, int>::value_type(FC_VR_ACTION_HVAC_SHOW_FRONT_SCREEN, FC_VR_ACTION_HVAC_SHOW_FRONT_SCREEN_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HVAC_SHOW_REAR_SCREEN, FC_VR_ACTION_HVAC_SHOW_REAR_SCREEN_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HVAC_SHOW_STEERING_SCREEN, FC_VR_ACTION_HVAC_SHOW_STEERING_SCREEN_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HVAC_SHOW_FRONT_SEAT_SCREEN, FC_VR_ACTION_HVAC_SHOW_FRONT_SEAT_SCREEN_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HVAC_SHOW_REAR_SEAT_SCREEN, FC_VR_ACTION_HVAC_SHOW_REAR_SEAT_SCREEN_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HVAC_SHOW_LEXUS_CONCIERGE_SCREEN, FC_VR_ACTION_HVAC_SHOW_LEXUS_CONCIERGE_SCREEN_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HVAC_SHOW_SEAT_OPERATION_SCREEN, FC_VR_ACTION_HVAC_SHOW_SEAT_OPERATION_SCREEN_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HVAC_SHOW_FRONT_SEAT_VENTI_SCREEN, FC_VR_ACTION_HVAC_SHOW_FRONT_SEAT_VENTI_SCREEN_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HVAC_SHOW_REAR_SEAT_VENTI_SCREEN, FC_VR_ACTION_HVAC_SHOW_REAR_SEAT_VENTI_SCREEN_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HVAC_SHOW_FRONT_AC_SCREEN, FC_VR_ACTION_HVAC_SHOW_FRONT_AC_SCREEN_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HVAC_SHOW_REAR_AC_SCREEN, FC_VR_ACTION_HVAC_SHOW_REAR_AC_SCREEN_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HVAC_SHOW_SEAT_SCREEN, FC_VR_ACTION_HVAC_SHOW_SEAT_SCREEN_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HVAC_SHOW_EXAMPLE, FC_VR_ACTION_HVAC_SHOW_EXAMPLE_INDEX)
};

const std::map<QString, int> VrActionHvacMap(action_havc_init_map, action_havc_init_map + FC_VR_ACTION_HVAC_SHOW_EXAMPLE_INDEX);


// ------------------------------Action Phone op ------------------------------------------
const QString FC_VR_ACTION_PHONE_DIAL_CALL                           = QString("dial");
const QString FC_VR_ACTION_PHONE_DIAL_CALL_NUM                       = QString("dial");
const QString FC_VR_ACTION_PHONE_DIAL_CALL_RECENT                    = QString("dial");
const QString FC_VR_ACTION_PHONE_DIAL_Call_SHORTRING                 = QString("dial");
const QString FC_VR_ACTION_PHONE_DIAL_REDIAL                         = QString("dial");
const QString FC_VR_ACTION_PHONE_SHOW_RECENT_CALL_LIST               = QString("showRecentCallList");
const QString FC_VR_ACTION_PHONE_SEND_DTMF_TONES                     = QString("sendDTMFTones");
const QString FC_VR_ACTION_PHONE_SHOW_CONTACT_LIST                   = QString("showContactList");
const QString FC_VR_ACTION_PHONE_SHOW_FAVORITE_CONTACT_LIST          = QString("showFavoriteContactList");
const QString FC_VR_ACTION_PHONE_SEND_MESSAGE                        = QString("sendMessage");
const QString FC_VR_ACTION_PHONE_MUTE_CALL                           = QString("muteCall");
const QString FC_VR_ACTION_PHONE_MUTE_OFF                            = QString("muteOff");
const QString FC_VR_ACTION_PHONE_ADD_VOICE_TAG                       = QString("showAddVoiceTagUI");
const QString FC_VR_ACTION_PHONE_GET_MESSAGE_DEATIL                  = QString("getMessageDetail");
const QString FC_VR_ACTION_PHONE_GET_MESSAGE_STATE                   = QString("getMessageState");
const QString FC_VR_ACTION_PHONE_STATE                               = QString("phoneState");
const QString FC_VR_ACTION_PHONE_PB_STATE                            = QString("phonePbState");
const QString FC_VR_ACTION_PHONE_GET_MSGDETAIL_STATUSNOCHANGE        = QString("getMsgDetailStatusNoChange");
const QString FC_VR_ACTION_PHONE_EXAMPLE                             = QString("example");

const std::map<QString, int>::value_type action_phone_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_DIAL_CALL, FC_VR_ACTION_PHONE_DIAL_CALL_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_DIAL_CALL_NUM, FC_VR_ACTION_PHONE_DIAL_CALL_NUM_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_DIAL_CALL_RECENT, FC_VR_ACTION_PHONE_DIAL_CALL_RECENT_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_DIAL_Call_SHORTRING, FC_VR_ACTION_PHONE_DIAL_CALL_SHORTRING_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_DIAL_REDIAL, FC_VR_ACTION_PHONE_DIAL_REDIAL_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_SHOW_RECENT_CALL_LIST, FC_VR_ACTION_PHONE_SHOW_RECENT_CALL_LIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_SEND_DTMF_TONES, FC_VR_ACTION_PHONE_SEND_DTMF_TONES_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_SHOW_CONTACT_LIST, FC_VR_ACTION_PHONE_SHOW_CONTACT_LIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_SHOW_FAVORITE_CONTACT_LIST, FC_VR_ACTION_PHONE_SHOW_FAVORITE_CONTACT_LIST_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_SEND_MESSAGE, FC_VR_ACTION_PHONE_SEND_MESSAGE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_MUTE_CALL, FC_VR_ACTION_PHONE_MUTE_CALL_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_MUTE_OFF, FC_VR_ACTION_PHONE_MUTE_OFF_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_ADD_VOICE_TAG, FC_VR_ACTION_PHONE_ADD_VOICE_TAG_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_GET_MESSAGE_DEATIL, FC_VR_ACTION_PHONE_GET_MESSAGE_DEATIL_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_GET_MESSAGE_STATE, FC_VR_ACTION_PHONE_GET_MESSAGE_STATE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_STATE, FC_VR_ACTION_PHONE_STATE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_PB_STATE, FC_VR_ACTION_PHONE_PB_STATE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_GET_MSGDETAIL_STATUSNOCHANGE, FC_VR_ACTION_PHONE_GET_MSGDETAIL_STATUSNOCHANGE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_PHONE_EXAMPLE, FC_VR_ACTION_PHONE_EXAMPLE_INDEX),
};
const std::map<QString, int> VrActionPhoneMap(action_phone_init_value, action_phone_init_value+FC_VR_ACTION_PHONE_EXAMPLE_INDEX);

// ------------------------------Action apps op ------------------------------------------
const QString FC_VR_ACTION_APPS_LAUNCH                               = QString("launchApp");
const QString FC_VR_ACTION_APPS_EXAMPLE                              = QString("example");

const std::map<QString, int>::value_type action_apps_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_ACTION_APPS_LAUNCH, FC_VR_ACTION_APPS_LAUNCH_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_APPS_EXAMPLE, FC_VR_ACTION_APPS_EXAMPLE_INDEX),
};
const std::map<QString, int> VrActionAppsMap(action_apps_init_value, action_apps_init_value+FC_VR_ACTION_APPS_EXAMPLE_INDEX);


// ------------------------------Action Help op ------------------------------------------
const QString FC_VR_ACTION_HELP_SHOW_VOICE_SETTINGS_UI             = QString("showVoiceSettingsUI");
const QString FC_VR_ACTION_HELP_SHOW_LEXUS_INSIDER_UI              = QString("showLexusInsiderUI");
const QString FC_VR_ACTION_HELP_SHOW_TUTORIALS_UI                  = QString("showTutorialsUI");
const QString FC_VR_ACTION_HELP_TRAINING_END_MSG                   = QString("showTrainingEndMsg");

const std::map<QString, int>::value_type action_help_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_ACTION_HELP_SHOW_VOICE_SETTINGS_UI, FC_VR_ACTION_HELP_SHOW_VOICE_SETTINGS_UI_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HELP_SHOW_LEXUS_INSIDER_UI, FC_VR_ACTION_HELP_SHOW_LEXUS_INSIDER_UI_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HELP_SHOW_TUTORIALS_UI, FC_VR_ACTION_HELP_SHOW_TUTORIALS_UI_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_HELP_TRAINING_END_MSG, FC_VR_ACTION_HELP_SHOW_TRAINING_END_MSG_INDEX)

};

const std::map<QString, int> VrActionHelpMap(action_help_init_value, action_help_init_value + FC_VR_ACTION_HELP_MAX_INDEX);


// ------------------------------Action Weather op --------------------------------------
const QString FC_VR_ACTION_INFO_SHOW_CURRENT_WEATHER              =  QString("showCurrentWeather");
const QString FC_VR_ACTION_INFO_SHOW_NATIONAL_WEATHER             =  QString("showNationalWeather");
const QString FC_VR_ACTION_INFO_SHOW_EXAMPLE                      =  QString("example");

const std::map<QString, int>::value_type action_weather_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_ACTION_INFO_SHOW_CURRENT_WEATHER, FC_VR_ACTION_INFO_SHOW_CURRENT_WEATHER_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_INFO_SHOW_NATIONAL_WEATHER, FC_VR_ACTION_INFO_SHOW_NATIONAL_WEATHER_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_INFO_SHOW_EXAMPLE,          FC_VR_ACTION_WEATHER_MAX_INDEX)
};

const std::map<QString, int> VrActionWeatherMap(action_weather_init_value, action_weather_init_value + FC_VR_ACTION_WEATHER_MAX_INDEX);


// ------------------------------Action Navi op ------------------------------------------
const QString FC_VR_ACTION_NAVI_SHOW_POI_ICON                      = QString("showPOIIcon");
const QString FC_VR_ACTION_NAVI_HIDE_POI_ICON                      = QString("hidePOIIcon");
const QString FC_VR_ACTION_NAVI_CALC_ROUTE                         = QString("calculateRoute");
const QString FC_VR_ACTION_NAVI_DEL_DESTINATION                    = QString("deleteDestination");
const QString FC_VR_ACTION_NAVI_SHOW_POI_ICON_NUM                  = QString("queryShowingPOIIconNumber");
const QString FC_VR_ACTION_NAVI_ADD_TO_ROUTE                       = QString("addToRoute");
const QString FC_VR_ACTION_SHOW_DESTINATION_ASSIST                 = QString("callDestinationAssist");

const std::map<QString, int>::value_type action_navi_init_value[] =
{
    std::map<QString, int>::value_type(FC_VR_ACTION_NAVI_SHOW_POI_ICON, FC_VR_ACTION_NAVI_SHOW_POI_ICON_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_NAVI_HIDE_POI_ICON, FC_VR_ACTION_NAVI_HIDE_POI_ICON_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_NAVI_CALC_ROUTE, FC_VR_ACTION_NAVI_CALC_ROUTE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_NAVI_DEL_DESTINATION, FC_VR_ACTION_NAVI_DEL_DESTINATION_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_NAVI_SHOW_POI_ICON_NUM, FC_VR_ACTION_NAVI_SHOW_POI_ICON_NUM_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_NAVI_ADD_TO_ROUTE, FC_VR_ACTION_NAVI_ADD_TO_ROUTE_INDEX),
    std::map<QString, int>::value_type(FC_VR_ACTION_SHOW_DESTINATION_ASSIST, FC_VR_ACTION_SHOW_DESTINATION_ASSIST_INDEX)
};

const std::map<QString, int> VrActionNaviMap(action_navi_init_value, action_navi_init_value + FC_VR_ACTION_NAVI_MAX_INDEX);


/* EOF */
