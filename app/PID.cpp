#include "PID.hpp"

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

float PIDController::compute(float inputVel, float targetVel) { return 0.0; }

void PIDController::resetController() { ; }

}  // namespace controller
