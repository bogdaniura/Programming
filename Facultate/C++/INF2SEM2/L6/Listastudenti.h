#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Student.h>
#include <Nod.h>

using namespace std;

class ListaStudenti {
private:
    Nod* cap;

public:
    ListaStudenti() : cap(nullptr) {}

    void adauga(const Student& s) {
        Nod* nou = new Nod(s);
        nou->next = cap;
        cap = nou;
    }

    void afiseaza() {
        Nod* current = cap;
        while (current != nullptr) {
            cout << current->student.nume << ' ' << current->student.prenume << ' '
                 << current->student.specializare << ' ' << current->student.an << ' '
                 << current->student.medie << '\n';

            current = current->next;
        }
        cout << '\n';
    }

    void sterge(const string& numePrenume) {
        Nod* current = cap;
        Nod* prev = nullptr;

        while (current != nullptr &&
               (current->student.nume + ' ' + current->student.prenume) != numePrenume) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Studentul cu numele " << numePrenume << " nu a fost gasit.\n";
            return;
        }

        if (prev == nullptr) {
            cap = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        cout << "Studentul " << numePrenume << " a fost sters.\n";
    }
};
