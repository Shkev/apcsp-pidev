#include <stdio.h>
#include <string.h>

void stringCompare(char* str1, char* str2)
{
  if (strcmp(str1, str2) == 0)
  {
    printf("they are the same\n");
  }
  else
  {
    printf("they are different\n");
  }
}

int main()
{
  char* c1 = "a";
  char str1[54];
  str1[0] = *c1;
  for (int i = 1; i <= 25; i++)
  {
    int j = i - 1;
    str1[i] = str1[j] + 1;
  }
  char str2[54] = "abcdefghijklmnopqrstuvwxyz";
  stringCompare(str1, str2);
  //subtract 32 from all values in string to make uppercase
  for (int i = 0; i <= 25; i++)
  {
    str1[i] = str1[i] - 32;
  }
  printf("After Upcasing all letters ");
  stringCompare(str1, str2);
  char str3[70];
  printf("%s\n", str1);
  strcpy(str3, strcat(str1, str2));
  printf("%s\n%s\n", str2, str3);
  return 0;
}
