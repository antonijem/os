//
// Created by os on 1/5/23.
//

#ifndef PROJECT_BASE_V1_0_SYSCALL_C_H
#define PROJECT_BASE_V1_0_SYSCALL_C_H


#include "../lib/hw.h"
#include "../h/defs.h"
#include "../h/thread.h"
#include "../h/scheduler.h"
#include "../h/semaphore.h"
#include "../h/console.h"

#ifdef __cplusplus
extern "C" {
#endif

void *mem_alloc(size_t size);

int mem_free(void *);

int thread_create(
        thread_t *handle,
        void(*start_routine)(void *),
        void *arg
);

int thread_exit();

void thread_dispatch();

int sem_open(
        sem_t *handle,
        unsigned init
);

int sem_close (sem_t handle);

int sem_signal(sem_t id);

int sem_wait(sem_t id);

int time_sleep (time_t time);

void init_kthread();

void init_scheduler();

void kill_scheduler();

void kill_kthread();

void init_timer_thread();

void init_idle_thread();

void putc (char c);

char getc ();

void shutdown();

void userMode();

#ifdef __cplusplus
}
#endif

#endif //PROJECT_BASE_V1_0_SYSCALL_C_H
