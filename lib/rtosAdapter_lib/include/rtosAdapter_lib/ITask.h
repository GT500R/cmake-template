#pragma once

// Local
#include "RtosPriority.h"

// System
#include <cstdint>

namespace rtos_adapter_lib {

class ITask
{
public:
  virtual ~ITask()
  {}
  virtual void create(const char* taskName,
                      void (*taskFunction)(void*),
                      uint32_t* const taskStackBuffer,
                      const uint32_t taskStackSizeBytes,
                      void* arguments) = 0;

  virtual void delayPeriod(const uint16_t ms) const = 0;
  virtual void suspend() const = 0;
  virtual void resume() const = 0;
  virtual void* getTaskHandle() const = 0;
};

}
