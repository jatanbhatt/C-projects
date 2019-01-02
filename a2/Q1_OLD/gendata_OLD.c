#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randint() {
    int max = 10;
    int min = -max;
    return rand()%(max*2 -1) + (min+1);
}

void genvector(int n, double b[]) {
    for (int i = 0; i < n; i++) {
        b[i] = randint();
        printf("%.0f\n",b[i]);
    }
}

void genmatrix(int n, double A[]) {
    for (int i = 0; i < n*n; i++) {
        A[i] = randint();
        printf("%-5.0f ", A[i]);
        if ((i+1)%n == 0) printf("\n");
    }
}
