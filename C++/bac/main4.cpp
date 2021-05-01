//alcatuim un vector de frecventa pentru numerele citite
//afisam numerele impare de cate ori apar cu ajutorul vectorului de frecventa, utilizant un contor care porneste de la 1 si creste din 2 in 2
//afisam numerele pare de cate ori apar cu ajutorul vectorului de frecventa, utilizant un contor care porneste de la 2 si creste din 2 in 2
//eficienta algoritmului consta in faptul ca folosim un singur vector, iar operatiile sunt simple

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("bac4.in");

int a, fr[1000000], maxim;

int main()
{
    while (fin >> a)
    {
        fr[a]++;
        if (a > maxim)
        {
            maxim = a;
        }
    }
    for (int i = 1; i <= maxim; i += 2)
    {
        if (fr[i] != 0)
        {
            for (int j = 1; j <= fr[i]; j++)
            {
                cout << i << ' ';
            }
        }
    }
    for (int i = 2; i <= maxim; i += 2)
    {
        if (fr[i] != 0)
        {
            for (int j = 1; j <= fr[i]; j++)
            {
                cout << i << ' ';
            }
        }
    }

    return 0;
}