#include <iostream>
#include <string>

using namespace std;

struct Student {
    string nume;
    string prenume;
    string specializare;
    int an;
    float medie;

    Student(const string& n, const string& p, const string& s, int a, float m)
        : nume(n), prenume(p), specializare(s), an(a), medie(m) {}
};

class Nod {
public:
    Student student;
    Nod* next;

    Nod(const Student& s) : student(s), next(nullptr) {}
};

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