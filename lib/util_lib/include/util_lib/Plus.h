#pragma once

// Local
#include "IPlus.h"

namespace util_lib {

class Plus : public IPlus
{
public:
  Plus() = default;
  ~Plus() = default;

  uint8_t sum(const uint8_t summand1, const uint8_t summand2) const override;
};

}
