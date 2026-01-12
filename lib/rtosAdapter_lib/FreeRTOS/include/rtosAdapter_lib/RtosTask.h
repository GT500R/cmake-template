#pragma once

// Local
#include "../../../include/rtosAdapter_lib/ITask.h"
#include "../../../include/rtosAdapter_lib/RtosPriority.h"

// Internal library
#include <FreeRTOS.h>
#include <task.h>

namespace rtos_adapter_lib {

class RtosTask : public ITask
{
public:
  RtosTask(const ERtosPriority taskPriority);
  virtual ~RtosTask() = default;

  void create(const char* taskName,
              void (*taskFunction)(void*),
              uint32_t* const taskStackBuffer,
              const uint32_t taskStackSizeBytes,
              void* arguments) override;
  void delayPeriod(const uint16_t ms) const override;
  void suspend() const override;
  void resume() const override;
  void* getTaskHandle() const override;

private:
  TaskHandle_t m_taskHandle;
  ERtosPriority m_taskPriority;
  StaticTask_t m_taskControlBlock;
};

}
