//
// Created by os on 1/21/23.
//

#ifndef PROJECT_BASE_V1_0_SEMAPHORE_H
#define PROJECT_BASE_V1_0_SEMAPHORE_H

#include "../lib/hw.h"
#include "../h/scheduler.h"
#include "../h/defs.h"


#ifdef __cplusplus
extern "C" {
#endif

enum status {
    ALIVE, DEAD
};

typedef struct _sem {
    unsigned int val;
    thread_t waitingQueue;
    enum status sem_status;
} _sem;

typedef _sem *sem_t;

int sem_open_sys(sem_t *handle, unsigned int init);

int sem_signal_sys(sem_t handle);

int sem_wait_sys(sem_t handle);

void init_sem_list(_sem addr, int i);

#ifdef __cplusplus
}
#endif

#endif //PROJECT_BASE_V1_0_SEMAPHORE_H
