#ifndef IMAGE_H
#define IMAGE_H
#include"iostream"
#include"string"

using namespace std;

class Image
{
public:
    Image(string name);
    ~Image();

    virtual void Show() = 0;
protected:
    string m_imageName;
};

#endif // IMAGE_H
