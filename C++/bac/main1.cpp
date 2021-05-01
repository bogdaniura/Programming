#include <iostream>

using namespace std;

int a, b;

int suma(int a, int b)
{
    int s = 0;
    for (int i = 2; i <= min(a, b) / 2; i++)
    {
        if (a % i == 0 and b % i == 0)
        {
            s = s + i;
        }
    }
    return s;
}

int main()
{
    cin >> a >> b;
    cout << suma(a, b);
    return 0;
}