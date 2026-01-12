#pragma once

// Local
#include "IMinus.h"

namespace util_lib {

class Minus : public IMinus
{
public:
  Minus() = default;
  ~Minus() = default;

  uint8_t difference(const uint8_t minuend, const uint8_t subtrahend) const override;
};

}
