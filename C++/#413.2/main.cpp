#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("adiacenta1.in");
ofstream fout("adiacenta1.out");
int l, c, a[101][101], b[101], v1, v2, cmmn = 0;

int main () {
  while (fin>>v1>>v2){
      if(v1>cmmn)
          cmmn=v1;
      if(v2>cmmn)
          cmmn=v2;
    a[v1][v2]=a[v2][v1]=1;
  }
    for(l=1; l<=cmmn; l++){
        for(c=1; c<=cmmn; c++){
            fout<<a[l][c]<<' ';
        }
        fout << endl;
    }
    return 0;
}
