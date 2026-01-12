#pragma once

// Local
#include "../../../include/driver_lib/IDigitalOutput.h"

// Internal library
#include <stm32g4xx_hal.h>

namespace driver_lib {

class DigitalOutput : public IDigitalOutput
{
private:
  GPIO_TypeDef* m_port{nullptr};
  uint16_t m_pin{0};
  const char* m_name{""};
  bool m_isLowActive{false};

public:
  DigitalOutput(GPIO_TypeDef* const port, const uint16_t pin, const char* name, const bool isLowActive = false);
  virtual ~DigitalOutput() = default;
  void setOn() override;
  void setOff() override;
  void setToggle() override;
  bool isOn() const override;
  bool isOff() const override;
};

}
