#include <iostream>

using namespace std;

int x, p, y, c;

int main()
{
    cin >> x;
    p = 1;
    y = 0;
    c = x % 10;
    x = x / 10;
    if (c != 0)
    {
        if (x % 10 < c)
        {
            y = y * 10 + c;
        }
        else
        {
            y = c * p + y;
        }
        p = p * 10;
    }
    while (x != 0)
    {
        c = x % 10;
        x = x / 10;
        if (c != 0)
        {
            if (x % 10 < c)
            {
                y = y * 10 + c;
            }
            else
            {
                y = c * p + y;
            }
            p = p * 10;
        }
    }
    cout << y;
    return 0;
}