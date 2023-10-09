namespace controller{
struct Gains{
};
class PIDController{
public:
PIDController(Gains gains);
float compute(float outputVel,float inputVel);
void resetController();
private:
};
};