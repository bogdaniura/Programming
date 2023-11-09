#include <iostream>

using namespace std;
int n, x, p=1, a;
int main()
{
    cin >> n;
    while(n >= 1){
        x = n % 10;
        if(x % 2 == 1){
            p = p * x;
            a++;}
        n = n / 10;
    }
    if(a != 0)
        cout << p;
    else
        cout << -1;

    return 0;
}
