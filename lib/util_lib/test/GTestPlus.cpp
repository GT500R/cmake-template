#include "GTestPlus.h"

namespace util_lib::test {

void GTestPlus::SetUp()
{
  m_plus = std::make_unique<Plus>();
}

void GTestPlus::TearDown()
{
  m_plus.reset();
}

TEST_F(GTestPlus, testSum_42Plus2)
{
  // Arrange

  // Expect

  // Act
  const uint8_t sum = m_plus->sum(42, 2);

  // Assert
  EXPECT_EQ(sum, 44);
}

}
