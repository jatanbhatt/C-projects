/* MvM, 20 Game */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int  score;   /* Globals */
char in[20];

int user(void)
{
 int i=0;
 while(i!=1 && i!=2){
    printf("We are at %-2d, add 1 or 2 ? ",score);
    fgets(in,10,stdin);
    i=atoi(in);
  };
 return(i);
};


// Given current score return 1 or 2
int computer(void)
{

    int i;
    int rem = score % 3;

    if (rem == 0) i = 2;
    else if (rem == 1) i = 1;
    else i = rand() % 2 + 1;

    printf("Computer adds %d\n",i);
    return(i);
};


int main(void)
{
  int i;
  srand(time(NULL));// Init random
  setvbuf(stdout, NULL, _IONBF, 0);// THIS LINE IS FOR WINDOWS ECLIPSE
  printf(" Who says first 20 \n \n");
  score=0;
  i=0;
  while(i!=1 && i!=2){
    printf("Who goes first: you=1 computer=2 ? ");
    fgets(in,10,stdin);
    i=atoi(in);
  };
  if(i==2)score=computer();
  while(score <=20){
    score=score+user();
    if(score>=20) {printf(" YOU WIN !!\n ");break;};
    score=score+computer();
    if(score>=20) {printf(" I WIN !! \n ");break;};
 };
return(0);
};
