#include <array>
#include <iostream>

using namespace std;

struct nod {
    int vecin;
    string denumire;
};

void afisare(nod lista[101], int lungime_lista) {
    for (int i = 0; i < lungime_lista; i++) {
        cout << lista[i].vecin << lista[i].denumire << "\n";
    }
}

void adauga_element(nod lista[101], int &lungime_lista, int &cmmvecin, string denumire_element) {
    cmmvecin++;
    lista[lungime_lista-1].vecin = cmmvecin;
    lista[lungime_lista].vecin = 0;    
    lista[lungime_lista].denumire = denumire_element;
    lungime_lista++;

}

void extrage_element_final(){
    
}

int main() {
    nod lista[101] = {{1, "a"}, {2, "b"}, {0, "c"}};
    int lungime_lista = 3, cmmvecin = 2;

    adauga_element(lista,lungime_lista,cmmvecin,"d");
    adauga_element(lista,lungime_lista,cmmvecin,"e");
    adauga_element(lista,lungime_lista,cmmvecin,"f");
    afisare(lista,lungime_lista);
}