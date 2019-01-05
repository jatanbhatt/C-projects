
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
	const int x = 10; // target distance

	initCar("DATA");
	while (1) {
		if (x <= 0) break;
		double currPos = getCarPos();
		double currVel = getCarSpeed();
		if (currPos > 0. && currVel == 0.) break;
		double bd = brakingDist(currVel);

		if ((x - currPos)*.8 > bd) {
			holdSpeed(50.);
		} else {
			setBreak(1.);
		}
		stepCar();
	}
	freeCar();
}
