#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 4800

typedef struct measurement{
	float x[SIZE];
	float y[SIZE];
	float z[SIZE];
} sensor_data;

void read_data(sensor_data* d)
{
	FILE* file;
	int n;
	float val_x, val_y, val_z;

	n=0;
	file=fopen("LDB.txt","r");
	while(n<SIZE){
		fscanf(file,"%f\t%f\t%f", &val_x, &val_y, &val_z);
		d->x[n] = val_x;
		d->y[n] = val_y;
		d->z[n] = val_z;
		n++;
	}
	fclose(file);
}

float find_max_axis(float* readings)
{
	float max = 0;
	for (int n = 0; n < SIZE; n++) {
		if (fabsf(readings[n]) > fabsf(max)) max = readings[n];
	}
	return max;
}

float find_max_plane(float* readings_a, float* readings_b)
{
	float max = 0;
	float val;
	for (int n = 0; n < SIZE; n++) {
		val = sqrt(readings_a[n]*readings_a[n]+readings_b[n]*readings_b[n]);
		if (val > max) max = val;
	}
	return max;
}

int main(void)
{
	sensor_data data;
	read_data(&data);

	float max_x = find_max_axis(data.x);
	float max_y = find_max_axis(data.y);
	float max_z = find_max_axis(data.z);

	printf("Max X: %f\n", max_x);
	printf("Max Y: %f\n", max_y);
	printf("Max Z: %f\n", max_z);

	float max_xy = find_max_plane(data.x, data.y);

	printf("Max XY: %f\n", max_xy);

	return(0);
}
