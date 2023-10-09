#include "PID.hpp"

namespace controller {
/**
 * @brief Store controller gains
 * @param[in] inputGains Gains struct
 */
PIDController::PIDController(controller::Gains inputGains) { ; }

float PIDController::compute(float inputVel, float targetVel) { return 0.0; }

void PIDController::resetController() { ; }

}  // namespace controller
