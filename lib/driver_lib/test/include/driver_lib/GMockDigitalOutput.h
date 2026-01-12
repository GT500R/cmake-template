#pragma once

// Local
#include "../../../include/driver_lib/IDigitalOutput.h"

// External library
#include <gmock/gmock.h>

namespace driver_lib::test {

class GMockDigitalOutput : public IDigitalOutput
{
public:
  MOCK_METHOD(void, setOn, (), (override));
  MOCK_METHOD(void, setOff, (), (override));
  MOCK_METHOD(void, setToggle, (), (override));
  MOCK_METHOD(bool, isOn, (), (const, override));
  MOCK_METHOD(bool, isOff, (), (const, override));
};

}
