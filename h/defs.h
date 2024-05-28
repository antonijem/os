//
// Created by os on 1/5/23.
//

#ifndef PROJECT_BASE_V1_0_DEFS_H
#define PROJECT_BASE_V1_0_DEFS_H

#define MEM_INFO 32
#define MEM_OFFSET 32
#define SYS_MEM_ALLOC 0x01
#define SYS_MEM_FREE 0x02
#define SYS_THREAD_CREATE 0x11
#define SYS_THREAD_EXIT 0x12
#define SYS_DISPATCH 0x13
#define SYS_SEM_OPEN 0x21
#define SYS_SEM_CLOSE 0x22
#define SYS_SEM_WAIT 0x23
#define SYS_SEM_SIGNAL 0x24
#define SYS_THREAD_SLEEP 0x31
#define SYS_GET_C 0x41
#define SYS_PUT_C 0x42

#define MAX_NUM_THREADS 2000
#define MAX_NUM_SEM 500

#define disableHardwareTraps size_t sie; asm volatile("csrr %0, sie" : "=r" (sie)); sie = sie - 512; asm volatile("csrw sie, %0" : : "r" (sie));
#define enableSoftwareTraps size_t sstatusE; asm volatile("csrr %0, sstatus" : "=r" (sstatusE)); sstatusE = sstatusE | 2; asm volatile("csrw sstatus, %0" : : "r" (sstatusE));
#define disableSoftwareTraps size_t sstatusD; asm volatile("csrr %0, sstatus" : "=r" (sstatusD)); sstatusD = sstatusD & ~2; asm volatile("csrw sstatus, %0" : : "r" (sstatusD));
#define acknowledgeSoftwareTrap size_t sip; asm volatile("csrr %0 , sip " : "=r" (sip)); sip = sip & ~2; asm volatile("csrw sip, %0" : : "r" (sip));
#define acknowledgeHardwareTrap size_t sip; asm volatile("csrr %0 , sip " : "=r" (sip)); sip = sip & ~512; asm volatile("csrw sip, %0" : : "r" (sip));

#define disableAllTraps size_t sstatusD; asm volatile("csrr %0, sstatus" : "=r" (sstatusD)); sstatusD = sstatusD & ~sstatusD; asm volatile("csrw sstatus, %0" : : "r" (sstatusD));
#define enableAllTraps size_t sstatusE; asm volatile("csrr %0, sstatus" : "=r" (sstatusE)); sstatusE = sstatusE | 0x2; asm volatile("csrw sstatus, %0" : : "r" (sstatusE));


#endif //PROJECT_BASE_V1_0_DEFS_H
