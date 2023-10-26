#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int n, a[1001], imp[1001];

int divizori(int nr)
{
    int div = 0;
    for (int i = 2; i <= nr / 2; i++)
    {
        if (nr % i == 0)
        {
            div++;
        }
    }
    return div;
}

int modul(int m)
{
    if (m >= 0)
        return m;
    else
        return -m;
}

void citire()
{
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> a[i];
    }
}

void cerinta_a()
{
    for (int i = 1; i <= n; i++)
    {
        cout << modul(a[i]) << ' ';
    }
}

void cerinta_b()
{
    for (int i = 1; i <= n; i++)
    {
        cout << divizori(modul(a[i])) << ' ';
    }
}

void cerinta_c()
{
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        if (modul(a[i] % 2) == 1)
        {
            imp[++j] = a[i];
        }
    }
    sort(imp+1, imp + j + 1);
    for (int i = 1; i <= j; i++)
    {
        fout << imp[i] << ' ';
    }
}

int main()
{
    citire();
    cerinta_a();
    cout << endl;
    cerinta_b();
    cerinta_c();
}