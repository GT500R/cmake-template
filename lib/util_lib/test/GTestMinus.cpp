#include "GTestMinus.h"

namespace util_lib::test {

void GTestMinus::SetUp()
{
  m_minus = std::make_unique<Minus>();
}

void GTestMinus::TearDown()
{
  m_minus.reset();
}

TEST_F(GTestMinus, testDifference_42Minus2)
{
  // Arrange

  // Expect

  // Act
  const uint8_t difference = m_minus->difference(42, 2);

  // Assert
  EXPECT_EQ(difference, 40);
}

}
