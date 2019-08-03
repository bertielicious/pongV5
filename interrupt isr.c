#include "config.h"
#include "interrupt isr.h"



void interrupt isr(void)
{
    
   /* if ( INTCONbits.TMR0IF == 1)
    {
        //GREEN_LED = ~GREEN_LED;
        
         TMR0 = 0x00; 
         INTCONbits.TMR0IF = 0; 
    }*/
    if (PIR1bits.TMR1IF == 1 )       // TMR1 is 1 sec gravity timer interrupt        
    {  
       
        TMR1H = 0x63;               // preload TMR1 to generate a 125ms interrupt
        TMR1L = 0xc0;
      
       
        
         
        GREEN_LED = ~GREEN_LED;
        
       
        PIR1bits.TMR1IF = 0;  
    }
        
}

        
   