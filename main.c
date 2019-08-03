/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 20 July 2019, 11:07
 */
/*                  16f1459
 *                  ---------
 *   +5 Volts    1 |Vdd      | 20 0 Volts
 *Player select  2 |RA5      | 19
 * Paddle up  L  3 |RA4      | 18
 *    MCLR/ RST  4 |         | 17
 *    GREEN LED  5 |RC5      | 16
 *           CE  6 |RC4      | 15
 *RST op to 5110 7 |         | 14  RC2 Paddle down L
 *           SS  8 |         | 13 
 *           SDO 9 |         | 12
 *           TX 10 |         | 11  SCK
 *                  ---------
 
 */



#include "config.h"
#include <stdio.h>
#include "main.h"
#include "config_osc.h"
#include "setup_ports.h"
#include "init_spi.h"
#include "set_usart.h"
#include "putch.h"
#include "lcd_setup.h"
#include "TMR0_setup.h"
#include "TMR1_setup.h"
#include "interrupt isr.h"
#include "lcdWrite.h"
#include "set_address.h"
#include "set_game_area.h"
#include "TMR1_setup.h"
#include "eraseBall.h"
#include "animate_rht.h"


void main(void) 
{
config_osc();       // internal clock frequency = 8MHz
setup_ports();      
init_spi();
set_usart();
lcd_setup();        // configures the LCD
set_game_area();
uchar col, row, offsetDwn = 0;
for(col = 0; col < 83; col++)
{   
    
    animate_rht(col,1,0,offsetDwn);   //colInit = 0; page = 1; offsetUp = 0; offsetDwn = 1
    if(col%17 == 0)
    {
        offsetDwn++;
    }
    __delay_ms(100);
    if(col <81)
    eraseBall(col,1);         // colInit = 0; page = 1;
}
/*for(col = 82; col >= 0; col--)
{   
    
    animate_rht(col,1,0,offsetUp);   //colInit = 0; page = 1; offsetUp = 0; offsetDwn = 1
    if(col%17 == 0)
    {
        offsetUp++;
    }
     __delay_ms(150);
    if(col >=3)
    eraseBall(col,1);         // colInit = 0; page = 1;
   
}*/

while(1)
    {
    
    }       
}
