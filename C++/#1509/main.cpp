#include <iostream>

using namespace std;

int nrmaxim(int a) {
  int ca=a, p10=1, u, p, maxim=0, l=0;
  while(ca >= 10){
    ca = ca / 10;
    p10 = p10 * 10;
    l++;
  }
  cout << l << endl;
  if(p10 == 1)
  	return a;
  else{
  for(int i = 0; i <= l; i++){
    u = a % p10;
    p = a / p10;
    a = u * 10 + p;
    cout << a << endl;
    if(a > maxim)
        maxim = a;
  }
  return maxim;
 }
}
int main () {
    int n;
    cin >> n;
    cout << nrmaxim(n);
}
