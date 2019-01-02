#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

typedef struct student {
	int number;
	char name[32];
} student;

student d[SIZE];
int numStudents = 0;

int findStudent(int number) {
	for (int n = 0 ; n < numStudents; n++) {
		if (number == d[n].number) return n;
	}
	return -1;
}

int read_data(const char* fname)
{
	FILE* file = fopen(fname,"r");
	if (file == 0) printf("File not found");
	// search variables
	int number;
	char name[32];
	int n = 0;
	while(n < SIZE) {
		// if we don't find 2 data entries, we've reached end of file
		if (fscanf(file,"%d %s", &number, name) != 2){
			break;
		}

		int duplicate = findStudent(number);
		if (duplicate != -1) {
			// output information if duplicate found
			printf("Duplicate ID:%d\n", number);
			printf("Student 1:%s\n", d[duplicate].name);
			printf("Student 2:%s\n", name);
		}
		else {
			// copy values of holding variables
			d[n].number = number;
			strcpy(d[n].name, name);
			// increase index count and total student count (used in findStudent)
			n++;
			numStudents = n;
		}
	}
	fclose(file);
	return (0);
}

void swap(const int index1, const int index2) {

	student temp;
	temp = d[index1];
	d[index1] = d[index2];
	d[index2] = temp;
}

void sort(void) {

	for(int n = 0; n < numStudents ; n++) {
    	for(int i = 0 ; i < numStudents - 1 ; i++) {
			if(strcmp(d[i].name, d[i+1].name) > 0) {
				swap(i, i+1);
        	}
    	}
	}
}

void groups(void){
	int half = numStudents/2;
	printf("Group 1: %s - %s\n",d[0].name, d[half-1].name);
	printf("Group 2: %s - %s\n",d[half].name, d[numStudents-1].name);
}

void writeData(const char* fname,int start,int end){
	FILE* file = fopen(fname,"w");
	for(int i=start; i<end; i++) {
		char sentence[7+1+32+1];
		sprintf(sentence, "%d %s\n", d[i].number, d[i].name);
		fputs(sentence, file);
	}
	fclose(file);
}

int main(void)
{
	read_data("students.txt");
	printf("Number of Students Enrolled: %d\n", numStudents);
	sort();
	groups();
	writeData("output.txt",0,115);
	return(0);
}
