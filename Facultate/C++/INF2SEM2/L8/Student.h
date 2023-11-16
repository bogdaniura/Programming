#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Student{
    string  nume, prenume, specializare;
    int an;
    float medie;
public:

   Student(string, string, string, int, float);
   static bool compNume(Student *, Student *);
   static bool compMedia(Student *, Student *);
   void afiseaza();
   friend class TabStudenti;


};
