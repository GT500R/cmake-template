#include "DeviceFactory.h"

namespace app1 {

DeviceFactory::DeviceFactory(DriverFactory& driverFactory) :
  m_digitalIoBridge(driverFactory.getDigitalInput1(),
                    driverFactory.getDigitalOutput1())

{}

}
