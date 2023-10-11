#include <gtest/gtest.h>

#include <PID.hpp>

// @brief: Test to check if the controller output is 1.0 for kp=1.0 kd=0.0
// ki=0.0
TEST(pid_test_1, proportional_test) {
  controller::Gains gains(1.0, 0.0, 0.0, 0.0);
  controller::PIDController pid(gains);
  EXPECT_FLOAT_EQ(1.0, pid.compute(-1, 0));
}

// @brief: Test to check if the controller output is 1 for kp=0 kd=0 ki=1
TEST(pid_test_2, integral_test) {
  controller::Gains gains(0.0, 0.0, 1.0, 10);
  controller::PIDController pid(gains);
  EXPECT_FLOAT_EQ(1.0, pid.compute(-1, 0));
}

// @brief: Test to check if the controller resets succesfully
TEST(pid_test_3, reset_test) {
  controller::Gains gains(0, 1.0, 0, 10);
  controller::PIDController pid(gains);
  // @brief: Create controller history by calling compute  twice
  EXPECT_FLOAT_EQ(1.0, pid.compute(-1, 0));
  EXPECT_FLOAT_EQ(0.0, pid.compute(-1, 0));
  // reset controller
  pid.resetController();
  // controller should behave as the first compute call
  EXPECT_FLOAT_EQ(1.0, pid.compute(-1, 0));
}
