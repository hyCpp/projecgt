#ifndef VUIMODELPARSEXML
#define VUIMODELPARSEXML
#include <stdio.h>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/xmlstring.h>
#include <libxml/xpath.h>
#include <string>
#include <vector>
#include <map>
#include <VUIModelXMLDefine.h>

typedef std::map<std::string, std::string> XML_MAP;

class VUIModelParseXML
{
public:
    VUIModelParseXML(const std::string& xmlStr);
    ~VUIModelParseXML();

    std::string getFristNodeValue(const std::string &xpath, const std::string& attr = "");
    std::vector<XML_MAP> GetNodeListValue(const std::string& nodePath);
    std::string makeQueryXml(const XMLNodeData& data);

private:
    bool GetFristNode(const xmlChar* xpath);
    void addTextTo(xmlNodePtr node, const std::string& content);
//    void addTextTo(xmlXPathContextPtr nodes, const std::string& content);
    void addTextTo(xmlNodePtr node, const std::string& xpath, const std::string& content);
    std::string transferXMLtoString(xmlNodePtr node);

private:
    xmlDocPtr m_xmlDocPtr;
    xmlNodePtr m_curNodePtr;
};

#endif // VUIMODELPARSEXML

