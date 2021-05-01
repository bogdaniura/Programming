#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("ambuscada.in");
ofstream fout("ambuscada.out");

int n, m, v, s[10000001], soldati, p, u, d;

int main()
{
    fin >> n >> m >> v;
    for (int i = 1; i <= n; i++)
    {
        s[i] = v;
    }
    for (int i = 1; i <= m; i++)
    {
        fin >> p >> u >> d;
        for(int j = p; j <= u;j++){
            s[j] -= d;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if(s[i] > 0){
            soldati++;
        }
    }
    fout << soldati;
    return 0;
}
