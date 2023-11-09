#include <fstream>

using namespace std;

int n, a[10];

ifstream fin("numere.in");
ofstream fout("numere.out");

void tip () {
    int i;
    for (i = 1; i <= n; i++)
        fout << a[i] << ' ';
    fout << endl;
}
bool valid (int k) {
    int i;
    for (i = 1; i <= k-1; i++) // pentru toate
        if (a[i] == a[k])
            return false;
    return true;
}

bool solutie(int k){
    return k == n;
}
void bt (int k) {
    for (a[k] = 1; a[k] <= n; a[k]++)
        if (valid(k)) // Valoarea nu se repeta?
            if (solutie(k))
                tip(); // prezentam o permutare
            else
                bt(k + 1); // Trecem la locul urmator.
}

int main () {
    n = 3;;
    bt(1);
}