#include <iostream>
#include <cmath>

using namespace std;

int n, x, y;

void patrate(int n, int &x, int &y)
{

    bool ok = false;
    for (int d = 2; d * d < n, !ok; d++)
    {
        if (n % (d * d) == 0)
        {
            x = d * d;
            ok = true;
        }
    }
    y = n / x;
    int r = sqrt(y);
    if (r * r != y or x == y)
    {
        x = 0;
        y = 0;
    }
    else
    {
        y = r;
        x = sqrt(x);
    }
}

int main()
{

    cin >> n;
    patrate(n, x, y);
    cout << x << ' ' << y;

    return 0;
}