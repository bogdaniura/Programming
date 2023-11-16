#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Student {
public:
    string nume, prenume, specializare;
    int an;
    float medie;

    Student(string nume, string prenume, string specializare, int an, float medie)
        : nume(nume), prenume(prenume), specializare(specializare), an(an), medie(medie) {}

    static bool compNume(Student* a, Student* b) {
        // Implementation for comparing by name
        return a->nume < b->nume;
    }

    static bool compMedia(Student* a, Student* b) {
        // Implementation for comparing by media
        return a->medie > b->medie;
    }

    void afiseaza() {
        cout << nume << ' ' << prenume << ' ' << specializare << ' ' << an << ' ' << medie << '\n';
    }

    friend class TabStudenti;
};
