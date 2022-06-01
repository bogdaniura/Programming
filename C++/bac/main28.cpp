#include <iostream>
#include <fstream>

using namespace std;

ifstream in("f.in");

int a, p[1001];

int main()
{

    while (in >> a)
    {
        p[a]++;
    }
    for (int i = 1; i <= 999; i += 2)
    {
        if (p[i])
        {
            for (int j = 1; j <= p[i]; j++)
            {
                cout << i << ' ';
            }
        }
    }
    for (int i = 2; i <= 999; i += 2)
    {
        if (p[i])
        {
            for (int j = 1; j <= p[i]; j++)
            {
                cout << i << ' ';
            }
        }
    }

    return 0;
}