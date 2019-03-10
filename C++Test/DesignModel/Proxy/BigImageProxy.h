#ifndef BIGIMAGEPROXY_H
#define BIGIMAGEPROXY_H
#include"Image.h"
#include"BigImage.h"

class BigImageProxy : public Image
{
public:
    BigImageProxy(string name);
    ~BigImageProxy();

    void Show();

private:
    BigImage *m_bigImage;
};

#endif // BIGIMAGEPROXY_H
