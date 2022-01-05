#include <iostream>
#include <fstream>

using namespace std;

ifstream in("f.in");
ofstream out("f.out");

int n, p, e, l, c, s, a[101][101];

bool perfect(int s)
{
    int suma = 1;

    for (int i = 2; i * i <= s; i++)
    {
        if (s % i == 0)
        {
            suma = suma + i + s / i;
        }
    }
    if (suma == s)
    {
        return true;
    }
    return false;
}

int main()
{
    in >> n >> p;
    for (int i = 1; i <= p; i++)
    {
        in >> e >> l >> c;
        a[l][c] = e;
        s += e;
    }
    for (int i = 1; i <= n; i++)
    {
        out << endl;
        for (int j = 1; j <= n; j++)
        {
            out << a[i][j] << ' ';
        }
    }
    if (perfect(s))
    {
        cout << "DA";
    }
    else
    {
        cout << "NU";
    }
    return 0;
}