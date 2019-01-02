#include <stdio.h>
#include <stdlib.h>

// void print_A_b(int n, double A[], double b[]) {
//     printf("A | b:\n");
//     for (int i = 0; i < n*n; i++) {
//         printf("%-5.2f ", A[i]);
//         if ((i+1)%n == 0) printf("| %-5.2f\n", b[i]);
//     }
//     printf("\n");
// }

// void print_x(int n, double x[]) {
//     printf("x[]:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%-5.2f\n", x[i]);
//     }
//     printf("\n");
// }

void checkresult(int n, int flag, double A[], double b[], double x[])
{
	printf("N: %d\n", n);
	printf("Result: %d\n", flag);
	// if (flag == 1) {
	// 	print_A_b(n, A, b);
	// 	print_x(n, x);
	// }
}