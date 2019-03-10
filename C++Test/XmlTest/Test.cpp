#include <VRXMLStrParse.h>
#include <iostream>
#include "VoiceVoiceRecogModelDef.h"
#include "DemoItem.h"
#include <stdio.h>
#include <string>

using namespace std;


void test(const QString& str)
{
    //    std::cout<<"begin"<<std::endl;
    //    VRXMLStrParse* pVRXMLStrParse = new VRXMLStrParse(str);
    //    QString data = pVRXMLStrParse->GetValue("display", "agent");

    //    if (data.compare("Common") == 0) {
    //        std::cout<<"size = "<< sizeof(*pVRXMLStrParse)<<std::endl;
    //        return;
    //    }

    //    delete pVRXMLStrParse;
    //    pVRXMLStrParse = NULL;
    //    std::cout<<"end"<<std::endl;
}

int main() {
    QString testxml1 = QString("<display agent=\"Common\" content=\"ScreenDisplay\">"\
                               "<agent>alexa_demo</agent>"
                               "<content>RenderPlayerInfo</content>"
                               "<header>"
                               "<namespace>TemplateRuntime</namespace>"
                               "<name>RenderPlayerInfo</name>"
                               "<messageId>string</messageId>"
                               "<dialogRequestId>string</dialogRequestId>"
                               "</header>"
                               "<payload>"
                               "<audioItemId>string</audioItemId>"
                               "<content>"
                               "<title>string</title>"
                               "<titleSubtext1>string</titleSubtext1>"
                               "<titleSubtext2>string</titleSubtext2>"
                               "<header>string</header>"
                               "<headerSubtext1>string</headerSubtext1>"
                               "<mediaLengthInMilliseconds>0</mediaLengthInMilliseconds>"
                               "<art>IMAGE_STRUCTURE</art>"
                               "<provider>"
                               "<name>string</name>"
                               "<logo>"
                               "<contentDescription></contentDescription>"
                               "<sources>"
                               "<url>url</url>"
                               "<darkBackgroundUrl>darkBackgroundUrl</darkBackgroundUrl>"
                               "<size>10</size>"
                               "<widthPixels>0</widthPixels>"
                               "<heightPixels>0</heightPixels>"
                               "</sources>"
                               "<sources>"
                               "<url>url1</url>"
                               "<darkBackgroundUrl>darkBackgroundUrl1</darkBackgroundUrl>"
                               "<size>12</size>"
                               "<widthPixels>0</widthPixels>"
                               "<heightPixels>0</heightPixels>"
                               "</sources>"
                               "</logo>"
                               "</provider>"
                               "</content>"
                               "<controls>"
                               "<type>BUTTON</type>"
                               "<name>string</name>"
                               "<enabled>false</enabled>"
                               "<selected>false</selected>"
                               "</controls>"
                               "<controls>"
                               "<type>BUTTON</type>"
                               "<name>string</name>"
                               "<enabled>false</enabled>"
                               "<selected>false</selected>"
                               "</controls>"
                               "<controls>"
                               "<type>BUTTON</type>"
                               "<name>string</name>"
                               "<enabled>false</enabled>"
                               "<selected>false</selected>"
                               "</controls>"
                               "</payload>"
                               "</display>");

    QString testxml = QString("<action agent=\"Navi\" content=\"SearchResult\" errcode=\"0\">"\
                              "<count>"
                              "<poc>poc</poc>"
                              "<test>" \
                              "<q>yyy</q>" \
                              "<qq>yyyyy</qq>" \
                              "</test></count>"\
                              "<items>"\
                              "<data>"\
                              "<contactid>%20%</contactid>"
                              "<firstname>%21%</firstname>"
                              "<lastname>%22%</lastname>"
                              "<phonetype1>%23%</phonetype1>"
                              "<phonenumber1>%24%</phonenumber1>"
                              "<phonetype2>%25%</phonetype2>"
                              "<phonenumber2>%26%</phonenumber2>"
                              "<phonetype3>%27%</phonetype3>"
                              "<phonenumber3>%28%</phonenumber3>"
                              "<phonetype4>%29%</phonetype4>"
                              "<phonenumber4>%30%</phonenumber4>"
                              "</data>"
                              "</items>"
                              "</action>");

    QString dataXml = QString("<action agent=\"apps\" op=\"launchApp\">"\
                              "<appid>app=id</appid>"\
                              "<dataSize>data=Size</dataSize>"\
                              "<data><huyang><test>hello</test></huyang></data>"\
                          "</action>");

    QString amStateXml = QString("<display agent=\"Common\" content=\"HintsDisplay\">"\
                                    "<hints><list><header>count</header>"\
                                        "<items>"\
                                            "<item><hint>one</hint></item>"\
                                            "<item show=\"AM_Exist\"><hint>two</hint></item>"\
                                            "<item><hint>thress</hint></item>"\
                                        "</items>"\
                                    "</list></hints>"\
                                 "</display>");
    //    test(testxml1);
    //    printf("new VRXMLStrParse(data)");
    //    while(1);

      QDomDocument qDom;
      if (!qDom.setContent(amStateXml)) {
          std::cout<<"Dom->setContent fail !"<<std::endl;
      }
      bool amState = false;
      QDomNodeList itemslist = qDom.elementsByTagName("item");
      for (int i = 0; i < itemslist.count(); ++i) {
          QDomNode node = itemslist.at(i);

          if (node.nodeType() == QDomNode::ElementNode && node.hasAttributes()) {

              QString attrItem = node.attributes().namedItem("show").nodeValue();
              std::cout<<attrItem.toStdString()<<std::endl;
              if (attrItem.compare("AM_Exist") == 0) {
                  amState = true;
              }
              else if (attrItem.compare("AM_Not_Exist") == 0) {
                  amState = false;
              }
              else {
                  std::cout<<"item nodes is not exist attribute of name is show"<<std::endl;
              }
          }
      }
      std::cout<<amState<<std::endl;
      QVariant(true);


//    VRXMLStrParse pVRXMLStrParse(dataXml);

//    QVariantMap itemContentMap = pVRXMLStrParse.GetActionMapForApp("lunchApp");
//    QVariantMap::Iterator iter;
//    for (iter = itemContentMap.begin(); iter != itemContentMap.end(); ++iter) {
//        printf("key = %s, value = %s\n", iter.key().toStdString().c_str(), iter.value().toString().toStdString().c_str());
//    }

}

