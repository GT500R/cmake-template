#pragma once

// System
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

  void APP_setMainTaskPriorityLow();
  void APP_taskDelayMs(const uint32_t delayMs);

#ifdef __cplusplus
}
#endif
