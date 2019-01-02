#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#define N 8000

void genmatrix(int n, double A[]);
void genvector(int n, double b[]);
void checkresult(int n, int flag, double A[], double b[], double x[]);
int linsolve(int n, double A[], double b[], double x[]);

double A[N * N], B[N*N], b[N], c[N], x[N];

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: main n\n");
        return 1;
    }
    int n = atoi(argv[1]);
    if (n > N) {
        printf("n = %d must be <= %d\n", n, N);
        return 2;
    }

    srand(time(NULL));

    genvector(n, b);
    printf("\n");
    genmatrix(n, A);

    // Save A and b so we use it to check the result.
    memmove(B,A,n*n*sizeof(double));
    memmove(c,b,n*sizeof(double));
    // You can overwrite A and b.
    // int success = linsolve(n, A, b, x);
    // checkresult(n, success , B, c, x);
    return 0;
}

//////////////////

int randint() {
    int max = 10;
    int min = -max;
    return rand()%(max*2 -1) + (min+1);
}

double randdub()
{
    double LIMIT_MAX = 100;
    double LIMIT_MIN = -100;
    double range = (LIMIT_MAX - LIMIT_MIN);
    double divis = RAND_MAX / range;
    return LIMIT_MIN + (rand() / divis);
}

void printmatrix(int n, double A[])
{
    for (int i = 0; i < n*n; i++) {
        printf("%-5.0f ", A[i]);
        if ((i+1)%n == 0) printf("\n");
    }
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

void linsolve (int n, double A[], double b[], double x[]) {

    for(int col=0; col<n; col++) {
        for(int row=0; row<n; row++) {
            if(row!=col) {
                int factor=A[indx(n,row,col)]/A[indx(n,col,col)];
                for(int k=0; k<=n; k++) {
                    A[indx(n,col,k)]= A[indx(n,col,k)] - factor*A[indx(n,row,k)];
                }
            }
        }
    }

    for(int i=0; i < n; i++) {
        x[i]=A[indx(n,i,n+1)]/A[indx(n,i,i)];
        printf("\n x%d=%f\n",i,x[i]);
    }
}
