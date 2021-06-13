#include <iostream>

using namespace std;

int n, n1, s;

int impare(int n)
{
    int v[10] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };
    for (int i = 1; n > 0; i++)
    {
        if (n % 10 % 2 == 1)
        {
            v[i] = n % 10 - 1;
        }
        else
        {
            v[i] = n % 10;
        }
        n = n / 10;
        s++;
    }
    for (int i = s; i > 1; i--)
    {
        n = n * 10 + v[i];
    }

    return n;
}

int main()
{
    cin >> n;
    n1 = n;
    for (; n1 > 0; s++)
    {
        n1 = n1 / 10;
    }
    cout << s;
    cout << impare(n);

    return 0;
}