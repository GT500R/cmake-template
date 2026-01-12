#include "../include/util_lib/Minus.h"

namespace util_lib {

uint8_t Minus::difference(const uint8_t minuend, const uint8_t subtrahend) const
{
  const uint8_t difference = minuend - subtrahend;
  return difference;
}

}
