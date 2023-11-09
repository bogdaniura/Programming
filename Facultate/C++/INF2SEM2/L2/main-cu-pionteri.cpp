#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

struct student {
    string nume;
    string prenume;
    string specializare;
    int an;
    float medie;
};

void afisare(student* students, int lungime) {
    for (int i = 0; i < lungime; i++) {
        cout << students[i].nume << ' ' << students[i].prenume << ' '
             << students[i].specializare << ' ' << students[i].an << ' '
             << students[i].medie << ' ' << "\n";
    }
    cout << "\n";
}

int main() {
    ifstream fin("date.in");

    int lungime = 0;
    student* s = new student[100];

    while (fin >> s[lungime].nume) {
        fin >> s[lungime].prenume;
        fin >> s[lungime].specializare;
        fin >> s[lungime].an;
        fin >> s[lungime].medie;

        lungime++;
    }

    // sortare dupa medie
    sort(s, s + lungime,
         [](const student& a, const student& b) { return a.medie < b.medie; });

    afisare(s, lungime);

    // sortare alfabetica
    sort(s, s + lungime, [](const student& a, const student& b) {
        return a.nume[0] < b.nume[0];
    });

    afisare(s, lungime);

    delete[] s;
}
