#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sufixe.in");
ofstream fout("sufixe.out");

int n, t, op, nrelem, l, suf;
string s, m[999999], aux;
char c;
bool apartine = false;

int main()
{
    fin >> n >> t; //citim nr de elem din s si nr operatiilor care se vor efectua
    fin >> s;      //citim s
    for (int pas = 1; pas <= t; pas++)
    {
        fin >> op;
        if (op == 1) //operatia nr 1
        {
            fin >> c;  //mai citim un caracter
            s = s + c; //adaugam caracterul la s
            // cout << s << endl;
        }
        else
        {
            if (op == 2) //operatia nr 2
            {
                for (int i = 1; i <= nrelem; i++) //parcurgem multimea m
                {
                    if (s == m[i]) //daca s este deja in multimea m
                    {
                        apartine = true;
                    }
                }
                if (not apartine) //daca nu apartine
                {
                    nrelem++;      //nr de elemente creste
                    m[nrelem] = s; //adaugam sirul in multime
                }
            }
            else
            {
                if (op == 3) //operatia nr 3
                {
                    suf = 0;
                    for (int i = 1; i <= nrelem; i++)
                    {
                        l = m[i].size();
                        // cout << m[i] << l << i << endl;
                        // cout << s.size() << ' ' << l << ' ' << s.size() - l << ' ';
                        for (int j = s.size() - l; j <= s.size() - 1; j++)
                        {
                            // cout << j << endl;
                            aux = aux + s[j];
                            // cout << endl << aux;
                        }
                        // cout << aux << ' ' << m[i] << endl << aux.size() << ' ' << m[i].size() << endl;
                        if (aux == m[i])
                        {
                            suf++;
                        }
                        aux.erase(0, aux.size());
                    }
                    fout << suf << endl;
                }
            }
        }
    }

    return 0;
}