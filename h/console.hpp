//
// Created by os on 2/8/23.
//

#ifndef PROJECT_BASE_V1_0_CONSOLE_HPP
#define PROJECT_BASE_V1_0_CONSOLE_HPP

#include "syscall_c.h"

class Console {
public:
    static char getc() { return ::getc(); }

    static void putc(char ch) { ::putc(ch); }
};

#endif //PROJECT_BASE_V1_0_CONSOLE_HPP
