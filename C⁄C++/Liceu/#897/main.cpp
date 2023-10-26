#include <iostream>

using namespace std;

int sumcif(int n){
    int a, sc = 0;
    while(n > 0){
        a = n % 10;
        sc = sc + a;
        n = n / 10;
    }
    return sc;
}

int main()
{
    cout << sumcif(241);
    return 0;
}
