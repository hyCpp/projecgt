#include "VUIModelParseXML.h"
#include "Log_Func.cpp"
#include <string.h>

void VUIXMLNodeValue()
{
    VUIModelParseXML VUIXMLParse(FC_VUI_VRSTATE_HINTS);
    std::string result = VUIXMLParse.getFristNodeValue("//id");
    LOGD("xml node is %s", result.c_str());
    std::string type = VUIXMLParse.getFristNodeValue("//type");
    LOGD("xml node is %s", type.c_str());
    std::string param = VUIXMLParse.getFristNodeValue("//param");
    LOGD("xml node is %s", param.c_str());

    VUIModelParseXML VUIXMLParse1(DISPLAY_VRSTATE_VOICERECOG_RESULT);
    std::string attr = VUIXMLParse1.getFristNodeValue("//display", "content");
    LOGD("xml display attribute is %s", attr.c_str());
}

void VUIXMLListTest()
{
    VUIModelParseXML VUIXMLParse(FC_VUI_VRSTATE_HINTS);
    std::vector<XML_MAP> list = VUIXMLParse.GetNodeListValue("//params");

    for (XML_MAP map : list) {
        LOGD("name = %s", map["name"].c_str());
        LOGD("value = %s \n", map["value"].c_str());
    }
}

void VUIXMLMakeXMLTest()
{

}

int main()
{
    TC_Log::setLogStatus(true);

    VUIXMLListTest();
    VUIXMLNodeValue();
}
