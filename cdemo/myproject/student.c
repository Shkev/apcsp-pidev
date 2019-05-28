#include <stdio.h>
#include "student.h"

void printStudent(struct Student* student)
{
  printf("\nFirst Name: %s\n", student->fname);
  printf("Last Name: %s\n", student->lname);
  printf("Age: %d\n", student->age);
  printf("Student ID: %d\n", student->sid);
}

