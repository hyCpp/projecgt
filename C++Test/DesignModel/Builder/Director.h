#ifndef DIRECTOR_H
#define DIRECTOR_H
#include"Builder.h"

class Director
{
public:
    Director();
    ~Director();

    void Construct(Builder *builder);
};

#endif // DIRECTOR_H
