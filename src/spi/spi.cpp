#include "spi/spi.h"
#include <avr/io.h>
#include <util/delay.h>

namespace spi {
    

  void init(void)
  {
    //enable SPI
    SPCR |= (1<<SPE);
    //set so slave
    SPCR &= ~(1<<MSTR);
    //Set prescaler to fosc/16
    SPCR |= (1<<SPR0);

    //MISO Output all other Input
    DDRB &= ~(1<<DDB1);
    DDRB &= ~(1<<DDB1);
    DDRB &= ~(1<<DDB2);
    DDRB |= (1<<DDB3);

      

  }


  char receive( void )
  {
    while(!(SPSR & (1<<SPIF)));
    return SPDR;
    
  }
}