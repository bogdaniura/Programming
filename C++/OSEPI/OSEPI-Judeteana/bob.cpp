#include <iostream>

using namespace std;

int p, t, n, k, a[200001][21], i, j, r[200001], v;
bool fr[21];

int sumfr()
{
    int s = 0;
    for (int i = 1; i <= k; i++)
    {
        s = s + fr[i];
    }
    return s;
}

void resetfr()
{
    for (int i = 1; i <= k; i++)
    {
        fr[i] = 0;
    }
}

int main()
{
    cin >> p;
    cin >> t;
    for (int t1 = 1; t1 <= t; t1++)
    {
        cin >> n >> k;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= k; j++)
            {
                cin >> a[i][j];
            }
        }
        if (p == 1)
        {
            i = 1;
            do
            {
                for (; i <= n and sumfr() != k; i++)
                {
                    for (j = 1; j <= k; j++)
                    {
                        if (a[i][j] == 1)
                        {
                            fr[j] = true;
                        }
                    }
                }
                if (sumfr() == k)
                {
                    resetfr();
                    r[t1]++;
                }
            } while (i <= n);
        }
        else
        {
            //backtracking?
        }
    }
    for (int i = 1; i <= t; i++)
    {
        cout << r[i] << endl;
    }
    return 0;
}