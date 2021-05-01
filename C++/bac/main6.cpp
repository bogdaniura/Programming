#include <iostream>

using namespace std;

int m, n, p = 0, a[101][101];

int main()
{
    cin >> m >> n;
    for (int l = m; l >= 1; l--) //incepem din dreapta jos
    {
        for (int c = n; c >= 1; c--)
        {
            if (p == 0) //daca p == 0
            {
                a[l][c] = 0; //ultimul element mereu e 0
                p++;
            }
            else
            {
                while (p * p % 2 != 0) //cat timp p * p este impar
                {
                    p++; //p creste
                }
                a[l][c] = p * p; //cand p * p este par, a[l][c] = p * p
                p++; //p creste
            }
        }
    }
    for (int l = 1; l <= m; l++) //afisare normala
    {
        cout << endl;
        for (int c = 1; c <= n; c++)
        {
            cout << a[l][c] << ' ';
        }
    }
    return 0;
}