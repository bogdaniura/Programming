#include <iostream>

using namespace std;

int a, x, s1, s2, c = 1;

void actualizeaza(int& s)
{
    x = a % 10;
    s = s + x;
    a = a / 10;
}

int main()
{
    cin >> a;
    do
    {
        if (c % 2 == 1)
        {
            actualizeaza(s1);
        }
        else
        {
            actualizeaza(s2);
        }
        c++;
    } while (a != 0);

    if (c % 2 == 1)
    {
        cout << s1;
    }
    else
    {
        cout << s2;
    }

    return 0;
}
