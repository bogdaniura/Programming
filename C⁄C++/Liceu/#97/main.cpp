#include <iostream>

using namespace std;
string a, b;
int i, j, sa, sb, g, anagrame;
int main()
{
  cin >> a >> b;
  //a = "rutina"; b = "masina";
  sa = a.size();
  sb = b.size();
  if(sa != sb)
    cout << 0;
  else {
    for(i = 0; i <= sa - 1; i++)
      for(j = 0; j <= sa - 1; j++)
        if(a[i] == b[j]){
          anagrame++;
          b[j] = '-'; }
    if(anagrame == sa + 1)
      cout << 1;
    else
      cout << 0;}
  return 0;
}

