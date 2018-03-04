#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    p_error = 0;
    i_error = 0;
    d_error = 0;
    pre_cte = 0;

	// params for twiddle
	//tol = 0.2;
	//best_error = 0;
	//dp = [1,1,1]
}

void PID::UpdateError(double cte) {
	p_error = cte;
    i_error += cte;  
    d_error = cte - pre_cte;
}

double PID::TotalError() {
    return Control();
}

double PID::Control() {
    double output = -Kp * p_error - Kd * d_error  - Ki * i_error;
    pre_cte = p_error;
    return output;
}
