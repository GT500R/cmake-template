#pragma once

// Local
#include "../include/util_lib/Minus.h"

// External library
#include <gtest/gtest.h>

namespace util_lib::test {

class GTestMinus : public ::testing::Test
{
protected:
  std::unique_ptr<Minus> m_minus;

  void SetUp() override;    // will be called before each test function is executed.
  void TearDown() override; // will be called after every test function.
};

}
