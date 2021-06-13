#include <iostream>

using namespace std;

int n, m, p, q, s, s1, s2;

int main()
{
    cin >> n >> m >> p >> q;
    s1 = 0;
    s2 = 0;
    while (p <= q)
    {
        if (p % m == 0 or p % n == 0)
        {
            s1++;
        }
        if (p % m == 0 and p % n == 0)
        {
            s2++;
        }
        p++;
    }
    s = s1 - 2 * s2;
    cout << s;

    return 0;
}