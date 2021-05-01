#include <iostream>

using namespace std;

int n, m = 2100000000, d;
double a, b;

int ncd(int y)
{
    int k, z = 0;
    bool c[10] = {false};
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

int ncd2(int y)
{
    int k, z = 0;
    bool c[10] = {false};
    while (y > 0)
    {
        k = y % 10;
        y = y / 10;
        c[k] = true;
    }
    for(int i = 0;i <= 9;i++){
        if(c[i])
            z++;
    }
    return z;
}

int main()
{
    cin >> m;
    cout << ncd2(m);

    return 0;
}