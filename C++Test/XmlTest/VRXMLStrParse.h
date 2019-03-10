#ifndef VRXMLSTRPARSE_H
#define VRXMLSTRPARSE_H

#ifndef __cplusplus
#    error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif

#include <QDomElement>
#include <QtCore/QVariant>
#include <vector>
#include "VRConst.h"

class VRXMLStrParse
{
public:
    enum ParseType {
        Parse_Xml,
        Parse_Json
    };

    VRXMLStrParse(const QString &xmlStr, ParseType type = Parse_Xml);
    ~VRXMLStrParse();

    QString GetValue(const QString &tag, const QString& attributeName = "") const;
    QVariant GetListValue(QString uniformtagkey, QString path);
    QString GetValueByPath(const QString &tag, const QString &parent) const;
//    QVariant GetListValue(QString path, QString nodeName);
    QVariantMap GetActionListValue(QString& actionOp);

    QVariantMap GetActionMapForApp(const QString& actionOp);
    void getNode(QDomNode& n, QVariantMap& itemContentMap);

private:
    void m_RecurNode(QDomNode node, QVariantMap& contentMap, const QString& uniformtagkey = "");
    void m_InitializeUniformTagMap();

    QDomDocument m_dom;

    typedef std::vector<QString> VrUniformTagStrVec;
    typedef std::map<QString, VrUniformTagStrVec> VrUniformTagMap;
    VrUniformTagMap m_VrUniformTagMap;
};

#endif // VRXMLSTRPARSE_H
/* EOF */
