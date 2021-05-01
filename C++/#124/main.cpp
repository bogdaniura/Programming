#include <fstream>

using namespace std;

int n, a[10];

ifstream fin("permutari1.in");
ofstream fout("permutari1.out");

void tip()
{
    int i;
    for (i = 1; i <= n; i++)
        fout << a[i] << ' ';
    fout << endl;
}
bool valid(int k1)
{
    for (int i = 1; i <= k1 - 1; i++) // pentru toate elem situate in stg
        if (a[i] == a[k1])
            return false;
    return true;
}

bool solutie(int k1)
{
    return k1 == n;
}
void bt(int k)
{
    int k1 = 0;
    k1 = n - k + 1;
    for (a[k1] = n; a[k1] >= 1; a[k1]--)
        if (valid(k1)) // Valoarea nu se repeta?
            if (solutie(k1))
                tip(); // prezentam o permutare
            else
                bt(k1 + 1); // Trecem la locul urmator.
}
int main()
{
    fin >> n;
    bt(n);
}
