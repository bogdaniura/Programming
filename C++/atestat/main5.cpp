#include <iostream>

using namespace std;

int n;
double f, a, b;

int main()
{
    cin >> a >> b >> n;
    f = a / b;
    f = f - (int)f;
    for (int i = 1; i <= n; i++)
    {
        f = f * 10;
        cout << (int)f % 10;
    }
    return 0;
}