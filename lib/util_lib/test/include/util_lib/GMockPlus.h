#pragma once

// Local
#include <../../include/util_lib/IPlus.h>

// External library
#include <gmock/gmock.h>

namespace util_lib::test {

class GMockPlus : public IPlus
{
public:
  MOCK_METHOD(uint8_t, plus, (const uint8_t, const uint8_t), (const, override));
};

}
