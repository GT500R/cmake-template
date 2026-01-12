#include "../include/rtosAdapter_lib/RtosTask.h"

namespace rtos_adapter_lib {

RtosTask::RtosTask(const ERtosPriority taskPriority) :
  m_taskPriority(taskPriority)
{}

void RtosTask::create(const char* taskName,
                      void (*taskFunction)(void*),
                      uint32_t* const taskStackBuffer,
                      const uint32_t taskStackSizeBytes,
                      void* arguments)
{
  m_taskHandle = xTaskCreateStatic(static_cast<TaskFunction_t>(taskFunction),
                                   taskName,
                                   taskStackSizeBytes / 4, // Bytes to DWord
                                   arguments,
                                   static_cast<UBaseType_t>(m_taskPriority),
                                   taskStackBuffer,
                                   &m_taskControlBlock);
}

void RtosTask::delayPeriod(const uint16_t ms) const
{
  vTaskDelay(pdMS_TO_TICKS(ms));
}

void RtosTask::suspend() const
{
  vTaskSuspend(m_taskHandle);
}

void RtosTask::resume() const
{
  vTaskResume(m_taskHandle);
}

void* RtosTask::getTaskHandle() const
{
  return static_cast<void*>(m_taskHandle);
}

}
