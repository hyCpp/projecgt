#ifndef PROTOTYPE_H
#define PROTOTYPE_H
class Prototype
{
public:
    Prototype();
    ~Prototype();

    virtual Prototype* Clone();
    virtual void show();

protected:
    int id;
};

#endif // PROTOTYPE_H
