#include <stdio.h>
#include <stdlib.h>

// flag to toggle debug printouts
// #define DEBUG

int ind_n;

int indx(int i, int j) {
    int indx = (ind_n*i + j);
    return indx;
}

#ifdef DEBUG
void print_A_b(int n, double A[], double b[]) {
    printf("A | b:\n");
    for (int i = 0; i < n*n; i++) {
        printf("%-+12.4f ", A[i]);
        if ((i+1)%n == 0) printf("| %-+12.4f\n", b[i/n]);
    }
    printf("\n");
}

void print_x(int n, double x[]) {
    printf("x[]:\n");
    for (int i = 0; i < n; i++) {
        printf("%-+12.4f\n", x[i]);
    }
    printf("\n");
}
#else
void print_A_b(int n, double A[], double b[]) {}
void print_x(int n, double x[]) {}
#endif

int linsolve (int n, double A[], double b[], double x[]) {
    ind_n = n;
    print_A_b(n,A,b);
    // i    : row iterator
    // j, k : column iterators
    for(int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            // for non diagonal elements
            if (i != j) {
                if (A[indx(j,j)] == 0) return 0;
                else {
                    double factor = A[indx(i,j)]/A[indx(j,j)];
                    b[i] = b[i] - factor*b[j];
                    for (int k = 0; k < n; k++) {
                        A[indx(i,k)] = A[indx(i,k)] - factor*A[indx(j,k)];
                    }
                }
            }
        }
    }
    print_A_b(n,A,b);

    for (int i = 0; i < n; i++)
    {
        // solving for x[]
        x[i] = b[i]/A[indx(i,i)];
    }
    print_x(n,x);
    return 1;
}
