namespace controller{
// @brief Gains struct
struct Gains{
};
// @brief PIDController class
class PIDController{
public:
/** @brief Constructor which takes gains as input,initialize controller variables
*  @param[in] inputGains Gains struct
*/
PIDController(Gains inputGains);
/**
* @brief Compute function which takes input velocity and target velocity as input and returns a controller output
* @param[in] inputVel Input velocity
* @param[in] targetVel Target velocity
* @return control signal
*/
float compute(float inputVel,float targetVel);
/**
* @brief Sets all stored historical variables to zero. Brings controller to standstill.
*/
void resetController();
private:
};
};