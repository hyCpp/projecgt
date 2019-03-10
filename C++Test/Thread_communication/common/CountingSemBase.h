#ifndef COUNTINGSEMBASE_H
#define COUNTINGSEMBASE_H
class CountingSemBase
{
public:
    typedef enum {
        KTimeout,
        KForever
    }Mode;

    CountingSemBase();
    ~CountingSemBase();

    virtual bool Wait(Mode mode = KForever, unsigned long timeout = 0) = 0;
    virtual bool Post(void) = 0;
};

#endif // COUNTINGSEMBASE_H
