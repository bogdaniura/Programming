#include <iostream>

using namespace std;

int a, n;

int main()
{
    cin >> n;
    for (a = 1;a <= 2*n;a++)
        if (a % 2 == 0)
        cout << a << ' ';
    return 0;
}
