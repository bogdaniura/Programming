#include <iostream>

using namespace std;

int x, y;

int main()
{
    cin >> x >> y;
    if(y % x != 0)
        cout << (y / x) + 1;
    else
        cout << y / x;
    return 0;
}
