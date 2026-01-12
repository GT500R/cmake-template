#pragma once

// Local
#include <../../include/util_lib/IMinus.h>

// External library
#include <gmock/gmock.h>

namespace util_lib::test {

class GMockMinus : public IMinus
{
public:
  MOCK_METHOD(uint8_t, minus, (const uint8_t, const uint8_t), (const, override));
};

}
