#pragma once

// System
#include <cstdint>

namespace device_lib {

class IDigitalIoBridge
{
public:
  virtual ~IDigitalIoBridge() {};

  virtual void update() = 0;
};

}
