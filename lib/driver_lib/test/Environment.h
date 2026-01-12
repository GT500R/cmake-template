#pragma once

// External library
#include <gtest/gtest.h>

class Environment : public ::testing::Environment
{
public:
  void SetUp() override
  { // This code is executed before any test is run
  }
  void TearDown() override
  { // This code is executed after all tests are run
  }
};
