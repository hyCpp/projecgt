#ifndef NGVUIXMLSTRPARSE_H
#define NGVUIXMLSTRPARSE_H

#include "pugixml.hpp"
#include <string>
#include <map>
#include <vector>
#include "pugiconfig.hpp"

typedef std::map<std::string, std::string> XmlMap;
typedef std::vector<XmlMap> XmlVectorMap;
typedef std::vector<std::string> XmlVector;

class NGVUIXMLStrParse
{
public:
    NGVUIXMLStrParse(const std::string & xmlStr);
    ~NGVUIXMLStrParse();

    std::string GetXMLValue(const std::string &tag, const std::string& attributeName = "") const;
    XmlVectorMap GetXMLListValue(const std::string& nodePath) const;
    XmlMap GetXMLAttrMap(const std::string& nodePath);
    XmlVector GetXMLListNodeValue(const std::string& nodePath) const;

private:
    std::string transferXmlToString(pugi::xml_node nodes);
    void getNodes(pugi_vr::xml_node nodes, XmlMap& data);

private:
    pugi::xml_document m_dom;
};

#endif // NGVUIXMLSTRPARSE
/* EOF */
