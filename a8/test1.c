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

student* read_data(const char* fname)
{
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

		// allocate memory for student & assign read values
		student* tempStudent = (student*)malloc(sizeof(student));
		tempStudent->number = number;
		strcpy(tempStudent->name, name);

		// new students next will be current head
		tempStudent->next = head;
		// move head to newly read student
		head = tempStudent;

		numStudents++;
	}
	}

	fclose(file);
	return (0);
}


student* indexStudent(int index) {
	student* currStudent = head;
	for (int n = 0; n < numStudents - index; n++) currStudent = currStudent->next;
	return currStudent;
}

// void swap(const int index1, const int index2) {
//
// 	student* temp;
// 	temp = studentIndex(index1);
// 	strcpy(studentIndex(index1), studentIndex(index2));
// 	d[index1] = d[index2];
// 	d[index2] = temp;
// }
//
//
// void sort(void) {
//
// 	for(int n = 0; n < numStudents ; n++) {
//     	for(int i = 0 ; i < numStudents - 1 ; i++) {
// 			if(strcmp(indexStudent(i)->name, indexStudent(i+1)->name) > 0) {
// 				swap(i, i+1);
//         	}
//     	}
// 	}
// }

void groups(void){
	student*currStudent = head;
	int half = numStudents/2;

	printf("Group 1: A - %s\n", indexStudent(half)->name);
	printf("Group 2: %s - Z\n",indexStudent(half+1)->name);
}


int main(void)
{
	read_data("students.txt");
	printf("Number of Students Enrolled: %d\n", numStudents);
	printf("%d\t%s\n", head->next->number, head->next->name);
	student*test = indexStudent(5);
	printf("Name is %s\n",test->name);
	// sort();
	groups();
	return(0);
}
