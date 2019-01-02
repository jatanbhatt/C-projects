#include <stdio.h>
#include <stdlib.h>

int two = 0;
int three = 0;
int five = 0;
int six = 0;
int ten = 0;
int fifteen = 0;
int na = 0;

void divisibley(int now) {
    int flag = 0;
    if (!(now%2)) two++, flag = 1;
    if (!(now%3)) three++, flag = 1;
    if (!(now%5)) five++, flag = 1;
    if (!(now%6)) six++, flag = 1;
    if (!(now%10)) ten++, flag = 1;
    if (!(now%15)) fifteen++, flag = 1;
    if (!flag) na++;
}

int main(void) {
    int input = 0;
    printf("Enter a positive integer: ");
    scanf("%d",&input);
    while (input <=0 ) {
        printf("Try again (number greater than 0): ");
        scanf("%d",&input);
    }
    printf("\nFibonacci sequence upto %d:\n",input);
    int temp = 0;
    int now = 1;
    int prev = 0;

    while (now <= input) {
        printf("%d, ",now);
        divisibley(now);
        temp = now;
        now = now + prev;
        prev = temp;
    }
    printf("\n\ndivisibley by:\n");
    printf(" 2  ->  %d\n",two);
    printf(" 3  ->  %d\n",three);
    printf(" 5  ->  %d\n",five);
    printf(" 6  ->  %d\n",six);
    printf("10  ->  %d\n",ten);
    printf("15  ->  %d\n",fifteen);
    printf(" -  ->  %d\n",na);
}
