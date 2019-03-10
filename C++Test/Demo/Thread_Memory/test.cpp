#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>

void *test_thread(void* pParam)
{
    while(1)
    {
        printf("print this thread!\n");
        sleep(1);
    }
    return (void*)0;
}

int main()
{
    pthread_t thread = 0;
    pthread_create(&thread, 0, test_thread, 0);

    while(1)
    {
        sleep(1);
    }

    return 0;
}
