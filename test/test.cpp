#include <gtest/gtest.h>
#include "PID.hpp"

TEST(pid_test_1, this_should_fail) {
  controller::Gains gains;
  controller::PIDController pid(gains);
  EXPECT_EQ(0.0, pid.compute(1, 0));
}
