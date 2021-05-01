#include <iostream>

using namespace std;

int n, p, s;

int main()
{
    cin >> n >> p;
    s = 1;
    cout << 1;
    while(s * n <= p){
        s = s * n;
        cout << ' ' << s;}
    return 0;
}
