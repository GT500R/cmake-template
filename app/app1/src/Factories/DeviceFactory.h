#pragma once

// Local
#include "DriverFactory.h"

// Internal library
#include <device_lib/DigitalIoBridge.h>

namespace app1 {

class DeviceFactory
{
private:
  device_lib::DigitalIoBridge m_digitalIoBridge;

public:
  DeviceFactory(DriverFactory& driverFactory);
  ~DeviceFactory() = default;

  // clang-format off
  device_lib::IDigitalIoBridge& getDigitalIoBridge() { return m_digitalIoBridge; }
  // clang-format on
};

}
