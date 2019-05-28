#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
  char fname[256];
  char lname[256];
  int age;
  int sid;
};

void printStudent(struct Student* student)
{
  printf("First Name: %s\n", student->fname);
  printf("Last Name: %s\n", student->lname);
  printf("Age: %d\n", student->age);
  printf("Student ID: %d\n", student->sid);
}

int main()
{
  char input[256];
  char ans;
  struct students[256];
  int j = 0;
  int count = 0;
  while (j == 0)
  {
    printf("Create New Student (y/n)?");
    fgets(input, 256, stdin);
    sscanf(input, "%s", &ans);
    if (strcmp(&ans, "y") == 0)
    {
      count++;
      j = 0;
      char fname[256];
      char lname[256];
      int age;
      int sID;
      printf("Enter First Name of Student");
      fgets(input, 256, stdin);
      sscanf(input, "%s", fname);
      printf("Enter Last Name of Student");
      fgets(input, 256, stdin);
      sscanf(input, "%s", lname);
      printf("Enter Age of Student");
      fgets(input, 256, stdin);
      sscanf(input, "%d", &age);
      printf("Enter Student ID of Student");
      fgets(input, 256, stdin);
      sscanf(input, "%d", &sID);
      struct Student student;
      strcpy(student.fname, fname);
      strcpy(student.lname, lname);
      student.age = age;
      student.sid = sID;
      students[count] = student;
    }
    else
    {
      j = 1;
      for (int i = 1; i <= count; i++);
      {
        printStudent(students[i]);
      }
    }
  }
  /* Example:
  struct Student student1;
  strcpy(student1.fname, "Shayan");
  strcpy(student1.lname, "Azmoodeh");
  student1.age = 15;
  student1.sid = 2007772;
  printStudent(&student1);
  */
  return 0;
}
