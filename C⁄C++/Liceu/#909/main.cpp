#include <iostream>

using namespace std;

int perm(int& a) {
  int ca, p10 = 1 ,pa = 0;
  ca = a;
  while(ca >= 10) {
    ca = ca / 10;
    p10 = p10 * 10;
  }
  ca = a;
  while(ca >= 10){
    pa = ca / 10;
    ca = ca / 10;
  } if(a >= 10)
        a = a % p10 * 10 + pa;
  return a;
}

int main()
{
    int n;
    cin >> n;
    perm(n);
    cout << n;

    return 0;
}

/*
a = 4567
ca = 4567
4567 / 456 / 45 / 4 / 0
1 / 10 / 100 / 1000*/
