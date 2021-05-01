#include <iostream>

using namespace std;

int f(int x){
    long long fac = 1;
    for(int i = x;i >= 1;i--)
        fac = fac*i;
    return fac;
}


int main()
{
    long long comb, n, k;
    cin >> n >> k;
    comb = f(n) / (f(k) * f(n-k));
    cout << comb;

    return 0;
}
