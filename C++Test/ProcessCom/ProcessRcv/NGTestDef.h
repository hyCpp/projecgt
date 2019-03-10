#ifndef NGTESTDEF
#define NGTESTDEF
#include <string>

const std::string FC_VUI_TEST_SHOWLIST("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
                                       "<action>" \
                                           "<id>1</id>" \
                                           "<type>HMI_ShowList</type>" \
                                           "<params>" \
                                                 "<scenario>NAVI_RESULT_LIST</scenario>" \
                                                 "<hmi_title>您想去哪？</hmi_title>" \
                                                 "<hmi_data>世纪汇广场A座</hmi_data>" \
                                                 "<hmi_longitude>23.123</hmi_longitude>" \
                                                 "<hmi_latitude>154.23</hmi_latitude>" \
                                                 "<hmi_data>世纪汇广场B座</hmi_data>" \
                                                 "<hmi_longitude>43.12</hmi_longitude>" \
                                                 "<hmi_latitude>113.243</hmi_latitude>" \
                                                 "<hmi_data>世纪汇广场C座</hmi_data>" \
                                                 "<hmi_longitude>12.45</hmi_longitude>" \
                                                 "<hmi_latitude>56.67</hmi_latitude>" \
                                                 "<hmi_help_command>可以说，第一个，第二个</hmi_help_command>" \
                                                 "<hmi_highlight_item>1</hmi_highlight_item>" \
                                                 "<current_page>1</current_page>" \
                                                 "<total_page>5</total_page>" \
                                          "</params>" \
                                     "</action>");


const std::string FC_VUI_TEST_NAVI_TODESTINATION("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
                                                "<action>" \
                                                    "<id>2</id>" \
                                                    "<type>Navi_ToDestination</type>" \
                                                    "<params>" \
                                                         "<navi_dst_addr>上海市浦东新区浦东国际机场1号</navi_dst_addr>" \
                                                         "<addr_longitude>112.5043</addr_longitude>" \
                                                         "<addr_latitude>39.2237</addr_latitude>" \
                                                         "<navi_route_option>NAVI_POLICY_HIGHWAY_FIRST</navi_route_option>" \
                                                "</params>" \
                                           "</action>");

const std::string FC_VUI_TEST_NAVI_VIAPOINT("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
                                                "<action>" \
                                                    "<id>3</id>" \
                                                    "<type>Navi_SetViaPoint</type>" \
                                                    "<params>" \
                                                         "<navi_via_point_name>北京市东城区长安街1号</navi_via_point_name>" \
                                                         "<addr_longitude>112.5043</addr_longitude>" \
                                                         "<addr_latitude>39.2237</addr_latitude>" \
                                                         "<position>2</position>" \
                                                "</params>" \
                                           "</action>");

const std::string FC_VUI_TEST_MEDIA_LOCAL("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
                                                "<action>" \
                                                    "<id>4</id>" \
                                                    "<type>Media_PlayLocalMusic</type>" \
                                                    "<params>" \
                                                         "<media_song_type>MEDIA_SONG_FROM_SOURCE</media_song_type>" \
                                                         "<name>usb</name>" \
                                                         "<id>38</id>" \
                                                "</params>" \
                                           "</action>");

const std::string FC_VUI_TEST_MEDIA_SETSTATUS("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
                                                "<action>" \
                                                    "<id>4</id>" \
                                                    "<type>Media_SetStatus</type>" \
                                                    "<params>" \
                                                         "<media_control_type>MEDIA_CONTROL_TYPE_EXIT</media_control_type>" \
                                                "</params>" \
                                           "</action>");


const std::string FC_VUI_TEST_MEDIA_PLAYONLINE("<?xml version=\"1.0\" encoding=\"utf-8\" ?>" \
                                                "<action>" \
                                                    "<id>4</id>" \
                                                    "<type>Media_PlayOnlineMusic</type>" \
                                                    "<params>" \
                                                          "<music_info>" \
                                                                "<url_song>http://dwn.roo.bo/resource/music_bk/123/34963123.mp3</url_song>" \
                                                                "<url_photo>https://y.gtimg.cn/music/photo_new/T002R300x300M000004cPHRr3nkmJe.jpg?max_age=2592000</url_photo>" \
                                                                "<artist_name>周杰伦 潘玮柏 张学友</artist_name>" \
                                                                "<song_name>听妈妈的话</song_name>" \
                                                                "<type_name>流行音乐</type_name>" \
                                                          "</music_info>" \
                                                          "<music_info>" \
                                                                "<url_song>http://dwn.roo.bo/resource/music_bk/123/34963123.mp3</url_song>" \
                                                                "<url_photo>https://y.gtimg.cn/music/photo_new/T002R300x300M000004cPHRr3nkmJe.jpg?max_age=2592000</url_photo>" \
                                                                "<artist_name>周杰伦 潘玮柏 张学友</artist_name>" \
                                                                "<song_name>听妈妈的话</song_name>" \
                                                                "<type_name>流行音乐</type_name>" \
                                                          "</music_info>" \
                                                          "<music_info>" \
                                                                "<url_song>http://dwn.roo.bo/resource/music_bk/123/34963123.mp3</url_song>" \
                                                                "<url_photo>https://y.gtimg.cn/music/photo_new/T002R300x300M000004cPHRr3nkmJe.jpg?max_age=2592000</url_photo>" \
                                                                "<artist_name>周杰伦 潘玮柏 张学友</artist_name>" \
                                                                "<song_name>听妈妈的话</song_name>" \
                                                                "<type_name>流行音乐</type_name>" \
                                                          "</music_info>" \
                                                    "</params>" \
                                               "</action>");


#endif // NGTESTDEF

