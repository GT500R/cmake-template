#pragma once

// Local
#include "../../../include/driver_lib/IDigitalInput.h"

// Internal library
#include <stm32g4xx_hal.h>

namespace driver_lib {

class DigitalInput : public IDigitalInput
{
private:
  GPIO_TypeDef* m_port{nullptr};
  uint16_t m_pin{0};
  const char* m_name{""};
  bool m_isLowActive{false};

public:
  DigitalInput(GPIO_TypeDef* const port, const uint16_t pin, const char* name, const bool isLowActive = false);
  virtual ~DigitalInput() = default;
  bool isOn() const override;
  bool isOff() const override;
};

}
