#include <gtest/gtest.h>
#include "PID.hpp"

// @brief: Test to check if the controller output is 1.0 for kp=1.0 kd=0.0 ki=0.0
TEST(pid_test_1, proportional_test) {
  controller::Gains gains;
  controller::PIDController pid(gains);
  EXPECT_FLOAT_EQ(1.0, pid.compute(1, 0));
}
