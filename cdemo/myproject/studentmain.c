#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#define TRUE 0
#define FALSE 1

int main()
{
  char input[256];
  char ans;
  struct Student students[256];
  int j = TRUE;
  int count = 0;
  while (j == 0)
  {
    printf("Create New Student (y/n)?  ");
    fgets(input, 100, stdin);
    sscanf(input, "%s", &ans);
    if (strcmp(&ans, "y") == 0)
    {
      j = TRUE;
      char fname[100];
      char lname[100];
      int age;
      int sID;
      printf("Enter First Name of Student:  ");
      fgets(input, 100, stdin);
      sscanf(input, "%s", fname);
      printf("Enter Last Name of Student:  ");
      fgets(input, 100, stdin);
      sscanf(input, "%s", lname);
      printf("Enter Age of Student:  ");
      fgets(input, 100, stdin);
      sscanf(input, "%d", &age);
      printf("Enter Student ID of Student:  ");
      fgets(input, 100, stdin);
      sscanf(input, "%d", &sID);
      printf("\n");
      strcpy(students[count].fname, fname);
      strcpy(students[count].lname, lname);
      students[count].age = age;
      students[count].sid = sID;
      count++;
    }
    else
    {
      j = FALSE;
      for (int i = 0; i < count; i++)
      {
        printStudent(&students[i]);
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
