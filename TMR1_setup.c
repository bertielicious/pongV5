
#include <pic16f1459.h>
#include "config.h"
void TMR1_setup(void)
{
    //TMR1H = 0xf0;          
    //TMR1L = 0x5f; 
    TMR1H = 0x63;          // generate an interrupt every 0.02 s (50 Hz))
    TMR1L = 0xc0; 
    T1CONbits.TMR1CS0 = LOW;
    T1CONbits.TMR1CS1 = LOW;    // instruction clock is source Fosc/4 = 250kHz
    T1CONbits.T1CKPS0 = LOW;
    T1CONbits.T1CKPS1 = LOW;   // 1:1 prescale 
    PIE1bits.TMR1IE = HIGH;
    INTCONbits.PEIE = HIGH;
    INTCONbits.GIE = HIGH;
    PIR1bits.TMR1IF = LOW;      // clear TMR1 interrupt flag
    T1CONbits.TMR1ON = HIGH;          
}
