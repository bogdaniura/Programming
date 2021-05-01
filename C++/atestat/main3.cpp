#include <iostream>

using namespace std;

int n, m = 2100000000, d;
double a, b;

int ncd(int y)
{
    int k, z = 0;
    bool c[9];
    while (y != 0)
    {
        k = y % 10;
        y = y / 10;
        if (!c[k])
        {
            c[k] = true;
            z++;
        }
    }
    return z;
}

int main()
{
    cin >> n;
    cin >> a;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> b;
        if ((int)b == b)
        {
            d = (int)b - int(a) - 1;
        }
        else
        {
            d = (int)b - int(a);
        }
        if (m > d)
        {
            m = d;
        }
        a = b;
    }
    cout << m;
    cout << "\n" << ncd(m);

    return 0;
}