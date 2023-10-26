#include <iostream>
#include <cmath>

using namespace std;

int n, l, c, a[101][101];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - 1; j++)
        {
            if (i != j)
            {
                cin >> a[i][j];
            }
        }
    }
    // for (int l = 1; l <= n; l++)
    // {
    //     for (int c = 1; c <= n; c++)
    //     {
    //         if(l == c){
    //             for(int i = l;i <= n-1;i++){
    //                 a[c][i] = a[c][i+1];
    //             }
    //         }
    //     }
    // }
    for (int i = 1; i <= n; i++)
    {
        cout << endl;
        for (int j = 1; j <= n - 1; j++)
        {
            cout << a[i][j] << ' ';
        }
    }

    return 0;
}