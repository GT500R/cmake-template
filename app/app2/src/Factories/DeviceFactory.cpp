#include "DeviceFactory.h"

namespace app2 {

DeviceFactory::DeviceFactory(DriverFactory& driverFactory) :
  m_digitalIoBridge(driverFactory.getDigitalInput1(),
                    driverFactory.getDigitalOutput1())

{}

}
