#include <iostream>
#include <fstream>

using namespace std;

ifstream in("secventeneuniforme.in");
ofstream out("secventeneuniforme.out");

int main()
{
    int a, b, c, l = 0, lmax = -1;

    in >> a;
    l = 1;
    in >> b;

    do
    {
        in >> b;
    } while (a == b);
    
    if (a != b)
    {
        l = 2;
    }

    while (in >> c)
    {
        if (a != b and a != c and b != c)
        {
            l++;
        }
        else
        {
            if (l > lmax)
            {
                lmax = l;
            }
            l = 2;
        }
        a = b;
        b = c;
    }
    out << max(l, lmax);

    return 0;
}