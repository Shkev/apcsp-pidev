#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %d\n", ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %d\n", &a);

  float d = 5;
  float e = 89;
  float* ptrtod = &d;
  float* ptrtoe = &e;

  printf("The value of d is %f\n", *ptrtod);
  printf("The value of e is %f\n", *ptrtoe);
  printf("d is at %d\n", ptrtod);
  printf("e is at %d\n", ptrtoe);

  //swapping the values of d and e
  int tmp = *ptrtod;
  d = *ptrtoe;
  e = tmp;
  printf("d is now %f\n", d);
  printf("e is now %f\n", e);
}
