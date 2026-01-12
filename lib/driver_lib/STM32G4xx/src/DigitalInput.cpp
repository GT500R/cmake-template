#include "../include/driver_lib/DigitalInput.h"

namespace driver_lib {

DigitalInput::DigitalInput(GPIO_TypeDef* const port, const uint16_t pin, const char* name, const bool isLowActive) :
  m_port(port),
  m_pin(pin),
  m_name(name),
  m_isLowActive(isLowActive)
{
  // check parameter
  assert_param(IS_GPIO_PIN(pin));
}

bool DigitalInput::isOn() const
{
  const bool isOn = m_isLowActive ? HAL_GPIO_ReadPin(m_port, m_pin) == GPIO_PIN_RESET
                                  : HAL_GPIO_ReadPin(m_port, m_pin) == GPIO_PIN_SET;
  return isOn;
}

bool DigitalInput::isOff() const
{
  const bool isOff = m_isLowActive ? HAL_GPIO_ReadPin(m_port, m_pin) == GPIO_PIN_SET
                                   : HAL_GPIO_ReadPin(m_port, m_pin) == GPIO_PIN_RESET;
  return isOff;
}

}
