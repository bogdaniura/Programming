#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nr.in");

int n, a[101], suma;

bool sumsearch()
{
    int stg = 1, dr = n, s;
    do
    {
        s = a[stg] + a[dr];
        if (s == suma)
        {
            return true;
        }
        else
        {
            if (s < suma)
            {
                stg++;
            }
            else
            {
                dr--;
            }
            
        }

    } while (stg < dr);
    return false;
}

int main()
{

    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> a[i];
    }
    fin >> suma;
    cout << sumsearch();

    return 0;
}