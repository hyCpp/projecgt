#ifndef CONVERSIONTEST
#define CONVERSIONTEST

class baseA
{
public:
    baseA() {printf("baseA::baseA()\n");}
    virtual void printA()
    {
        printf("baseA::print()\n");
    }

    virtual ~baseA() {printf("baseA::~baseA()\n");}
};

class baseB
{
public:
    baseB() {printf("baseB::baseB()\n");}

    void OnlyB()
    {
        printf("baseB::OnlyB()\n");
    }

    virtual ~baseB(){printf("baseB::~baseB()\n");}
};

class derived : public baseA ,public baseB
{
public:
    derived() {printf("derived::derived()\n");}

    ~derived() {printf("derived::~derived()\n");}
    void printA()
    {
        printf("derived::printA()\n");
    }

    void onlyHere()
    {
        printf("derived::onlyHere()\n");
    }

    void OnlyB()
    {
        printf("here too!\n");
    }

};

#endif // CONVERSIONTEST

