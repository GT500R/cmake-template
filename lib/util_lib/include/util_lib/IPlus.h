#pragma once

// System
#include <stdint.h>

namespace util_lib {

class IPlus
{
public:
  virtual ~IPlus() = default;

  virtual uint8_t sum(const uint8_t summand1, const uint8_t summand2) const = 0;
};

}
