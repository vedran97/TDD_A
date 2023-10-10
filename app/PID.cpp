#include "PID.hpp"

#include <algorithm>

namespace controller {
/**
 * @brief Store controller gains
 * @param[in] inputGains Gains struct
 */
PIDController::PIDController(controller::Gains inputGains) {
  gains = inputGains;
  motor_integral = 0;
  motor_prev_error = 0;
}

float PIDController::compute(float inputVel, float targetVel) {
  // Calculate error
  float error = targetVel - inputVel;

  // Calculate integral and derivative terms
  motor_integral += error * delta_t;
  motor_integral = std::min(std::max(motor_integral, -gains.isat),
                            gains.isat);  // Constrain integral term
  float derivative = (error - motor_prev_error) / delta_t;
  motor_prev_error = error;

  // Calculate output
  float output =
      gains.kp * error + gains.ki * motor_integral + gains.kd * derivative;

  return output;
}

void PIDController::resetController() {
  // Reset internal variables
  motor_integral = 0.0;
  motor_prev_error = 0.0;
}
}  // namespace controller
