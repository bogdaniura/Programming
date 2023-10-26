#include <fstream>

using namespace std;

ifstream fin("egale.in");
ofstream fout("egale.out");

int a, n, b, x, y, t;

int main() {
  fin >> t;
 /* if(n == 1)
    fin >> x >> y;*/
  if(t == 2)
    fin >> n;
  b = 1;
  while(b <= n) {
    a = 1;
    do {
      for(int i = 1; i <= b; i++)
        fout << a;
      fout << ' ';
      a++;
    } while(a <= 9);
    b++;
  }
  return 0;
}
