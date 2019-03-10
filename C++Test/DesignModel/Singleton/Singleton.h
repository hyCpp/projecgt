#ifndef SINGLETON_H
#define SINGLETON_H
#include<iostream>

class Singleton
{
public:
    static Singleton* Instance();

private:
    static Singleton* m_instance;
    Singleton();
};

#endif // SINGLETON_H
