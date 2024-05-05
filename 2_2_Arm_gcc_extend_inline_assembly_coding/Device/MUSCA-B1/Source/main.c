#include "stdio.h"

int main(void)
{
    int R1;

    //Read R1 register to R1 variable
    __asm volatile("MRS %0,r1":"=r"(R1));

    for(;;);
    return 0;
}

