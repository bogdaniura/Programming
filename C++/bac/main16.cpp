#include <iostream>

using namespace std;

int x, y;

void sumdiv(int a)
{
    int sa = 0;
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0)
        {
            sa += i;
        }
    }
    // cout << sa << ' ';
}

bool armonie(int x, int y)
{
    int sx = 0, sy = 0;
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            sx += i;
        }
    }
    for (int i = 1; i <= y; i++)
    {
        if (y % i == 0)
        {
            sy += i;
        }
    }
    if (x + y < max(sx, sy) && x + y > min(sx, sy))
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> x >> y;
    cout << armonie(x, y);

    return 0;
}