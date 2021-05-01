#include <iostream>

using namespace std;

int n, fibonacci;
long long fib[4];

int main()
{
    fib[1] = 1;
    fib[2] = 1;
    cin >> n;
    if (n > 2)
    {
        for (int i = 3; i <= n; i++)
        {
            fib[3] = (fib[1] + fib[2]) % 1000000;
            fib[1] = fib[2] % 1000000;
            fib[2] = fib[3] % 1000000;
        }

        cout << fib[3] % 666013 << endl;
    }
    else
    {
        cout << 1;
    }

    return 0;
}