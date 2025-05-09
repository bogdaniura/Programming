#include <iostream>

using namespace std;

int main() {
  int n, b, i, t, j;
  int a[] = {17, 21, 12, 33, 0, 11, 10, 9};

  for (n = 0; a[n] > 0; n++)
    b = 1;
  while (b) {
    b = 0;

    for (i = 0; ;a[i + 1]) {
      t = a[i];
      a[i] = a[i + 1];
      a[i + 1] = t;
      b = 1;
    }
  }
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  return 0;
}