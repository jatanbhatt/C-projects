#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double sinc(double x)
{
    if (x == 0) return 1;
    else return (sin(M_PI*x)/(M_PI*x));
}

double comph(int N)
{
    double h = M_PI/sqrt(2*N);
    return h;
}

double comprho(double x, double a, double b)
{
    double rho = (x-a)/(b-x);
    return rho;
}

double complambda(double x, double h, double a, double b, int j)
{
    double lambda = sinc((log(comprho(x,a,b))-j*h)/h);
    return lambda;
}

void wj(double x, double a, double b, int N, double *w)
{
    double h = comph(N);
    for (int i = 0; i <= 2*N; i++)
    {
        int j = (-N+i);
        w[i] = complambda(x,h,a,b,j);
    }

    double sum1 = 0;
    double sum2 = 0;

    for (int i = 1; i <= 2*N; i++)
    {
        int j = (-N+i);
        sum1 += complambda(x,h,a,b,j)/(1+exp(j*h));
    }

    for (int i = 0; i < 2*N; i++)
    {
        int j = (-N+i);
        sum2 += complambda(x,h,a,b,j)/(1+exp(j*h));
    }

    w[0] = (1 + exp(-N*h))*(1/(1+comprho(x,a,b)) - sum1);
    w[(2*N)-1] = (1 + exp(-N*h))*(comprho(x,a,b)/(1+comprho(x,a,b)) - sum2);

}
