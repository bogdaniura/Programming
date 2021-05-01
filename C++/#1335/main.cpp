#include <iostream>

using namespace std;
string a, b;
int sa, sb, i;
char c;
int main() {
  cin >> a >> b;
  sa = a.size();
  sb = b.size();
  for(i = 0; i < sa; i++){
      c = a[i];
    if(b.find(c) != string::npos)
      cout << a[i];}
}
