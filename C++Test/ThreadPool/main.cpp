#include "ThreadPoolDemo.h"
#include <unistd.h>

void funcTest(const std::string& str)
{
    sleep(1);
    std::cout<<"funTest is "<<str<<", Thread id : "<<std::this_thread::get_id()<<std::endl;
}

void funTest1(int n)
{
    sleep(n);
    std::cout<<"funTest1 is "<<n<<", Thread id : "<<std::this_thread::get_id()<<std::endl;
}

struct funTest2
{
    std::string operator() (int num) {
        std::cout<<"funTest2 : "<<num<<", Thread id : "<<std::this_thread::get_id()<<std::endl;
        sleep(1);
        return std::to_string(num);
    }
};

class ThreadUser
{
public:
    void UserFunc(int n, const std::string& str) {
        std::cout<<"ThreadUser::UserFunc : "<<n<<" , "<<str<<", Thread id : "<<std::this_thread::get_id()<<std::endl;
    }
};

class A
{
public:
    ~A() { std::cout<<"~A()"<<std::endl; }
};

class B : public A
{
public:
    ~B() { std::cout<<"~B()"<<std::endl; }
};

int main()
{
//    A* a = new B();
//    delete a;
//    a = nullptr;

    std::shared_ptr<A> spA = std::shared_ptr<A>(std::make_shared<B>());

//    ThreadPoolDemo threadPool(10);
//    threadPool.Initialize();

//    threadPool.Execute(funcTest, "hello world!");

//    threadPool.Execute([](int n){
//        for(int i = 0; i < 1000; ++i) {
//            n = n + i;
//        }
//        sleep(2);
//        std::cout<<"total is "<<n<<", Thread id : "<<std::this_thread::get_id()<<std::endl;
//    }, 1);

//    usleep(10);
//    std::cout<<"over idle Thread count is "<<threadPool.IdleThreadCount()<<std::endl;


//    std::future<std::string> futureTest = threadPool.ExecuteResult(funTest2(), 288);
//    usleep(10);
//    std::cout<<"over idle Thread count is "<<threadPool.IdleThreadCount()<<std::endl;


//    std::shared_ptr<ThreadUser> futureTest1(new ThreadUser);
//    threadPool.Execute(std::bind(&ThreadUser::UserFunc, futureTest1.get(), 1994, "My birthday"));
//    usleep(10);
//    std::cout<<"over idle Thread count is "<<threadPool.IdleThreadCount()<<std::endl;

//    std::cout<<"future Test : "<<futureTest.get()<<std::endl;

//    for (int i = 1; i< 50; ++i) {
//        threadPool.Execute(funTest1, i);
//    }

//    usleep(10);
//    std::cout<<"over idle Thread count is "<<threadPool.IdleThreadCount()<<std::endl;

//    for (int i = 0; i < 20; ++i) {
//        std::cout<<"current task count is "<<threadPool.getTaskCount()<<std::endl;
//        sleep(1);
//    }

//    usleep(10);
//    std::cout<<"over idle Thread count is "<<threadPool.IdleThreadCount()<<std::endl;


//    while(1) {
//        if (threadPool.IdleThreadCount() == 10 && threadPool.getTaskCount() == 0) {
//            break;
//        }
//    }

//    return 0;
}
