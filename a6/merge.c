#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_SIZE 256


void merge(int *a,int i1,int j1,int i2,int j2)
{
    int temp[MAX_SIZE];    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;

   printf("merge called with %d %d %d %d \n",i1,j1,i2,j2);

    while(i<=j1 && j<=j2){
        if(a[i]<a[j]){
       //     temp[k++]=a[i++];
            temp[k]=a[i];
	    k++;i++;
	}else
            temp[k++]=a[j++];
    }

    // take the rest of the lists
    while(i<=j1)
        temp[k++]=a[i++];

    while(j<=j2)
        temp[k++]=a[j++];

    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}



void merge_sort(int *a,int i,int j)
{
    int mid;

    if(i<j){
        mid=(i+j)/2;
        merge_sort(a,i,mid);        //left recursion
        merge_sort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
}


void print_array(int* a,int n)
{
   int i;
   for(i=0;i<n;i++)
        printf("%d ",a[i]);
   printf("\n");
}

//fill with radom numbers
void fillArray(int* a,int n)
{
	int i;
	for(i=0;i<n;i++)a[i]=rand()%n;
}


int main()
{
    srand(time(NULL)); // Initialize random

    int a[MAX_SIZE]; // local array to hold data
    int n;
    n=20;

    fillArray(a,n);
    print_array(a,n);

    merge_sort(a,0,n-1);

    printf("\nSorted array is : \n");
    print_array(a,n);

    return(0);
}
