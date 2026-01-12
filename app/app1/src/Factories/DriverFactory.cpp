#include "DriverFactory.h"

// Local
#include "../../Core/Inc/main.h"

namespace app1 {

DriverFactory::DriverFactory() :
  m_digitalInput1(PIN_DigitalInput1_GPIO_Port, PIN_DigitalInput1_Pin, "Input1"),
  m_digitalOutput1(PIN_DigitalOutput1_GPIO_Port, PIN_DigitalOutput1_Pin, "Output1")
{}

}
