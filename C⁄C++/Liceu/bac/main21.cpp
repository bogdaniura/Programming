#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("f.in");

bool p[10];

int sumcif(int a)
{
    int suma = 0;
    for (; a > 0; a = a / 10)
    {
        suma += a % 10;
    }
    return suma;
}

void addcif(int a)
{
    for (; a > 0; a = a / 10)
    {
        p[a % 10] = true;
    }
}

void afisare()
{
    cout << "\n";
    for (int i = 1; i <= 9; i++)
    {
        if (p[i])
        {
            cout << i;
        }
    }
}

int main()
{
    int n, s, a, j, v[1001];

    in >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        in >> a;
        if (sumcif(abs(a)) < s)
        {
            v[++j] = a;
            addcif(abs(a));
        }
    }
    sort(v + 1, v + j);
    for (int i = 1; i <= j; i++)
    {
        cout << v[i] << ' ';
    }
    afisare();

    return 0;
}