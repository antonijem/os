//
// Created by os on 2/1/23.
//

#ifndef PROJECT_BASE_V1_0_CONSOLE_H
#define PROJECT_BASE_V1_0_CONSOLE_H

#include "../lib/hw.h"
#include "../h/semaphore.h"
#include "../h/syscall_c.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BUFFER_SIZE 2048

typedef struct buffer {
    char elements[BUFFER_SIZE];
    int read;
    int write;
    int size;
} buffer;

typedef buffer *buffer_t;

void __putc(char chr);

char __getc();

void console_output();

void console_input();

void set_output_elements(sem_t oempty, sem_t ofull, buffer_t obuff, sem_t iempty, sem_t ifull, buffer_t ibuff);

void init_console();

int get_output_num();

#ifdef __cplusplus
}
#endif

#endif //PROJECT_BASE_V1_0_CONSOLE_H
