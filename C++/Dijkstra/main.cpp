#include <iostream>
#include <fstream>

#define MARE 1000

using namespace std;

int n, m, s, a[101][101], n1, n2, d[101];

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

void dijkstra(int nc)
{
    int min = MARE;

    for (int i = 0; i <= n; i++)
    {
        d[i] = a[s][i];
    }
    
}


int main()
{
    fin >> n >> m >> s;          //citim nr de noduri, nr de muchii si sursa
    for (int i = 1; i <= n; i++) //initializam elementele
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = MARE;
        }
    }
    for (int l = 1; l <= n; l++)
    { //alcatuim matricea de cost
        for (int l = 1; l <= n; l++)
        {
            fin >> n1 >> n2 >> a[n1][n2]; //citim costul
            a[n2][n1] = a[n1][n2];        //facem sa fie simetric
        }
    }
    // dijkstra(s);
    for (int i = 1; i <= n; i++) //pentru fiecare nod
    {
        fout << d[i] << ' ';
    }

    return 0;
}
