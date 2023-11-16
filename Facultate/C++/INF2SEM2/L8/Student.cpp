#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Student {
    string nume, prenume, specializare;
    int an;
    float medie;

public:
    Student(string, string, string, int, float);
    static bool compNume(Student *, Student *);
    static bool compMedie(Student *, Student *);
    void afiseaza();
    friend class TabStudenti;
};

Student::Student(string nume, string prenume, string specializare, int an, float medie):
    nume(nume), prenume(prenume), specializare(specializare), an(an), medie(medie) {}

bool Student::compNume(Student *s1, Student *s2) {
    return s1->nume > s2->nume;
}

bool Student::compMedie(Student *s1, Student *s2) {
    return s1->medie < s2->medie;
}

void Student::afiseaza() {
    cout << '\t' << nume << ", " << specializare << ", " <<
        an << ", " << medie << '\n';
}
