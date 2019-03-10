#include"Service.h"
#include<QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Service service;
    service.show();
    return app.exec();
}
