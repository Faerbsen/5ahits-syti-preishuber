#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "example_lib/math.h"

static uint8_t leds_on = 0x00;
static uint8_t leds_off = 0x00;
constexpr uint16_t pause = 250;

void app_init()
{
  // configure all pins of port F as outputs
  DDRF = 0xFF;

  // configure start value
  leds_on = 0x01;
}

void app_run()
{
  while(1)
  {
    PORTF = leds_on;
    _delay_ms(pause);

    PORTF = leds_off;
    _delay_ms(pause);

    leds_on = example_lib::add(leds_on, 1);
  }
}

int main()
{
  app_init();
  app_run();
  return 0;
}
