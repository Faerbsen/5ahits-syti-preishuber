#include "uart/uart.h"
#include <avr/io.h>
#include <util/delay.h>

namespace uart {

  void init()
  {
    UBRR0 = 0; 
    //UDR0
    UCSR0C &= (0 << UMSEL00) & (0<<UMSEL01);
    UCSR0C |= (1<< UPM00) | (1<< UPM01);
    UCSR0A |= (1<<U2X0);
    UBRR0L = 0b11001111; //set ubbr0l to 207 - ATMega hat frequenz 16Mhz - Baudrate dadurch 9600
    
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    UBRR0 = 9600;
  }


  uint8_t receive( void )
  {
    /* Wait for data to be received */
    while ( !(UCSR0A & (1<<RXC0)) );
    /* Get and return received data from buffer */
    return UDR0;
  }
}