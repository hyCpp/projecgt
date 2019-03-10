#ifndef CLASSADAPTER_H
#define CLASSADAPTER_H
#include"Target.h"
#include"Adaptee.h"

class ClassAdapter : public Target , private Adaptee
{
public:
    ClassAdapter();
    ~ClassAdapter();

    void Request();
};

#endif // CLASSADAPTER_H
