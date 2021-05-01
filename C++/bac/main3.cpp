#include <iostream>

using namespace std;

int a, b, c, x;

int main()
{
    cin >> a;
    c = 0;
    do
    {
        b = a;
        x = 0;
        do
        {
            if (b % 10 == c)
            {
                x = 1;
            }
            b = b / 10;

        } while (b != 0 or x != 1);
        cout << x;
        c = c + 2;

    } while (c <= 9);
}