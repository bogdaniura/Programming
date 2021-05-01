
#include <fstream>

using namespace std;

ifstream fin("listavecini.in");
ofstream fout("listavecini.out");
int n, i, l, c, b[101];
bool a[101][101];

int main() {
  fin >> n;
  while (fin >> l >> c) {
    a[l][c] = a[c][l] = true;
  }
  for (l = 1; l <= n; l++) {
    for (c = 1; c <= n; c++)
      if (a[l][c])
        b[l]++;
  }
  for (l = 1; l <= n; l++) {
    fout << b[l] << ' ';
    for (c = 1; c <= n; c++)
      if (a[l][c])
        fout << c << ' ';
    fout << endl;
  }
  return 0;
}
