#include "CountingSemImpl.h"
#include <stdio.h>

CountingSemImpl::CountingSemImpl(unsigned int init_sem_count)
    :CountingSemBase()
{
    int result = sem_init(&m_sem, 0, init_sem_count);
    if (result != 0) {
        printf("CLinuxCountingSem:  error\n");
    }
}

CountingSemImpl::~CountingSemImpl()
{

}

/**
  *The function is subtract a "1" from the value of the semaphore
 */
bool CountingSemImpl::Wait(Mode mode, unsigned long timeout)
{

    if (sem_wait(&m_sem) == 0) {
        return true;
    }
    else {
        return false;
    }
}

/**
  *The function is add a "1" from the value of the semaphore
 */
bool CountingSemImpl::Post()
{
    sem_post(&m_sem);
    return true;
}
