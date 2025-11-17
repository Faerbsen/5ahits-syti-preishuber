#include <Arduino.h>
#include "uart/uart.h"
#include <stdint.h>
#include <stdio.h>
#include <util/delay.h>

// LED Pins (8 LEDs für 8 Bits)
const uint8_t LED_PINS[8] = {2, 3, 4, 5, 6, 7, 8, 9};

int main()
{
  Serial.begin(115200);
  uart::init();
  
  // Initialize LED pins as output
  for (int i = 0; i < 8; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }
  
  while(1)
  {
    // examples:
    // uart::send('a');
    char data = uart::receive();
    
    // Show received data as bits on LEDs (Bit 0-7)
    for (int i = 0; i < 8; i++) {
      if (data & (1 << i)) {
        digitalWrite(LED_PINS[i], HIGH);  // Bit ist 1 -> LED leuchtet
      } else {
        digitalWrite(LED_PINS[i], LOW);   // Bit ist 0 -> LED aus
      }
    }
    
    _delay_ms(200);
    
    
  }
  return 0;
}
