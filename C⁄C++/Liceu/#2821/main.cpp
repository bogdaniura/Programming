#include <iostream>

using namespace std;

int n, i = 2, r = 1;;

int main() {
  cin >> n;
  do {
    if(n % i == 0) {
      r = r * i;
      while(n % i == 0)
        n = n / i;
    } else
      i++;
  } while(n != 1 and n * n>= i);
  if(n > 1)
    r = r * n;
  cout << r;
  return 0;
}
