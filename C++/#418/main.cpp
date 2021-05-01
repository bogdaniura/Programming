#include <iostream>
#include <fstream>

using namespace std;

bool graf[101][101];
int n, v1, v2, muchii;

ifstream fin("subgraf.in");
ofstream fout("subgraf.out");

bool prime (int n) {
  int d, nd = 0; // Variabilele locale se initializeaza.
  if (n <= 1)
    return false;
  else {
    for (d = 2; d * d <= n; d++)
      if (n % d == 0) // d este divizor al lui n
        nd = nd + 1; // Am mai gasit un divizor.
    if (nd == 0)
      return true;
    else // altfel
      return false;
  }
}


int main()
{
    fin >> n;
    while(fin >> v1 >> v2){
        if(graf[v1][v2] == 0){
        graf[v1][v2] = graf[v2][v1] = 1;
        muchii++;
        }
    }
    for(int i=1; i<=n; i++){
        if(prime(i)){
            for(int j = 1;j<=n;j++){
                if(graf[i][j] == 1){
                graf[i][j] = 0;
                graf[j][i] = 0;
                muchii--;
                }
            }
        }
    }
    fout << muchii;



    return 0;
}
