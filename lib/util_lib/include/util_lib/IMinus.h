#pragma once

// System
#include <stdint.h>

namespace util_lib {

class IMinus
{
public:
  virtual ~IMinus() = default;

  virtual uint8_t difference(const uint8_t minuend, const uint8_t subtrahend) const = 0;
};

}
