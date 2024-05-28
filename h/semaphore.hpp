//
// Created by os on 2/8/23.
//

#ifndef PROJECT_BASE_V1_0_SEMAPHORE_HPP
#define PROJECT_BASE_V1_0_SEMAPHORE_HPP

#include "syscall_c.h"

class Semaphore {
public:
    Semaphore(unsigned init = 1) { sem_open(&myHandle, init); }

    virtual ~Semaphore() { sem_close(myHandle); }

    int wait() { return sem_wait(myHandle); }

    int signal() { return sem_signal(myHandle); }

private:
    sem_t myHandle;
};

#endif //PROJECT_BASE_V1_0_SEMAPHORE_HPP
