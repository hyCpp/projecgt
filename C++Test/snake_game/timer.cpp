#include "timer.h"
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

Timer* Timer::p_Timer = NULL;

Timer* Timer::GetInstance()
{
    if (p_Timer == NULL) {
        p_Timer = new Timer();
    }
    return p_Timer;
}

void Timer::gameTimer(int tim_ms)
{
    struct itimerval time;
    time.it_interval.tv_sec = tim_ms / 1000; // "tim_ms/1000" seconds later start
    time.it_interval.tv_usec = tim_ms % 1000 * 1000;

    time.it_value.tv_sec = tim_ms / 1000; //Intervals
    time.it_value.tv_usec = tim_ms % 1000 * 1000;

    setitimer(ITIMER_REAL,&time,NULL); //SIGALRM()
}

char Timer::getKey()
{
    int n;
    char buf[3];
    n = read(0,buf,sizeof(buf));
    if(3 == n && buf[0] == 27 && buf[1] == 91)
    {
        return buf[2];
    }
    else if(1 == n)
    {
        return buf[0];
    }
    return 0;
}

