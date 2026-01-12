#include "GTestDigitalIoBridge.h"

// Local
#include "../include/device_lib/DigitalIoBridge.h"

namespace device_lib::test {

void GTestDigitalIoBridge::SetUp()
{
  m_mockDigitalInput = std::make_unique<driver_lib::test::GMockDigitalInput>();
  m_mockDigitalOutput = std::make_unique<driver_lib::test::GMockDigitalOutput>();

  m_digitalIoBridge = std::make_unique<device_lib::DigitalIoBridge>(*m_mockDigitalInput.get(), *m_mockDigitalOutput.get());
}

void GTestDigitalIoBridge::TearDown()
{
  m_digitalIoBridge.reset();
  m_mockDigitalInput.reset();
  m_mockDigitalOutput.reset();
}

TEST_F(GTestDigitalIoBridge, testUpdate_Off)
{
  // Arrange

  // Expect
  EXPECT_CALL(*m_mockDigitalInput, isOn()).Times(1).WillOnce(testing::Return(false));
  EXPECT_CALL(*m_mockDigitalOutput, setOn()).Times(0);
  EXPECT_CALL(*m_mockDigitalOutput, setOff()).Times(1);

  // Act
  m_digitalIoBridge->update();

  // Assert
}

TEST_F(GTestDigitalIoBridge, testUpdate_On)
{
  // Arrange

  // Expect
  EXPECT_CALL(*m_mockDigitalInput, isOn()).Times(1).WillOnce(testing::Return(true));
  EXPECT_CALL(*m_mockDigitalOutput, setOn()).Times(1);
  EXPECT_CALL(*m_mockDigitalOutput, setOff()).Times(0);

  // Act
  m_digitalIoBridge->update();

  // Assert
}

}
