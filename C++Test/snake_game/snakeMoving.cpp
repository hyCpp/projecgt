#include "snakeMoving.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>

void snakeMoving::initData()
{
    srand(time(NULL)); //Generates a random number according to the system time
    signal(SIGALRM,funcHander); //The first param trigger the signal, the second param is execute

}

void snakeMoving::initGame()
{

}

void snakeMoving::gameEnd()
{

}

void snakeMoving::gameGrade()
{

}

void snakeMoving::funcHander(int sig)
{

}

void snakeMoving::gameBox()
{

}

void snakeMoving::gameFood()
{

}

void snakeMoving::gameKey()
{

}

void snakeMoving::gameSnack()
{

}

void snakeMoving::lifeEnd()
{

}
