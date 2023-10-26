#include <iostream>

using namespace std;

int a, n, m;

int main()
{
    cin >> n >> m;
    while(m != 1){
        m = m / n;
        a++;}
    cout << a;
    return 0;
}
