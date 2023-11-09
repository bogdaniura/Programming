#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("date.in");

struct student {
    string nume;
    string prenume;
    string specializare;
    int an;
    float medie;

} s[100];

void afisare(int lungime) {
    for (int i = 0; i < lungime; i++) {
        cout << s[i].nume << ' ' << s[i].prenume << ' ' << s[i].specializare
             << ' ' << s[i].an << ' ' << s[i].medie << ' ' << "\n";
    }
    cout << "\n";
}

int main() {
    int lungime = 0, schimbare, perete = 1;

    while (fin >> s[lungime].nume) {
        fin >> s[lungime].prenume;
        fin >> s[lungime].specializare;
        fin >> s[lungime].an;
        fin >> s[lungime].medie;

        lungime++;
    }

    do {
        schimbare = 0;
        for (int i = 0; i < lungime - perete; i++) {
            if (s[i].medie > s[i + 1].medie) {
                swap(s[i], s[i + 1]);
                schimbare++;
            }
        }
        perete++;
    } while (schimbare != 0);

    afisare(lungime);

    perete = 1;
    do {
        schimbare = 0;
        for (int i = 0; i < lungime - perete; i++) {
            if (s[i].nume[0] > s[i + 1].nume[0]) {
                swap(s[i], s[i + 1]);
                schimbare++;
            }
        }
        perete++;

    } while (schimbare != 0);

    afisare(lungime);
}
