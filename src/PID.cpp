#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpin, double Kdin, double Kiin) {
	Kp = Kpin;
	Kd = Kdin;
	Ki = Kiin;
	p_error = 0.;
	d_error = 0.;
	i_error = 0.;
}

void PID::UpdateError(double cte) {
	cout << "----------------------------------------------" << endl;
	cout << "OLD errors: p_e=" << p_error << " d_e=" << d_error << " i_e=" << i_error << endl;
	cout << "cte=" << cte << endl;
	d_error = cte - p_error;
	p_error = cte;
	i_error = i_error + cte;
	cout << "NEW errors: p_e=" << p_error << " d_e=" << d_error << " i_e=" << i_error << endl;
	cout << "----------------------------------------------" << endl;
}

double PID::TotalError() {
	
        //double totalError = p_error * Kp + d_error * Kd + i_error * Ki;
	std::cout << "d_error=" << d_error << endl;
	std::cout << "pErr=" << -Kp*p_error << ", dErr=" << -Kd*d_error << ", iErr=" << -Ki*i_error << std::endl;
	double totalError = -Kp * p_error - Kd * d_error - Ki * i_error;
//	double totalError = -Kp * p_error - Kd * d_error - Ki * i_error;
//	double totalError = -Kp * p_error;


	if(totalError > 1) {
		totalError = 1.;
	}
	if(totalError < -1) {
		totalError = -1.;
	}
	return totalError;
}

