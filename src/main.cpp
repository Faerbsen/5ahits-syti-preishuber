#include <Arduino.h>
#include "spi/spi.h"
#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>

int main()
{
  Serial.begin(115200);
  spi::init();
  
  
  while(1)
  {
    Serial.println("!");
    char data = spi::receive();
    Serial.println(".");
    Serial.println(data);
  }
}


