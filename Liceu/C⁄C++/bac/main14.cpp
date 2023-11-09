#include <iostream>

using namespace std;

int k, n, a[101][101];

void afisare()
{
    for (int i = 1; i <= n; i++)
    {
        cout << endl;
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << ' ';
        }
    }
}

int main()
{
    cin >> k >> n;
    // afisare();
    for (int i = 1; i <= n; i++)
    {
        a[i][i] = k * i;
    }

    // afisare();

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n-1; j++)
        {
            a[i][j+1] = a[i][j] + 1;
        }
        for (int j = i; j >= 2; j--)
        {
            a[i][j-1] = a[i][j] - 1;
        }
    }
    afisare();

    return 0;
}