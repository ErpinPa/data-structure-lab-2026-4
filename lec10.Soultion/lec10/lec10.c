#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
}student;

int main(void)
{
	student* p;
	p = (student*)malloc(sizeof(student));
	if (p == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}
	strcpy(p->name, "Park");
	p->age = 20;

	printf("Name : %s\n", p->name);
	printf("Name : %s\n", (*p).name);

	printf("Age : %d\n", p->age);
	printf("Age : %d\n", (*p).age);

	free(p);
	return 0;
}