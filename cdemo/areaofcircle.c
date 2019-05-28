#include <stdio.h>
#include <math.h>

float areaOfCircle(float radius)
{
  float area = M_PI * radius * radius;
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
