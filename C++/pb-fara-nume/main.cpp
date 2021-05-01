#include <iostream>
#include <fstream>

using namespace std;

int n, a, c, p;

ifstream fin("nr.in");
ofstream fout("nr.out");

int main()
{
    fin >> n >> c;
    for (int i = 2; i <= n; i++)
    {
        fin >> a;
        if (a < c)
        {
            p++;
        }
    }
    fout << p + 1;
    return 0;
}