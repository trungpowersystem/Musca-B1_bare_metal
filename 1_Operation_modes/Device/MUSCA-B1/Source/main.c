#include "stdio.h"

/* This function executes in THREAD MODE of the processor */
void generate_interrupt()
{
    uint32_t *pSTIR  = (uint32_t*)0xE000EF00;
    uint32_t *pISER0 = (uint32_t*)0xE000E100;

    //enable IRQ3 interrupt
    *pISER0 |= ( 1 << 3);

    //generate an interrupt from software for IRQ3
    *pSTIR = (3 & 0x1FF);

}

/* This function executes in THREAD MODE of the processor */
int main(void)
{
    // Before interrupt

    generate_interrupt();

    // After interrupt

    for(;;);
    return 0;
}

/* This function(ISR) executes in HANDLER MODE of the processor */
void Interrupt3_Handler(void)
{
    // I'm in interrupt 3 ISA
}
