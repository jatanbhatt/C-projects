#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int a = 0;
    float x0 = 0;
    int n = 0;

    printf("Enter a,x0,n: ");
    scanf("%d,%f,%d",&a,&x0,&n);

    double error = 0;
    double now = x0;

    for (int i = 0; i < n; i++) {
        printf("%d ",i+1);
        double next = now*(1.5 - 0.5*a*now*now);
        printf("%e ",next);
        now = next;
        error = fabs(now-(1/sqrt(a)))*sqrt(a);
        printf("%e\n",error);
    }
}
