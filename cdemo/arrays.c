#include <stdio.h>
int main() {
  int arr[100];
  for(int i = 0; i < 100; i++) {
    arr[i] = i * i;
    printf("%d\n", arr[i]);
  }
}
