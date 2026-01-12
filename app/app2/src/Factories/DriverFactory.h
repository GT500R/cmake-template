#pragma once

// Internal library
#include <driver_lib/DigitalInput.h>
#include <driver_lib/DigitalOutput.h>

namespace app2 {

class DriverFactory
{
private:
  driver_lib::DigitalInput m_digitalInput1;  
  driver_lib::DigitalOutput m_digitalOutput1;

public:
  DriverFactory();
  ~DriverFactory() = default;

  // clang-format off
  driver_lib::IDigitalInput& getDigitalInput1() { return m_digitalInput1; }
  driver_lib::IDigitalOutput& getDigitalOutput1() { return m_digitalOutput1; }
  // clang-format on
};

}
