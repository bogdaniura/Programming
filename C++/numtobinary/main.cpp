#include <iostream>

using namespace std;

int n, d = 128;
bool b[9];

int main()
{
    cin >> n;
    if (n < 0)
    {
        b[0] = 1;
        n = -n;
    }
    for (int i = 1; n != 0; i++)
    {
        if (n >= d)
        {
            n = n - d;
            d = d / 2;
            b[i] = true;
        }
        else
        {
            d = d / 2;
        }
    }
    for (int i = 0; i <= 8; i++)
    {
        cout << b[i];
    }

    return 0;
}