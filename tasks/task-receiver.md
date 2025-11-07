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
_(3–5 Sätze: Wie wurde empfangen? Wie wird die Ausgabe dargestellt?)_

## 3. Quellcode

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

## 4. Empfangene Daten
 - Byte 1: `__________`
 - Byte 2: `__________`
 - LED-/Serial-Ausgabe funktioniert? `[ ]` Ja `[ ]`  Nein

## 5. Funktionstest
 - Verbindung mit Transmitter getestet? `[ ]` Ja `[ ]` Nein
 - Funktioniert Empfang bei unterschiedlichen Bytes? `[ ]` Ja `[ ]` Nein
 - Probleme / Beobachtungen: `_______________________________________`


## 6. Erkenntnisse
(4–6 Bullet Points)


## 7. Zusammenfassung
(3–5 Sätze: Was habe ich technisch gelernt?)
