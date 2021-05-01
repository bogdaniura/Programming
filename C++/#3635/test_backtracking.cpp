#include <fstream>

using namespace std;

int n, a[10];

ofstream fout("numere.out");

void tip () {
    int i;
    for (i = 1; i <= n; i++)
        fout << a[i] << ' ';
    fout << endl;
}
bool valid (int k) {
    return a[1] != 0;
}

bool solutie(int k){
    return a[1] == a[2];
}
void bt (int k) {
    for (a[k] = 0; a[k] <= 9; a[k]++)
        if (valid(k)) // Valoarea nu se repeta?
            if (solutie(k))
                tip(); // prezentam o permutare
            else
                bt(k + 1); // Trecem la locul urmator.
}

int main () {
    n = 2;
    bt(1);
}