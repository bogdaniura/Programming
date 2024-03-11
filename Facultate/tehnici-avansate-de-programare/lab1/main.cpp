#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("fisier.in");
ofstream fout("fisier.out");

struct lcv {
    int linie;
    int coloana;
    int valoare;
} vector[1000];

int main() {
    int nr_linii, nr_coloane, dim = 0, element;
    fin >> nr_linii >> nr_coloane;
    for (int i = 0; i < nr_linii; i++) {
        for (int j = 0; j < nr_coloane; j++) {
            fin >> element;
            if (element != 0) {
                vector[dim].linie = i;
                vector[dim].coloana = j;
                vector[dim].valoare = element;
                dim++;
            }
        }
    }
    for (int i = 0; i < dim; i++) {
        fout << vector[i].linie << ' ' << vector[i].coloana << ' '
             << vector[i].valoare << "\n";
    }
}
