#ifndef TIMER_H
#define TIMER_H

#define SPACE    32
#define ESC      27
#define UP       65
#define DOWN     66
#define RIGHT    67
#define LEFT     68

class Timer
{
public:
    void gameTimer(int tim_ms);
    char getKey();
    static Timer* GetInstance();

private:
    static Timer* p_Timer;
};

#endif // TIMER_H
