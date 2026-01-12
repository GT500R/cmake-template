#include "../include/driver_lib/DigitalOutput.h"

namespace driver_lib {

DigitalOutput::DigitalOutput(GPIO_TypeDef* const port, const uint16_t pin, const char* name, const bool isLowActive) :
  m_port(port),
  m_pin(pin),
  m_name(name),
  m_isLowActive(isLowActive)
{
  // check parameter
  assert_param(IS_GPIO_PIN(pin));
}

void DigitalOutput::setOn()
{
  m_isLowActive ? HAL_GPIO_WritePin(m_port, m_pin, GPIO_PIN_RESET) : HAL_GPIO_WritePin(m_port, m_pin, GPIO_PIN_SET);
}

void DigitalOutput::setOff()
{
  m_isLowActive ? HAL_GPIO_WritePin(m_port, m_pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(m_port, m_pin, GPIO_PIN_RESET);
}

void DigitalOutput::setToggle()
{
  HAL_GPIO_TogglePin(m_port, m_pin);
}

bool DigitalOutput::isOn() const
{
  const bool isOn = m_isLowActive ? HAL_GPIO_ReadPin(m_port, m_pin) == GPIO_PIN_RESET
                                  : HAL_GPIO_ReadPin(m_port, m_pin) == GPIO_PIN_SET;
  return isOn;
}

bool DigitalOutput::isOff() const
{
  const bool isOff = m_isLowActive ? HAL_GPIO_ReadPin(m_port, m_pin) == GPIO_PIN_SET
                                   : HAL_GPIO_ReadPin(m_port, m_pin) == GPIO_PIN_RESET;
  return isOff;
}

}
