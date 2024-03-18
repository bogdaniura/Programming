#include <array>
#include <iostream>

using namespace std;

struct nod {
    int nrord;
    string denumire;
};

void afisare(nod lista[101], int lungime_lista) {
    for (int i = 0; i < lungime_lista; i++) {
        cout << lista[i].nrord << lista[i].denumire << "\n";
    }
}

void adauga_element(nod lista[101], int &lungime_lista, int &cmmnrord, string denumire_element) {
    cmmnrord++;
    lista[lungime_lista].nrord = cmmnrord;
    lista[lungime_lista].denumire = denumire_element;
    lungime_lista++;

}

int main() {
    nod lista[101] = {{0, "a"}, {1, "b"}, {2, "c"}};
    int lungime_lista = 3, cmmnrord = 2;

    adauga_element(lista,lungime_lista,cmmnrord,"d");
    adauga_element(lista,lungime_lista,cmmnrord,"e");
    adauga_element(lista,lungime_lista,cmmnrord,"f");
    afisare(lista,lungime_lista);
}