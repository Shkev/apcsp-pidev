#include <stdio.h>

void arrayAdd(int* arr, int s, int n) {
  for(int i = 0; i < s; i++) {
    arr[i] = (arr[i] + n);
    printf("%d\n", arr[i]);
  }
}

int main() {
  int arr[100];
  for(int i = 0; i < 100; i++) {
    arr[i] = i * i;
  }
  arrayAdd(arr, 100, 25);
}
