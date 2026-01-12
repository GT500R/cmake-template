#pragma once

// Local
#include "../include/util_lib/Plus.h"

// External library
#include <gtest/gtest.h>

namespace util_lib::test {

class GTestPlus : public ::testing::Test
{
protected:
  std::unique_ptr<Plus> m_plus;

  void SetUp() override;    // will be called before each test function is executed.
  void TearDown() override; // will be called after every test function.
};

}
