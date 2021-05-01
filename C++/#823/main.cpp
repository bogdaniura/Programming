#include <iostream>

using namespace std;

int sumcif(int n){
    int s = 0, n1;
    if(n/10 > 0){
        n1 = n % 10;
        return n1 + sumcif(n/10);
    }
    else
        return n;
}

int main()
{
    int n;
    cin >> n;
    cout << sumcif(n);

    return 0;
}
