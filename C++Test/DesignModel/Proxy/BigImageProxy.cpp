#include"BigImageProxy.h"

BigImageProxy::BigImageProxy(string name) : Image(name),m_bigImage(NULL)
{

}

BigImageProxy::~BigImageProxy()
{
    delete m_bigImage;
    m_bigImage = NULL;
}


void BigImageProxy::Show()
{
    if(m_bigImage == NULL) {
        m_bigImage = new BigImage(m_imageName);
        m_bigImage->Show();
    }
}
