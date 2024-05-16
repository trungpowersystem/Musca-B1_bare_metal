#include <stdio.h>
#include <stdint.h>

#define IRQ3NUM 3
#define IRQ8NUM 8

void config_priority_and_enable_interrupt(uint8_t irqNum, uint8_t irqPriorityValue) {    
    uint32_t *pNVIC_IPRBase = (uint32_t*)0xE000E400;
    uint32_t *pNVIC_ISERBase = (uint32_t*)0xE000E100;
    // Find IPR offset
    uint8_t iprOffset = irqNum / 4;
    uint32_t *ipr = pNVIC_IPRBase + iprOffset;

    // Position in IPRx
    uint8_t iprPos = (irqNum % 4) * 8;

    // Config the priority
    *ipr &= ~(0xff << iprPos);             // Clear old value
    *ipr |= (irqPriorityValue << iprPos);  // Set new value


    // Find ISER offset
    uint8_t iserOffset = irqNum / 32;
    uint32_t *iser = pNVIC_ISERBase + iserOffset;

    // Position in ISERx
    uint8_t iserPos = irqNum % 32;

    // Enable the interrupt
    *iser |= (1 << iserPos);
}

void enable_intterupt_by_sw(uint8_t irqNum) {
    uint32_t *pNVIC_STIRBase = (uint32_t *)0xE000EF00;
    *pNVIC_STIRBase = (irqNum & 0x1FF);
}

int main(void)
{
    // Hello, Boot sequence is finished. I'm in main function now!!

    // Config priority for interrupts
    config_priority_and_enable_interrupt(IRQ3NUM, 0xA);
    config_priority_and_enable_interrupt(IRQ8NUM, 0x9);

    // Enable the interrupt by software
    enable_intterupt_by_sw(IRQ3NUM);
    return 0;
}

void Interrupt3_Handler(void) {
    //I'm in interrupt 3 handler
    enable_intterupt_by_sw(IRQ8NUM);
    int a = 8;
}

void Interrupt8_Handler(void) {
    //I'm in interrupt 8 handler
}