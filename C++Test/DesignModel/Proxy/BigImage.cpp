#include"BigImage.h"

BigImage::BigImage(string name) : Image(name)
{

}

BigImage::~BigImage()
{

}

void BigImage::Show()
{
    std::cout<<"Show bigImage is : "<<m_imageName<<std::endl;
}
