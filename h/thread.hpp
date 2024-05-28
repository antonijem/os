//
// Created by os on 2/8/23.
//

#ifndef PROJECT_BASE_V1_0_THREAD_HPP
#define PROJECT_BASE_V1_0_THREAD_HPP

#include "syscall_c.h"

class Thread {
public:
    Thread(void (*body)(void *), void *arg) {
        start_routine = body;
        args = arg;
    }

    virtual ~Thread() { thread_exit(); }

    int start() { return thread_create(&myHandle, wrapper, this); }

    static void dispatch() { thread_dispatch(); }

    static int sleep(time_t t) { return time_sleep(t); }

protected:
    Thread() {}

    virtual void run() {}

private:
    static void wrapper(void *th) { if (th) ((Thread *) th)->run(); }

    void (*start_routine)(void *) = 0;

    void *args = 0;
    thread_t myHandle;
};

class PeriodicThread : public Thread {
protected:
    PeriodicThread(time_t period) : _period(period) {};

    virtual void periodicActivation() {}

    virtual void run() final {
        while (1) {
            periodicActivation();
            sleep(_period);
        }
    }

private:
    time_t _period;
};

#endif //PROJECT_BASE_V1_0_THREAD_HPP
