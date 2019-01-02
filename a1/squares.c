#include <stdio.h>
#include <stdlib.h>
#define SQUARES_IN_ROWS 5

void makesquares(int squares) {
    if (squares == 0) return;
    for (int i = 0;i<3;i++) {
        for (int j = 0;j<squares;j++) {
            printf("### ");
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    printf("Enter number of squares: ");
    int n = 0;
    scanf("%d",&n);
    while (n<=0 || n>50) {
        printf("Try again (number of squares should be between 1 and 50): ");
        scanf("%d",&n);
    }

    for (int i =0; i < n/SQUARES_IN_ROWS; i++) makesquares(SQUARES_IN_ROWS);
    makesquares(n%SQUARES_IN_ROWS);
}
