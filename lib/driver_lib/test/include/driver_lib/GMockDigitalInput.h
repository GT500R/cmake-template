#pragma once

// Local
#include "../../../include/driver_lib/IDigitalInput.h"

// External library
#include <gmock/gmock.h>

namespace driver_lib::test {

class GMockDigitalInput : public IDigitalInput
{
public:
  MOCK_METHOD(bool, isOn, (), (const, override));
  MOCK_METHOD(bool, isOff, (), (const, override));
};

}
