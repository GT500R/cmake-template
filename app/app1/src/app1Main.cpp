#include "app1Main.h"

// Local
#include "../Core/Inc/app_freertos.h"
#include "Factories/DeviceFactory.h"
#include "Factories/DriverFactory.h"

// Internal library
#include <device_lib/IDigitalIoBridge.h>

namespace app1 {

void app1Main()
{
  DriverFactory m_driverFactory;
  DeviceFactory m_deviceFactory(m_driverFactory);

  device_lib::IDigitalIoBridge& digitalIoBridge = m_deviceFactory.getDigitalIoBridge();

  APP_setMainTaskPriorityLow();

  while (1)
  {
    digitalIoBridge.update();

    APP_taskDelayMs(1000);
  }
}

}

// Use wrapper for main method called from C code (C code does not understand namespaces)
void app1MainWrapper()
{
  app1::app1Main();
}
