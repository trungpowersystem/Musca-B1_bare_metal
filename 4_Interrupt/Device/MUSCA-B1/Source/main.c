#include "stdio.h"
#include "stdint.h"

#define IRQ3NUM 3
#define IRQ8NUM 8

uint32_t *pNVIC_IPRBase = (uint32_t *)0xE000E400;
uint32_t *pNVIC_ISERBase = (uint32_t *)0xE000E100;
uint32_t *pNVIC_ISPRBase = (uint32_t *)0xE000E200;

void config_priority_interrupt(uint8_t irqNum, uint8_t irqPriorityValue) {
    // Find iprx
    uint8_t iprX = irqNum / 4;
    uint32_t *ipr = pNVIC_IPRBase + iprX;

    // Position in iprx
    uint8_t pos = (irqNum % 4) * 8;

    // Config the priority
    *ipr &= ~(0xff << pos);             // Clear old value
    *ipr |= (irqPriorityValue << pos);  // Set new value
}

int main(void)
{
    // Hello, Boot sequence is finished. I'm in main function now!!

    // Config priority for interrupts
    config_priority_interrupt(IRQ3NUM, 0xA);
    config_priority_interrupt(IRQ8NUM, 0xA);

    // Set the interrupt pending bit in the NVIC IPR
    *pNVIC_ISPRBase |= (1 << IRQ3NUM);

    // Enable the interrupt in NVIC
    *pNVIC_ISERBase |= (1 << IRQ3NUM);
    *pNVIC_ISERBase |= (1 << IRQ8NUM);
    return 0;
}

void Interrupt3_Handler(void) {
    //I'm in interrupt 3 handler
}

void Interrupt8_Handler(void) {
    //I'm in interrupt 8 handler
}