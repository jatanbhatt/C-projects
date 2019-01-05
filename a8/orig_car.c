
#include <stdlib.h>
#include <stdio.h>

#include "car.h"
static double vxxkx, vxx_x, vxx_v, vxxk;FILE* out_file;void initCar(const char* log_name){out_file=fopen(log_name,"w");resetCar();printf("Car Initialized \n");}void freeCar(void){fclose(out_file);out_file=NULL;}void resetCar(void){	vxxkx=0.;vxx_x=0.;vxx_v=0.;vxxk=0.;printf("Car Reset\n");}int stepCar(void){	int i;double xv=0.01;for(i=0;i<10;i++){vxxkx+=xv;vxx_v+=xv*20.*vxxk - 0.0001*vxx_v - 0.00001*vxx_v*vxx_v;vxx_x+=xv*vxx_v;}if((vxxk<0)&&(vxx_v<0.)){vxx_v=0.;vxxk=0;};fprintf(out_file,"%f\t%f\t%f\t%f\n",vxxkx,vxx_x,vxx_v,vxxk);return(0);}double getCarPos(void){return(vxx_x);}double getCarSpeed(void){return(vxx_v);}void setBreak(double vxv){if((vxv<0)||(vxv>1)){printf("Ileagal break vxvue \n");exit(1);}if(vxx_v>0) vxxk=-vxv;}void setAccel(double vxv){if((vxv<0)||(vxv>1)){printf("Ileagal Accel vxvue \n");exit(1);}vxxk=vxv;}double getTime(void){return(vxxkx);}
