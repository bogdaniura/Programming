#include <iostream>

using namespace std;
int n, m, l, c, s, a[101][101];
int main()
{
    cin >> n >> m;
    for(l = 1;l<= n;l++)
        for(c = 1;c<= m;c++)
            cin >> a[l][c];
    for(l = 1;l<= n;l++)
        for(c = 1;c<= m;c++)
            if(a[l][c] % 2 == 0)
                s=s+a[l][c];
        cout << s;
    return 0;
}
