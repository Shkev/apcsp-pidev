#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

float areaOfCircle(float radius)
{
  float area = PI * radius * radius;
  return area;
}

int main()
{
  float a;
  for(float i = 3.5; i < 12.5; i++)
  {
    a = areaOfCircle(i);
    printf("Area = %f\n", a);
  }
  return 0;
}
