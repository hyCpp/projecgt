#include"BigImage.h"
#include"Image.h"
#include"BigImageProxy.h"

int main()
{
    Image *image = new BigImageProxy("proxy.jpg");
    image->Show();
    delete image;
}
