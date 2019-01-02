#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int a = 0;
    printf("Enter a: ");
    scanf("%d",&a);

    float x0 = (1+a);
    x0 = 2/x0;
    double now = x0;
    double error = 1;
    float error_min = 10E-13;

    while (error > error_min) {
        double next = now*(1.5 - 0.5*a*now*now);
        printf("%e   ",next);
        now = next;
        error = fabs(now-(1/sqrt(a)))*sqrt(a);
        printf("%e\n",error);
    }
}
