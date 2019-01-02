
// MvM
// SFWR ENG 2S03  MArch 2017
//
/***************************************************************************/
// CHANGE NOTHIN IN  HERE !!!!!
/***************************************************************************/


// CONTROL FUNCTIONS

// Must be called first
void initCar(const char* log_name);
//CLose the simulation, init has to be called again
void freeCar(void);
// Reset the Car, put it back to 0
void resetCar(void);
// step the car  simulation
// return 0 if OK 1  if error
int stepCar(void);


// NOTE, if you set the break or the accel it remains
//       set until you set it to 0!
// NOTE, you can only use one paddle at a time !!!
//       they will overwrite each other. (by design)
// 0..1
void setBreak(double val);
// 0..1
void setAccel(double val);

// OUTPUT Functions

// Returns the position in meters
double getCarPos(void);
// Returns the speed in km/h
double getCarSpeed(void);
//return the simulation time
double getTime(void);


