#include <iostream>

using namespace std;

int x;
float y, z;

float nreal(int x, float y)
{
    while (y >= 1)
    {
        y = y / 10;
    }
    z = x + y;
    // cout << z;
    return z;
}

int main()
{
    cin >> x >> y;
    cout << nreal(x, y);

    return 0;
}