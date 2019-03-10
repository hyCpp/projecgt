#include "VUIModelParseXML.h"
#include "Log_Func.h"

VUIModelParseXML::VUIModelParseXML(const std::string& xmlStr)
    : m_curNodePtr(nullptr)
{
    m_xmlDocPtr = xmlParseMemory(xmlStr.c_str(), xmlStr.size());

    if (m_xmlDocPtr == nullptr) {
        TCLOGD("xmlParseMemory(xmlStr.c_str(), size) is failed!");
        return;
    }
}

VUIModelParseXML::~VUIModelParseXML()
{
    if (m_xmlDocPtr != nullptr) {
        xmlFreeDoc(m_xmlDocPtr);;
        xmlCleanupParser();
    }
}

bool VUIModelParseXML::GetFristNode(const xmlChar* xpath)
{
    xmlXPathObjectPtr pathStr;
    xmlXPathContextPtr context = xmlXPathNewContext(m_xmlDocPtr);

    if (context == nullptr) {
        TCLOGD("Error in xmlXPathNewContext");
        return false;
    }

    pathStr = xmlXPathEvalExpression(xpath, context);

    if (pathStr == nullptr) {
        TCLOGD("Error in xmlXPathEvalExpression");
        return false;
    }

    if (xmlXPathNodeSetIsEmpty(pathStr->nodesetval)) {
        xmlXPathFreeObject(pathStr);
        LOGD("no result xpath = %s", (char*)xpath);
        return false;
    }

    if (pathStr->nodesetval->nodeNr == 0) {
        TCLOGD("Error node set is 0");
        return false;
    }
    LOGD("nodeNr = %d", pathStr->nodesetval->nodeNr);

    m_curNodePtr = pathStr->nodesetval->nodeTab[0];

    transferXMLtoString(m_curNodePtr);

    return true;
}

std::string VUIModelParseXML::getFristNodeValue(const std::string &xpath, const std::string& attr)
{
    std::string result("");

    if (xpath.compare(FC_VUI_RESULT_EMPTY) == 0) {
        TCLOGD("xpath is empty!");
        return result;
    }

    if (GetFristNode((xmlChar*)xpath.c_str())) {
        if (attr.compare(FC_VUI_RESULT_EMPTY) == 0) {
            xmlChar* xmlchar = xmlNodeGetContent(m_curNodePtr);
            result = (char*)xmlchar;

            if (xmlchar) {
                xmlFree(xmlchar);
            }

            return result;
        }
        else {
            xmlChar* xmlAttr = xmlGetProp(m_curNodePtr, (const xmlChar*)attr.c_str());

            if (xmlAttr == nullptr) {
                LOGD("%s attribute is not exist", attr.c_str());

                return result;
            }

            result = (char*)xmlAttr;

            if (xmlAttr) {
                xmlFree(xmlAttr);
            }

            return result;
        }
    }

    return result;
}


std::vector<XML_MAP> VUIModelParseXML::GetNodeListValue(const std::string &nodePath)
{
    std::vector<XML_MAP> xmlList;
    XML_MAP resultMap;

    if (GetFristNode((xmlChar*)nodePath.c_str())) {

        xmlNodePtr param;
        for (param = m_curNodePtr->children; param; param = param->next) {

            xmlNodePtr paramChild;
            for(paramChild = param->children; paramChild; paramChild = paramChild->next) {

                std::string nodeName = (char*)paramChild->name;
                xmlChar* nodeValue = xmlNodeGetContent(paramChild);
                resultMap[nodeName] = (char*)nodeValue;

                if (nodeValue) {
                    xmlFree(nodeValue);
                }
            }

            xmlList.push_back(resultMap);
            resultMap.clear();
        }
    }

    return xmlList;
}

std::string VUIModelParseXML::makeQueryXml(const XMLNodeData &data)
{
    addTextTo(m_curNodePtr, "//notifica/id", data.id);
    addTextTo(m_curNodePtr, "//notification/id", data.id);
    addTextTo(m_curNodePtr, "//notification/type", data.type);
    addTextTo(m_curNodePtr, "//notification/domain", data.domain);
    addTextTo(m_curNodePtr, "//action_result/id", data.id);
    addTextTo(m_curNodePtr, "//action_result/action_type", data.type);
    addTextTo(m_curNodePtr, "//action_result/action_id", data.action_id);
    addTextTo(m_curNodePtr, "//action_result/error_no", data.error_no);

    transferXMLtoString(m_curNodePtr);

}

void VUIModelParseXML::addTextTo(xmlNodePtr node, const std::string &content)
{

}

void VUIModelParseXML::addTextTo(xmlNodePtr node, const std::string &xpath, const std::string &content)
{

}

std::string VUIModelParseXML::transferXMLtoString(xmlNodePtr node)
{
    std::string result("");
    xmlBufferPtr nodeBuffer = xmlBufferCreate();

    if (xmlNodeDump(nodeBuffer, m_xmlDocPtr, node, 0, 1) > 0) {
        result = (char*)nodeBuffer->content;
//        LOGD("xmlContent = %s", (char*)nodeBuffer->content);
    }

    xmlBufferFree(nodeBuffer);
    return result;
}
