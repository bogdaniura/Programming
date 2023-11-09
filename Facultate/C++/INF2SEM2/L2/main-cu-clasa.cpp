#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Student {
    string nume, spec;
    int an;
    float media;

   public:
    Student(string nume, string spec, int an, float media)
        : nume(nume), spec(spec), an(an), media(media) {}
    static bool compNume(Student* s1, Student* s2) {
        return s1->nume > s2->nume;
    }
    static bool compMedia(Student* s1, Student* s2) {
        return s1->nume < s2->nume;
    }
    static bool afisare(Student* studenti[], int n) {
        for (int i = 0; i < n; i++) {
            cout << '\t' << studenti[i]->nume << ", " << studenti[i]->spec
                 << ", " << studenti[i]->an << ", " << studenti[i]->media
                 << '\n';
        }
        return 0;
    }
};

void sorteaza(Student* tab[], int n, bool (*comparator)(Student*, Student*)) {
    Student* t;
    bool modificat;
    do {
        modificat = false;
        for (int i = 0; i < n - 1; i++) {
            if (comparator(tab[i], tab[i + 1])) {
                swap(tab[i], tab[i + 1]);
                modificat = true;
            }
        }
    } while (modificat);
}

int main() {
    string temp;
    ifstream fin("date.in");
    int i, n;

    Student** studenti = new Student*[n];

    while(fin >> temp){
        n++;
    }
    n = n / 5;

    while (fin >> temp) {
        string nume, spec;
        int an;
        float media;

        fin >> nume >> spec >> an >> media;

        studenti[i++] = new Student(nume, spec, an, media);
    }

    cout << "studentii sortati alfabetic:\n";
    sorteaza(studenti, n, Student::compNume);
    Student::afisare(studenti, n);

    cout << "studentii sortati dupa medii:\n";
    sorteaza(studenti, n, Student::compMedia);
    Student::afisare(studenti, n);

    return 0;
}
