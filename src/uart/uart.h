#pragma once

#include <stdint.h>

namespace uart {

  void init();
  void send(uint8_t data);
  uint8_t receive();
}