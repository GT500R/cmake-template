#pragma once

// Local
#include "../../../include/device_lib/IDigitalIoBridge.h"

// External library
#include <gmock/gmock.h>

namespace device_lib::test {

class GMockDigitalIoBridge : public IDigitalIoBridge
{
public:
  MOCK_METHOD(void, update, (), (const, override));
};

}
