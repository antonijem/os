//
// Created by os on 1/10/23.
//

#ifndef PROJECT_BASE_V1_0_THREAD_H
#define PROJECT_BASE_V1_0_THREAD_H

#include "../lib/hw.h"
#include "../h/defs.h"

#ifdef __cplusplus
extern "C" {
#endif

//Određuje stanje u kom se nit nalazi
enum state {
    NEW, READY, WAITING, FREE, SLEEPING
};

typedef struct _thread {
    //Pokazivač na stek niti
    size_t sp;
    //Velicina steka
    //size_t size;
    //Mozda je potreban nekakav pokazivac na kraj steka kao osiguracija od prekoracenja opsega
    //Uz to treba dodati u mem.c f-ju koja ce traziti prosirenje prostora

    //context *context; //Da li mi je potrebno???
    struct trapframe {
        //Da bih mogao da prosledim trap frame i na osnovu njega spakujem a0 i a1 na svoja mesta
        size_t a0;
        size_t a1;

        size_t ra;
        size_t sp;

        size_t s0;
        size_t s1;
        size_t s2;
        size_t s3;
        size_t s4;
        size_t s5;
        size_t s6;
        size_t s7;
        size_t s8;
        size_t s9;
        size_t s10;
        size_t s11;

        size_t a2;
        size_t a3;
        size_t a4;
        size_t a5;
        size_t a6;
        size_t a7;

        size_t t0;
        size_t t1;
        size_t t2;
        size_t t3;
        size_t t4;
        size_t t5;
        size_t t6;

        size_t gp;
        size_t tp;

    } trapframe;


    //Koju funkciju pokreće
    void *routine;
    enum state th_state;
    int tid;
    size_t time_slice;
    struct _thread *next;//Sluzi za ulancavanje u scheduler-u, alociram po potrebi ?
    void *arg;
} _thread;

typedef _thread *thread_t;

int thread_create_sys(thread_t *handle, void(*start_routine)(void *), void *arg, void *stack_space);

void init_list_elem(_thread  addr, int i);

void dec_num_of_active_threads();

int get_num_active_threads();

#ifdef __cplusplus
}
#endif

#endif //PROJECT_BASE_V1_0_THREAD_H