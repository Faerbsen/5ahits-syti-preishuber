#include <Arduino.h>
#include "uart/uart.h"
#include <stdint.h>
#include<stdio.h>
#include <util/delay.h>

int main()
{
  Serial.begin(115200);
  uart::init();
  while(1)
  {
    // examples:
    // uart::send('a');
    char data = uart::receive();
    _delay_ms(200);
    Serial.println(data);
    
  }
  return 0;
}
