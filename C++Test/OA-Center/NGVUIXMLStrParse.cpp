#include "NGVUIXMLStrParse.h"
#include <memory.h>
#include <sstream>
#include "LogConfig/Log_Func.h"

NGVUIXMLStrParse::NGVUIXMLStrParse(const std::string & xmlStr)
{
    if (!m_dom.load_string(xmlStr.c_str())) {
        TCLOGD("m_dom.load_string(xmlStr.c_str()) is fail !");
        return;
    }
}

NGVUIXMLStrParse::~NGVUIXMLStrParse()
{
}

std::string NGVUIXMLStrParse::GetXMLValue(const std::string &tag, const std::string &attributeName) const
{
    std::string result = "";
    pugi::xml_node nodelist = m_dom.select_node(("//" + tag).c_str()).node();

    if (attributeName.compare("") == 0) {
        if (nodelist.empty()) {
            TCLOGD("Parse Exception! -- node = [%s]", tag.c_str());
        }
        else {
            result = nodelist.text().as_string();
        }
    }
    else {
        if (nodelist.attribute(attributeName.c_str()).empty()) {
            TCLOGD("Parse Exception! -- node = [%s], attributeName = [%s]", tag.c_str(), attributeName.c_str());
        }
        else {
            result = nodelist.attribute(attributeName.c_str()).value();
        }
    }

    return result;
}

XmlVectorMap NGVUIXMLStrParse::GetXMLListValue(const std::string& nodePath) const
{
    pugi::xpath_node_set nodelist = m_dom.select_nodes(nodePath.c_str());
    XmlVectorMap xmlList;
    XmlMap result;

    if (!nodelist.empty()) {
        for (pugi::xpath_node_set::const_iterator it = nodelist.begin(); it != nodelist.end(); ++it) {
            pugi::xpath_node node = *it;
            pugi::xml_node itemList = node.node();

            if (!itemList.empty()) {

                for (pugi::xml_node::iterator iter = itemList.begin(); iter != itemList.end(); ++iter) {
                    result[(*iter).name()] = (*iter).text().get();
                }

                xmlList.push_back(result);
                result.clear();
            }
        }
    }
    else {
        TCLOGD("Parse Exception! -- nodelist is empty!");
    }

    return xmlList;
}

XmlMap NGVUIXMLStrParse::GetXMLAttrMap(const std::string &nodePath)
{
    pugi::xml_node nodelist = m_dom.select_node((nodePath).c_str()).node();
    XmlMap result;
    getNodes(nodelist, result);
    return result;
}

XmlVector NGVUIXMLStrParse::GetXMLListNodeValue(const std::string &nodePath) const
{
    pugi::xpath_node_set nodelist = m_dom.select_nodes(nodePath.c_str());
    XmlVector xmlList;

    if (!nodelist.empty()) {
        for (pugi::xpath_node_set::const_iterator it = nodelist.begin(); it !=  nodelist.end(); ++it) {
            pugi::xpath_node node = *it;
            pugi::xml_node itemList = node.node();
            xmlList.push_back(itemList.text().as_string());
        }
    }
    else {
        printf("Parse Exception! -- nodelist is empty!\n");
    }

    return xmlList;
}

void NGVUIXMLStrParse::getNodes(pugi_vr::xml_node nodes, XmlMap& data)
{
    std::string key("");
    std::string value("");
    if (!strcmp(nodes.name(), "input")) {
        for (pugi::xml_node::attribute_iterator _attr = nodes.attributes_begin(); _attr != nodes.attributes_end(); ++_attr) {
            if (!strcmp(_attr->name(), "name")) {
                key = _attr->value();
            }

            if (!strcmp(_attr->name(), "value")) {
                value = _attr->value();
            }
        }

        if (!key.empty()) {
            data.insert(make_pair(key, value));
        }
    }

    for (pugi::xml_node _node = nodes.first_child(); _node; _node = _node.next_sibling()) {
        getNodes(_node, data);
    }
}

std::string NGVUIXMLStrParse::transferXmlToString(pugi::xml_node node)
{
    std::stringstream ss;
    node.print(ss);
    return ss.str();
}

/* EOF */
