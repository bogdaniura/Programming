#include <iostream>
#include <string>
#include <Student.h>
#include <Listastudenti.h>
#include <Nod.h>
#include <AltStudent.h>


using namespace std;

int main() {
    ListaStudenti lista;

    // Adauga studenti
    lista.adauga(Student("Popescu", "Ion", "Informatica", 2, 9.5));
    lista.adauga(Student("Ionescu", "Maria", "Matematica", 1, 8.0));
    lista.adauga(Student("Georgescu", "Mihai", "Fizica", 3, 7.2));

    // Afiseaza lista
    cout << "Lista initiala:\n";
    lista.afiseaza();

    // Sterge un student
    lista.sterge("Ionescu Maria");

    // Afiseaza lista dupa stergere
    cout << "Lista dupa stergere:\n";
    lista.afiseaza();

    return 0;
}