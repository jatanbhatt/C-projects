
#include <stdlib.h>
#include <stdio.h>

#include "car.h"

void holdSpeed(double speed)
{
	double sp= .8*( speed-getCarSpeed());
	if(sp>1.)sp=1.;
	if(sp<0.)sp=0.;
	setAccel(sp);
}

double brakingDist (double vel) {
	// best fit polynomial of Position vs. Velocity
	return 1.44 - 0.228*vel + 0.0319*vel*vel;
}

int main(void)
{
	const int x = 1000; // target distance

	initCar("DATA_NE2W");

	while (1) {
		double currPos = getCarPos();
		double currVel = getCarSpeed();
		double bd = brakingDist(currVel);

		if ((x - currPos)*.8 > bd) {
			holdSpeed(50.);
		}

		else break;

		stepCar();
	}

	while (getCarSpeed() != 0) {
		setBreak(1.);
		stepCar();
	}

	freeCar();
}
