#include <stdio.h>
#include <string>
#include "boost/cast.hpp"
#include "conversiontest.h"

int main()
{
    baseA* a = new derived();
    a->printA();
    delete a;
    a = NULL;

//    try{
//        derived* d = boost::polymorphic_cast<derived*>(a);
//        d->onlyHere();
//        d->OnlyB();
//        baseB* b = boost::polymorphic_cast<baseB*>(a);
//        b->OnlyB();
//    }
//    catch(std::bad_exception& e) {
//        printf("e.what() = %s\n", e.what());
//    }

}
