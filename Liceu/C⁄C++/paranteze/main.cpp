// oni2017surse@gmail.com

#include <fstream>

using namespace std;

ifstream fin("paranteze1.in");
ofstream fout("paranteze1.out");
char s[1001];
int v, n;
string sp;
bool corect;

void push (char c) {
  v++; s[v] = c;
}

void pop () {
  v--;
}

char top() {
  return s[v];
}

bool empty () {
  return v == 0;
}

int main () {
  fin >> n;
  for (int i = 1; i <= n; i++) {
    v = 0;
    fin >> sp;
    corect = true;
    for (int j = 0; j < sp.size() and corect; j++) {
      if (sp[j] == '(')
        push('(');
      else { // Avem ')'.
        if (not empty())
          pop();
        else
          corect = false;
      }
    }
    if (corect and v == 0)
      fout << 1 << endl;
    else
      fout << 0 << endl;
  }
  return 0;
}

/*
3
()(
()
)
*/

/*
3
())
()
)

*/








