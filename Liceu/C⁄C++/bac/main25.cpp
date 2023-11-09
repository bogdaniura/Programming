#include <iostream>
#include <fstream>

using namespace std;

ifstream in("f.in");

int main()
{
    int n, a, b, a1, b1;

    in >> n >> a;
    while (in >> b)
    {
        if (a % 1000 == n and b % 1000 == n)
        {
            a1 = a;
            b1 = b;
        }
        a = b; 
    }
    cout << a1 << ' ' << b1;

    return 0;
}