namespace controller{
struct Gains{
};
class PIDController{
public:
PIDController(Gains inputGains);
float compute(float inputVel,float targetVel);
void resetController();
private:
};
};