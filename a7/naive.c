
#include <stdio.h>
#include <stdlib.h>

// Data Structure

#define SIZE 16

typedef int MYTYPE;

MYTYPE a[SIZE];

//------------------- Array basic ------------------------


void init()
{
	int i;
	for(i=0;i<SIZE;i++)a[i]= SIZE-i;
}

void print(MYTYPE* a)
{

	int i;
	for(i=0;i<SIZE-1;i++)printf("%d, ",a[i]);
	printf("%d\n",a[i]);
}


//--------------- TOOLs --------------------


int find(MYTYPE * a,MYTYPE b)
{
	int i;
	for(i=0;i<SIZE;i++)
		if( a[i]==b)return(i);
	return(-1);
}

int bin_search(MYTYPE* data,MYTYPE val,int a, int b)
{
	int mid;
	mid=(a+b)/2;

	printf("Called with a=%d b=%d mid=%d \n",a,b,mid);
	if(data[mid]==val)return(mid);
	if(a==b)return(-1);
	if(data[mid]>val)
		return(bin_search(data,val,mid+1,b));
	else
		return(bin_search(data,val,a,mid-1));
}




int greater(int a,int b)
{
	return(a>b);
}


int smaller(int a,int b)
{
	return(a<b);
}

void swap(int i,int j)
{
	MYTYPE tmp;
	tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
}



void sort(MYTYPE* data,int (*compare)(MYTYPE a,MYTYPE b))
{

	int i, j;
        for(j=0;j<SIZE;j++)
		for(i=0;i<SIZE-1;i++)
		 	if(compare(data[i],data[i+1]))swap(i,i+1);

}

//------- MAIN ----------------



int main(void)
{
	init();
	//print(a);
	//printf("It is at %d \n",find(a,10));

	print(a);
	sort(a,&greater);
	print(a);
	sort(a,&smaller);
	print(a);
	return(0);
}
