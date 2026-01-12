#pragma once

namespace driver_lib {

class IDigitalOutput
{
public:
  virtual ~IDigitalOutput() {};

  virtual void setOn() = 0;
  virtual void setOff() = 0;
  virtual void setToggle() = 0;
  virtual bool isOn() const = 0;
  virtual bool isOff() const = 0;
};

}
