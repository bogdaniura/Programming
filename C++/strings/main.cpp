#include <iostream>
#include <fstream>

using namespace std;

ifstream in("f.in");
ofstream out("f.out");

int main()
{
    string text[12], x;
    int k = 1;

    while (in >> text[k]) // cat timp avem ce sa citim din fisier
    {
        k++;
    }

    x = text[k - 1];

    for (int i = 1; i <= k - 2; i += 2) // trebuie sa verificam doar prenumele
    {
        if (text[i] == x) // daca am gasit prenumele
        {
            out << text[i + 1].substr(0, text[i + 1].size() - 1) << endl; // afisam numele fara ";"
        }
    }

    return 0;
}