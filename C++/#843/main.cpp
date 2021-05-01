#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, n, p = 5, uc;
    long long b = 1, p10 = 1;
    cin >> a >> n >> p;
    for(int i = 1;i <= p;i++)
        p10 = p10 * 10;
    for(int i = 1;i <= n;i++){
        b = b * a;
        if(b % 10 != b)
            b = b % p10;
    }
    cout << b;
    return 0;
}
