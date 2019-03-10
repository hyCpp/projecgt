#ifndef SNAKEMOVING_H
#define SNAKEMOVING_H

struct pos
{
    int x;
    int y;
};

struct dir
{
    int x;
    int y;
    int f;
};

class snakeMoving
{
public:
    snakeMoving();
    ~snakeMoving();

    void initGame();
    void initData();
    int gameEnd();
    int gameKey();
    void gameBox();
    void gameSnack();
    void moveingSnack();
    void gameFood();
    void funcHander(int sig);
    int saveData();
    int loadData();
    void gameGrade();
    int lifeEnd();

private:
    pos m_head;
    pos m_body[200];
    pos m_food;
    dir m_dir;
    char m_fKey;
    int m_grade;
    int m_level;
    int m_count;
    int m_speed;
    int m_MaxGrade[10];
};

#endif // SNAKEMOVING_H
