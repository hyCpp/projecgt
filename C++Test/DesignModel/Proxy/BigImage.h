#ifndef BIGIMAGE_H
#define BIGIMAGE_H
#include"Image.h"

class BigImage : public Image
{
public:
    BigImage(string name);
    ~BigImage();

    void Show();
};

#endif // BIGIMAGE_H
