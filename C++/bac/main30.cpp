#include <iostream>
#include <fstream>

using namespace std;

fstream in("f.in");

int n, k, a[21][21], x;

void afisare()
{
    for (int i = 1; i <= n; i++)
    {
        cout << endl;
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << ' ';
        }
    }
}

void citire()
{
    in >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            in >> a[i][j];
        }
    }
    in >> k;
}

int main()
{

    citire();
    
    x = a[k][k - 1];
    for (int i = k - 1; i > 1; i--)
    {
        a[k][i] = a[k][i - 1];
    }
    a[k][1] = x;

    afisare();

    return 0;
}