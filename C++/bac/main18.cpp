#include <iostream>
#include <fstream>

using namespace std;

ifstream in("f.in");

int l, c, a[21][21];

int main()
{
    in >> l >> c;
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            in >> a[i][j];
        }
    }
    for (int i = 1; i <= c - 1; i++)
    {
        for (int j = 2; j <= l; j++)
        {
            if(a[1][i] == a[j][c]){
                cout << a[1][i] << ' ';
            }
        }
    }

    return 0;
}