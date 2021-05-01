#include <iostream>

using namespace std;

int n, u, s;

int main()
{
    cin >> n;
    do
    {
        s = 0;
        do
        {
            u = n % 10;
            s = s + u;
            n = n / 10;
        } while (n > 0);
        n = s;
    } while (s >= 10);
    cout << s;
    return 0;
}