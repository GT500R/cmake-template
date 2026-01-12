#pragma once

// Local
#include "../include/device_lib/DigitalIoBridge.h"

// Internal library
#include <driver_lib/GMockDigitalInput.h>
#include <driver_lib/GMockDigitalOutput.h>

// External library
#include <gtest/gtest.h>

namespace device_lib::test {

class GTestDigitalIoBridge : public ::testing::Test
{
protected:
  std::unique_ptr<driver_lib::test::GMockDigitalInput> m_mockDigitalInput;
  std::unique_ptr<driver_lib::test::GMockDigitalOutput> m_mockDigitalOutput;

  std::unique_ptr<device_lib::DigitalIoBridge> m_digitalIoBridge;

  void SetUp() override;    // will be called before each test function is executed.
  void TearDown() override; // will be called after every test function.
};

}
