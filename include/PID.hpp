namespace controller {
// @brief Gains struct
struct Gains {
  Gains() : kp(0), kd(0), ki(0), isat(0) { ; }
  Gains(float kp, float kd, float ki, float isat)
      : kp(kp), kd(kd), ki(ki), isat(isat) {
    ;
  }
  float kp;
  float kd;
  float ki;
  float isat;
};
// @brief PIDController class
class PIDController {
 public:
  /** @brief Constructor which takes gains as input,initialize controller
   * variables
   *  @param[in] inputGains Gains struct
   */
  explicit PIDController(Gains inputGains);
  /**
   * @brief Compute function which takes input velocity and target velocity as
   * input and returns a controller output
   * @param[in] inputVel Input velocity
   * @param[in] targetVel Target velocity
   * @return control signal
   */
  float compute(float inputVel, float targetVel);
  /**
   * @brief Sets all stored historical variables to zero. Brings controller to
   * standstill.
   */
  void resetController();

 private:
  Gains gains;
  static const constexpr int delta_t = 1;
  float motor_integral;
  float motor_prev_error;
};
};  // namespace controller