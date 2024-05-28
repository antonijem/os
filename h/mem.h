//
// Created by os on 12/27/22.
//

#ifndef PROJECT_BASE_V1_0_MEM_H
#define PROJECT_BASE_V1_0_MEM_H

#include "../lib/hw.h"
#include "../h/console.h"

#ifdef __cplusplus
extern "C" {
#endif


//void* __mem_alloc(size_t size);

//int __mem_free(void* ptr);

void init_mem();

void *__mem_alloc(size_t size);

int __mem_free(void *ptr);

void test();

#ifdef __cplusplus
}
#endif


#endif //PROJECT_BASE_V1_0_MEM_H
