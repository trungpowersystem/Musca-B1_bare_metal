#ifndef SYSTEM_MUSCA_B1_H
#define SYSTEM_MUSCA_B1_H

#ifdef __cplusplus
extern "C" {
#endif

/**
  \brief Exception / Interrupt Handler Function Prototype
*/
typedef void(*VECTOR_TABLE_Type)(void);

/**
  \brief System Clock Frequency (Core Clock)
*/
extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock) */

/**
  \brief Setup the microcontroller system.

   Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);

/**
  \brief  Update SystemCoreClock variable.

   Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define  SYS_CLOCK       (50000000UL)     /* PLL Clock Div4 for SYSCLK frequency */
#define  X32K_CLOCK      (   32768UL)     /* Oscillator frequency */

#define  SYSTEM_CLOCK    (SYS_CLOCK)
 
 

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_MUSCA_B1_H */
