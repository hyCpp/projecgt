#include <algorithm>
#include "VRXMLStrParse.h"
#include "VoiceVoiceRecogModelDef.h"
#include <iostream>
using namespace std;

VRXMLStrParse::VRXMLStrParse(const QString & xmlStr, ParseType type)
{
    if (type == Parse_Xml) {
        if (!m_dom.setContent(xmlStr)) {
            std::cout<<"Dom->setContent fail !"<<std::endl;
            return;
        }
        m_InitializeUniformTagMap();
    }
    else {
        if (!m_dom.setContent(xmlStr)) {
            std::cout<<"Dom->setContent fail !"<<std::endl;
            return;
        }
    }
}

VRXMLStrParse::~VRXMLStrParse()
{
}

void VRXMLStrParse::m_InitializeUniformTagMap()
{
    VrUniformTagStrVec vrUniformNameTagVec;
    vrUniformNameTagVec.push_back(FC_VR_RESULT_NAME_TAG);
    vrUniformNameTagVec.push_back(FC_VR_RESULT_APPNAME_TAG);
    vrUniformNameTagVec.push_back(FC_VR_RESULT_APP_NAME_TAG);
    vrUniformNameTagVec.push_back(FC_VR_RESULT_FORMAL_NAME_TAG);
    vrUniformNameTagVec.push_back(FC_VR_RESULT_CONTACT_NAME_TAG);
    vrUniformNameTagVec.push_back(FC_VR_RESULT_NUMBER_TAG);
    vrUniformNameTagVec.push_back(FC_VR_RESULT_DIGITS_TAG);
    vrUniformNameTagVec.push_back(FC_VR_RESULT_ARTIST_NAME_TAG);
    vrUniformNameTagVec.push_back(FC_VR_RESULT_ALBUM_NAME_TAG);
    vrUniformNameTagVec.push_back(FC_VR_RESULT_SONG_NAME_TAG);
    vrUniformNameTagVec.push_back(FC_VR_RESULT_PLAYLIST_NAME_TAG);
    m_VrUniformTagMap.insert(std::pair<QString, VrUniformTagStrVec>(VRCOMMON_NBESTLIST_NAME, vrUniformNameTagVec));

    VrUniformTagStrVec vrUniformAppNameTagVec;
    vrUniformAppNameTagVec.push_back(FC_VR_RESULT_APPNAME_TAG);
    m_VrUniformTagMap.insert(std::pair<QString, VrUniformTagStrVec>(VRAPPS_APPLIST_NAME, vrUniformAppNameTagVec));

    VrUniformTagStrVec vrUniformCommandTagVec;
    vrUniformCommandTagVec.push_back(FC_VR_RESULT_COMMAND_TAG);
    vrUniformCommandTagVec.push_back(FC_VR_RESULT_GENRE_NAME_TAG);
    vrUniformCommandTagVec.push_back(FC_VR_RESULT_ARTIST_NAME_TAG);
    vrUniformCommandTagVec.push_back(FC_VR_RESULT_ALBUM_NAME_TAG);
    vrUniformCommandTagVec.push_back(FC_VR_RESULT_SONG_NAME_TAG);
    vrUniformCommandTagVec.push_back(FC_VR_RESULT_PLAYLIST_NAME_TAG);
    vrUniformCommandTagVec.push_back(FC_VR_RESULT_STATION_NAME_TAG);
    vrUniformCommandTagVec.push_back(FC_VR_RESULT_CONTACT_NAME_TAG);
    m_VrUniformTagMap.insert(std::pair<QString, VrUniformTagStrVec>(VREU_TOPCMDLIST_COMMAND, vrUniformCommandTagVec));

}

QString VRXMLStrParse::GetValue(const QString& tag, const QString& attributeName) const
{
    QString result = "";
    QDomNodeList nodelist = m_dom.elementsByTagName(tag);

    if (QString::compare(attributeName, FC_VR_RECOGNITION_NULL_STRING) == 0) {
        if (nodelist.item(0).isElement()) {
            result = nodelist.item(0).toElement().text().toUtf8().data();
            QDomNode node = nodelist.at(0);
            QString test = node.toDocument().toString();
            printf("test = %s, name = %s\n", test.toStdString().c_str(), node.nodeName().toStdString().c_str());
        }
        else if (nodelist.item(0).toElement().firstChild().isText()) {
            result = nodelist.item(0).toElement().firstChild().toText().data().toUtf8().data();
            QString test = nodelist.at(0).toDocument().toString();
            printf("test = %s\n", test.toStdString().c_str());
        }
        else {
        }
    }
    else {
        if (nodelist.item(0).toElement().attributeNode(attributeName).isNull()) {
        }
        else {
            result = nodelist.item(0).toElement().attributeNode(attributeName).value();
        }
    }

    return result;
}

QVariant VRXMLStrParse::GetListValue(QString uniformtagkey, QString path)
{
    QVariantMap itemContentMap;
    QVariantList itemTagList;
    QDomNodeList nodelist = m_dom.elementsByTagName(path);
    if (nodelist.count() != 1) {
       std::cout<<"Parse Exception !--items tag is not exist!\n"<<std::endl;
    }
    QDomNodeList itemlist = nodelist.at(0).childNodes();

    for (int i = 0; i< itemlist.count(); i++) {
        m_RecurNode(itemlist.at(i), itemContentMap, uniformtagkey);
        itemTagList.append(itemContentMap);
        itemContentMap.clear();
    }

    QVariant data(itemTagList);
    return data;
}


QString VRXMLStrParse::GetValueByPath(const QString &tag, const QString &parent) const
{
    QString result = "";
    QDomNodeList nodelist = m_dom.elementsByTagName(parent);
    if (nodelist.count() != 1) {

    }
    QDomNodeList itemlist = nodelist.at(0).childNodes();

    for (int i = 0; i< itemlist.count(); ++i) {
        QDomNode childnode = itemlist.at(i);
        if (childnode.nodeName().compare(tag) == 0) {
            result = childnode.toElement().text().toUtf8().data();
        }
    }
    return result;
}

QVariantMap VRXMLStrParse::GetActionListValue(QString &actionOp)
{
    QVariantMap itemContentMap;
    itemContentMap.insert(FC_VOICE_ACTION_TYPE, actionOp);
    QDomNodeList nodelist = m_dom.elementsByTagName(FC_VR_RESULT_ALL_ACTION_TAG);
    if (nodelist.count() != 1) {
        std::cout<<"Parse Exception !--items tag is not exist!\n"<<std::endl;
    }
    else {
        m_RecurNode(nodelist.at(0), itemContentMap);
    }
    return itemContentMap;
}

QVariantMap VRXMLStrParse::GetActionMapForApp(const QString& actionOp)
{
    printf("GetActionMapForApp\n");
    QVariantMap itemContentMap;
    itemContentMap.insert(FC_VOICE_ACTION_TYPE, actionOp);
    QDomNodeList nodelist = m_dom.elementsByTagName(FC_VR_RESULT_ALL_ACTION_TAG);
    QDomNodeList childNodeList = nodelist.at(0).childNodes();

    for (int i = 0; i < childNodeList.count(); ++i) {
        QDomNode node = childNodeList.at(i);
            itemContentMap.insert(node.nodeName(), node.toElement().text());
            if (node.nodeName().compare("data") == 0 && node.nodeType() == 1) {
                QDomDocument data;
                data.setContent(QString("<temp></temp>"));
                for (QDomNode tempNode = node.firstChild(); !tempNode.isNull(); tempNode = tempNode.nextSibling()) {
                    data.appendChild(tempNode.cloneNode(true));
                }
                data.removeChild(data.elementsByTagName("temp").at(0));
                itemContentMap.insert("data", data.toString());
                continue;
            }
    }

    return itemContentMap;
}

void VRXMLStrParse::m_RecurNode(QDomNode node, QVariantMap& contentMap, const QString& uniformtagkey)
{
    QDomNodeList childNodeList = node.childNodes();
    for (int i = 0; i < childNodeList.count(); i++) {
        if (childNodeList.at(i).toElement().hasChildNodes()) {
            if (childNodeList.at(i).toElement().firstChild().isText()) {
                if (QString::compare(uniformtagkey, FC_VR_RECOGNITION_NULL_STRING) == 0) {
                    contentMap.insert(childNodeList.at(i).toElement().tagName(), childNodeList.at(i).toElement().firstChild().toText().data());
                }
                else {
                    VrUniformTagStrVec vrUniformTagStrVec;
                    vrUniformTagStrVec = m_VrUniformTagMap[uniformtagkey];
                    if (std::find(vrUniformTagStrVec.begin(), vrUniformTagStrVec.end(), childNodeList.at(i).toElement().tagName()) != vrUniformTagStrVec.end()) {
                        contentMap.insert(uniformtagkey, childNodeList.at(i).toElement().firstChild().toText().data());
                    }
                    else {
                        contentMap.insert(childNodeList.at(i).toElement().tagName(), childNodeList.at(i).toElement().firstChild().toText().data());

                    }
                }
            }
            else {
                m_RecurNode(childNodeList.at(i), contentMap, uniformtagkey);
            }
        }
        else {
            if (QString::compare(uniformtagkey, FC_VR_RECOGNITION_NULL_STRING) == 0) {
                contentMap.insert(childNodeList.at(i).toElement().tagName(),  FC_VR_RECOGNITION_NULL_STRING);
            }
            else {
                VrUniformTagStrVec vrUniformTagStrVec;
                vrUniformTagStrVec = m_VrUniformTagMap[uniformtagkey];
                if (std::find(vrUniformTagStrVec.begin(), vrUniformTagStrVec.end(), childNodeList.at(i).toElement().tagName()) != vrUniformTagStrVec.end()) {
                    contentMap.insert(uniformtagkey, FC_VR_RECOGNITION_NULL_STRING);
                }
                else {
                    contentMap.insert(childNodeList.at(i).toElement().tagName(), FC_VR_RECOGNITION_NULL_STRING);
                }
            }
        }
    }
}

void VRXMLStrParse::getNode(QDomNode& curNode, QVariantMap& itemContentMap)
{
    for (QDomNode n = curNode.firstChild(); !n.isNull(); n = n.nextSibling()) {
        if (n.nodeName().compare("count") == 0 && n.nodeType() == 1) {
            QDomDocument data;
            data.setContent(QString("<data></data>"));
            for (QDomNode tempNode = n.firstChild(); !tempNode.isNull(); tempNode = tempNode.nextSibling()) {
                data.appendChild(tempNode.cloneNode(true));
            }
            data.removeChild(data.elementsByTagName("data").at(0));
            itemContentMap.insert("data", data.toString());
            continue;
        }
        if (n.firstChild().nodeType() == 3) {
            printf("==== type = %d, name = %s, val = %s\n", n.firstChild().nodeType(), n.nodeName().toStdString().c_str(), n.toElement().text().toStdString().c_str());
            itemContentMap.insert(n.nodeName(), n.toElement().text());
        }
        getNode(n, itemContentMap);
    }
}

/* EOF */
