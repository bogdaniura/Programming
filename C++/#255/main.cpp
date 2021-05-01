#include <iostream>

using namespace std;

int n, f[41];

int main()
{
    cin >> n;
    f[2] = f[1] = 1;
    for(int i = 3; i <= n;i++){
        f[i] = f[i-1] + f[i-2];
    }
    for(int i = 1; i <= n;i++){
        cout << f[i] << ' ';
    }

    return 0;
}
