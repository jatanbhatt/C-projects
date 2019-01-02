#include <stdlib.h>
#include <time.h>

double randint() {
    int max = 10000;
    int min = -max;
    return rand()%(max*2 -1) + (min+1);
}

void genvector(int n, double b[]) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        b[i] = randint();
    }
}

void genmatrix(int n, double A[]) {
    srand(time(NULL));
    for (int i = 0; i < n*n; i++) {
        A[i] = randint();
    }
}