# UART Labor – Protokoll
```
   Name: Tobias Mühlberger

  Datum: 07.11.2025

 Gruppe: [ ] Transmitter / [X] Receiver / [ ] Measurement
```

## 1. Aufgabenstellung
Implementiere einen UART-Receiver anhand des ATMega2560 Datenblatts.
Empfange Bytes und gib sie weiter:
- als LED-Muster oder Serial Print

## 2. Kurzbeschreibung der eigenen Lösung
Es werden 8 Bits gesendet. Für jedes Bit welches 1 ist, soll die entsprechende LED leuchten

## 3. Quellcode

uart.cpp:
```cpp
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
```

Main:
```cpp
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

```

## 4. Empfangene Daten
 - Byte 1: `01010101`
 - Byte 2: `11001100`
 - LED-/Serial-Ausgabe funktioniert? `[ ]` Ja `[X]`  Nein

## 5. Funktionstest
 - Verbindung mit Transmitter getestet? `[X]` Ja `[ ]` Nein
 - Funktioniert Empfang bei unterschiedlichen Bytes? `[ ]` Ja `[X]` Nein
 - Probleme / Beobachtungen: `_______________________________________`


## 6. Erkenntnisse
Baud-Rate beim seriellen Bildschirm ist anders wie bei UART, Register im Datenblatt sind einfacher rauszulesen als gedacht.


## 7. Zusammenfassung
Daten lesen aus dem Datenblatt besser gelernt. Wo steht was im Datenblatt? wie setze ich Register richtig im Code, wie verwende ich die baudrate
