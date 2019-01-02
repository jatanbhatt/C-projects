#include <stdio.h>
#include <stdlib.h>


int indx(int i, int j) {
    int n = 3;
    int indx = (n*i + j);
    return indx;
}

void printmatrix(int n, double A[]) {

    for (int i = 0; i < n*n; i++) {
        printf("%-5.2f ", A[i]);
        if ((i+1)%n == 0) printf("\n");
    }
}

void printvector(int n, double b[]) {

    for (int i = 0; i < n; i++) {
        printf("%-5.2f\n", b[i]);
    }
}

int linsolve (int n, double A[], double b[], double x[]) {

    for(int col = 0; col < n; col++)
    {
        for (int row = 0; row < n; row++)
        {
            if (row>col)
            {
                double factor = A[indx(row,col)]/A[indx(col,col)];
                b[row] = b[row] - factor*b[col];
                for (int ind=0; ind < n; ind++)
                {
                    A[indx(row,ind)] = A[indx(row,ind)] - factor*A[indx(col,ind)];
                }
            }
        }
    }

    printvector(n,b);
    printf("\n");
    printmatrix(n,A);
    printf("\n");

    x[n-1] = b[n-1]/A[n*n-1];

    for (int row = (n-2); row >= 0; row--)
    {
        x[row] = b[row];
        for (int col =row+1; col < n; col++)
        {
            x[row] = x[row] - A[indx(row,col)]*x[col];
        }
        x[row] = x[row]/A[indx(row,row)];
        if (!(x[row] == x[row])) return 0;
    }
    printvector(n,x);

    return 1;
}

int main(void) {
    double A[] = {1,0,0,0,1,0,0,0,0};
    double b[] = {7,8,3};
    double x[4];
    int n = 3;
    int output = linsolve(n,A,b,x);
    printf("output = %d",output);
}
