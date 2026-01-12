#pragma once

// Local
#include "../../../include/rtosAdapter_lib/ITask.h"

// External library
#include <gmock/gmock.h>

namespace rtos_adapter_lib::test {

class GMockTask : public ITask
{
public:
  MOCK_METHOD(void, create, (const char*, void (*)(void*), uint32_t* const, const uint32_t, void*), (override));
  MOCK_METHOD(void, delayPeriod, (const uint16_t), (const, override));
  MOCK_METHOD(void, suspend, (), (const, override));
  MOCK_METHOD(void, resume, (), (const, override));
  MOCK_METHOD(void*, getTaskHandle, (), (const, override));
};

}
