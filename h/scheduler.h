//
// Created by os on 1/12/23.
//

#ifndef PROJECT_BASE_V1_0_SCHEDULER_H
#define PROJECT_BASE_V1_0_SCHEDULER_H

#include "../h/thread.h"
#include "../h/defs.h"

#ifdef __cplusplus
extern "C" {
#endif


void schedule();

void yield(thread_t old, thread_t newT);

void dispatch_thread();

void set_running(thread_t handle);

void remove_running();

void add_ready(thread_t handle);

void set_scheduler();

void remove_waiting();

void remove_scheduler();

void swap_kthread_sthread();

thread_t get_running();

thread_t get_scheduler_thread();

thread_t get_timer_thread();

int is_sleepingQueue_emtpy();

int put_running_to_sleep(time_t time);

void decrement_sleeping_timer();

void set_timer_thread();

void infinite_loop();

void set_idle_thread();

thread_t get_console_thread_out();

thread_t get_console_thread_in();

void set_console_in_thread(thread_t th);

void set_console_out_thread(thread_t th);

void swap_running_thread(thread_t th);



#ifdef __cplusplus
}
#endif

#endif //PROJECT_BASE_V1_0_SCHEDULER_H
