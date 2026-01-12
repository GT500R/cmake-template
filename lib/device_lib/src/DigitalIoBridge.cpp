#include "../include/device_lib/DigitalIoBridge.h"

// Internal library
#include <driver_lib/IDigitalInput.h>
#include <driver_lib/IDigitalOutput.h>

namespace device_lib {

DigitalIoBridge::DigitalIoBridge(driver_lib::IDigitalInput& digitalInput,
                                 driver_lib::IDigitalOutput& digitalOutput) :
  m_digitalInput(digitalInput),
  m_digitalOutput(digitalOutput)
{
  m_answerToEverything1 = m_minus.difference(45, 3);
  m_answerToEverything2 = m_plus.sum(40, 2);
}

void DigitalIoBridge::update()
{
  const bool inputValue = m_digitalInput.isOn();
  inputValue ? m_digitalOutput.setOn() : m_digitalOutput.setOff();
}

}
