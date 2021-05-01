#include <iostream>

using namespace std;

int n, k, e, i;

int main()
{
    cin >> n >> k;
    while (n > 1){
        n = n / 10;
        e++;}
    cout << 1;
    for(i=1;i <= k * e;i++)
        cout << '0';
    return 0;
}
