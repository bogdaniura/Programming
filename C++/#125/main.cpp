#include <fstream>
#include <algorithm>

using namespace std;

int n, a[10], b[10];

ifstream fin("permutari2.in");
ofstream fout("permutari2.out");

bool ok(int k)
{
    for (int i = 1; i <= k - 1; i++)
    {
        if (b[i] == b[k])
        {
            return false;
        }
    }
    return true;
}

bool sol(int k)
{
    return k == n;
}

void afis()
{
    for (int i = 1; i <= n; i++)
    {
        fout << b[i] << ' ';
    }
    fout << endl;
}

void bt(int k)
{
    for (int i = 1; i <= n; i++)
    {
        b[k] = a[i];
        if (ok(k))
        {
            if (sol(k))
            {
                afis();
            }
            else
            {
                bt(k + 1);
            }
        }
    }
}

int main()
{
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> a[i];
    }
    sort(a, a + n + 1);
    bt(1);
}