#include <fstream>

using namespace std;

ifstream fin("veriflant.in");
ofstream fout("veriflant.out");

int v1, v2, m, n, vs, nsv, sir[201];
bool graf[101][101];

bool v_sir()
{
    bool advsir = 1;
    int i = 1;

    while (advsir == 1 and i <= vs - 1)
    {
        if (graf[sir[i]][sir[i + 1]] == 0 and graf[sir[i + 1]][sir[i]] == 0)
            advsir = 0;
        i++;
    }
    return advsir;
}
bool v_elementar()
{
    bool advelem = 1;
    int g = 1, fr[101];

    for (int p = 1; p <= 101; p++)
        fr[p] = 0;

    for (int j = 1; j <= vs; j++)
    {
        fr[sir[j]]++;
    }
    while (g <= vs and advelem == 1)
    {
        if (fr[sir[g]] > 1)
            advelem = 0;
        g++;
    }
    return advelem;
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= m; i++)
    { //matrice de adiacenta
        fin >> v1 >> v2;
        graf[v1][v2] = graf[v2][v1] = 1;
    }
    fin >> nsv; //nr de siruri
    for (int k = 1; k <= nsv; k++)
    {
        fin >> vs; //nr elemente din sir
        for (int i = 1; i <= vs; i++)
        {
            fin >> sir[i]; //elemente sir
        }
        if (not v_sir()) //verificare daca nu e sir
            fout << "NU" << endl;
        else
        {                      //daca e sir
            if (v_elementar()) //verificam daca e elementar
                fout << "ELEMENTAR" << endl;
            else
                fout << "NEELEMENTAR" << endl;
        }
    }
    return 0;
}
