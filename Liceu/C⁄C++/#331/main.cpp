#include <iostream>

using namespace std;

int a, n;

int main()
{
    cin >> n;
    for (a = 2*n;a >= 1;a--)
        if (a % 2 == 1)
        cout << a << ' ';
    return 0;
}
