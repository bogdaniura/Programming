#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat6.in");
ofstream fout("atestat6.out");

int k, a, diviz, p, u, ult;
bool f[100];

int divizori(int d)
{
    int d1 = 0, i = 1;

    for (i = 2; i * i < d; i++)
    {
        if (d % i == 0)
        {
            d1 += 2;
        }
    }
    if(i * i == d){
        d1++;
    }
    return d1;
}

int main()
{
    fin >> k;
    while (fin >> a)
    {
        f[a] = true;
    }
    for (int i = 4; i <= 99; i++)
    {
        if (f[i])
        {
            if (divizori(i) >= k)
            {
                fout << i << ' ';
                ult = i;
            }
        }
    }
    p = ult / 10;
    u = ult % 10;
    if (p % 2 == u % 2)
    {
        cout << "\n"
             << "DA";
    }
    else
    {
        fout << "\n"
             << "NU";
    }
    return 0;
}