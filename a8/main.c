#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	int number;
	char name[32];
	struct student* next;
} student;

student* head;

int numStudents = 0;

student* findStudent (int number) {

	student* currStudent = head;
	if (currStudent == NULL) return NULL;
	if (currStudent->number == number) return currStudent;
	while (currStudent->next != NULL)
	{
		currStudent = currStudent->next;
		if (currStudent->number == number) return currStudent;
	}
return NULL;

}

student* read_data(const char* fname) {

	FILE* file = fopen(fname,"r");
	if (file == 0) printf("File not found");
	int number;
	char name[32];
	while (fscanf(file,"%d %s", &number, name) == 2) {

		student* duplicate = findStudent(number);
		if (duplicate != NULL) {
			printf("Duplicate ID:%d\n", duplicate->number);
			printf("Student 1:%s\n", duplicate->name);
			printf("Student 2:%s\n", name);
		}
		else {

		student* tempStudent = (student*)malloc(sizeof(student));
		tempStudent->number = number;
		strcpy(tempStudent->name, name);
		tempStudent->next = head;
		head = tempStudent;

		numStudents++;
		}
	}

	fclose(file);
	return (0);
}

void swap (student*a,student*b) {

    char temp[32];
    strcpy(temp,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,temp);
}

void sort(void) {

	int check;
	student*curr;
    student*last = NULL;
    do {
		curr = head;
		check = 0;
        while (curr->next != last) {
			int test = strcmp(curr->name,curr->next->name);
            if (test > 0) {
                swap(curr,curr->next);
                check = 1;
            }
            curr = curr->next;
        }
        last = curr;
    }
    while (check);
}

student* indexStudent(int index) {
	student*tempStudent = head;
	for (int n = 1; n < numStudents - index; n++) tempStudent = tempStudent->next;
	return tempStudent;
}

void groups(void) {

	int half = numStudents/2;
	printf("Group 1: A - %s\n",indexStudent(half)->name);
	printf("Group 2: %s - Z\n",indexStudent(half)->next->name);
}

int main(void) {

	read_data("students.txt");
	printf("Number of Students Enrolled: %d\n", numStudents);
	sort();
	groups();
	return(0);
}
