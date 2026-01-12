#pragma once

// Local
#include "IDigitalIoBridge.h"

// Internal library
#include <util_lib/Minus.h>
#include <util_lib/Plus.h>

namespace driver_lib {
class IDigitalInput;
class IDigitalOutput;
}

namespace device_lib {

class DigitalIoBridge : public IDigitalIoBridge
{
private:
  driver_lib::IDigitalInput& m_digitalInput;
  driver_lib::IDigitalOutput& m_digitalOutput;
  util_lib::Minus m_minus;
  util_lib::Plus m_plus;
  uint8_t m_answerToEverything1{0};
  uint8_t m_answerToEverything2{0};

public:
  DigitalIoBridge(driver_lib::IDigitalInput& digitalInput, driver_lib::IDigitalOutput& digitalOutput);
  ~DigitalIoBridge() = default;

  void update() override;
};

}
