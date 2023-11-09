#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

int n, k, a[4000001], minim, maxim = 0;

using namespace std;

int main()
{
    ifstream fin("statisticiordine.in");
    ofstream fout("statisticiordine.out");
    fin >> n >> k;
    for(int i = 1;i <= n;i++)
        fin >> a[i];
    sort(a, a+n+1);

        fout << a[k];
    return 0;
}
