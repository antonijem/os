//
// Created by os on 1/5/23.
//

#ifndef PROJECT_BASE_V1_0_TRAP_H
#define PROJECT_BASE_V1_0_TRAP_H

#include "../lib/hw.h"
#include "../h/defs.h"
#include "../h/mem.h"
#include "../h/thread.h"
#include "../h/scheduler.h"
#include "../h/semaphore.h"
#include "../h/console.h"


#ifdef __cplusplus
extern "C" {
#endif

void init_trap();


#ifdef __cplusplus
}
#endif

#endif //PROJECT_BASE_V1_0_TRAP_H
