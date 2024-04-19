#include "stdio.h"

int main(void)
{
    __asm volatile ("LDR R1, =#0x20001000");        // R1 = 0x20001000
    __asm volatile ("LDR R2, =#0x20001004");        // R2 = 0x20001004
    __asm volatile ("LDR R0, [R1]");                // R0 = *((int *) 0x20001000)
    __asm volatile ("LDR R1, [R2]");                // R1 = *((int *) 0x20001004)
    __asm volatile ("ADD R0, R0, R1");              // R0 = R0 + R1
    __asm volatile ("STR R0, [R2]");                // *((int *) R2) = R0 
    for(;;);
    return 0;
}

