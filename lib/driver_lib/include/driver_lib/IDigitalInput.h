#pragma once

namespace driver_lib {

class IDigitalInput
{
public:
  virtual ~IDigitalInput() {};

  virtual bool isOn() const = 0;
  virtual bool isOff() const = 0;
};

}
