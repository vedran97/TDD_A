#include <gtest/gtest.h>
#include "PID.hpp"

TEST(pid_test, this_should_fail) {
  controller::Gains gains;
  controller::PIDController pid(gains);
  EXPECT_EQ(1.1, pid.compute(0, 0));
}
