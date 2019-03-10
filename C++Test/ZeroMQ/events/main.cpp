#include<string>
#include<stdio.h>
#include <stdlib.h>
#include "EventSystem.h"

int main()
{
    EventSystem::Instance()->Initialize("zmq");

}
