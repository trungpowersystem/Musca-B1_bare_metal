#include "stdio.h"

int main(void)
{
    int val = 50;
    __asm volatile("MOV R0,%0": : "r"(val));
    for(;;);
    return 0;
}

