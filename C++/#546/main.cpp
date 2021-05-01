#include <iostream>

using namespace std;
int n, i, a[1001];
int main()
{
    cin >> n;
    for(i = 1;i <= n;i++)
        cin >> a[i];
    for(i = 1;i <= n;i++){
        if(a[i] % a[n] == 0)
            cout << a[i] << ' ';
    }

    return 0;
}
