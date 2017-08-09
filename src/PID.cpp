#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Kd, double Ki) {
	Kp_ = Kp;
	Kd_ = Kd;
	Ki_ = Ki;
	p_error = 0.;
	d_error = 0.;
	i_error = 0.;

	n_ = 0;

	averageError_ = 0;
}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	i_error = i_error + cte;


	n_ += 1;
}

double PID::TotalError() {
	
	double totalError = -Kp_ * p_error - Kd_ * d_error - Ki_ * i_error;
	cout << n_ << " " << p_error << " " << totalError << endl;

	return totalError;
}

