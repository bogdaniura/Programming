#include <iostream>
#include <fstream>

using namespace std;

ifstream in("f.in");

int nl, nc, a[101][101];
bool sim = true;

int main()
{
    in >> nl >> nc;
    for (int l = 1; l <= nl; l++)
    {
        for (int c = 1; c <= nc; c++)
        {
            in >> a[l][c];
        }
    }
    for (int c1 = 1, c2 = nc; c1 <= nc / 2 and c2 >= nc / 2; c1++, c2--)
    {
        for (int l = 1; l <= nl; l++)
        {
            if (a[l][c1] != a[l][c2])
            {
                sim = false;
                c1 = 50;
            }
        }
    }

    if (sim)
    {
        cout << "DA";
    }
    else
    {
        cout << "NU";
    }

    return 0;
}