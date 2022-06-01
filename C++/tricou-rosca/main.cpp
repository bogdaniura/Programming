#include <iostream>
#include <fstream>

using namespace std;

ifstream in("clasa a X-a.in");
ofstream out("clasa a XII-a.out");

string absenta;

int main()
{
    in >> absenta;

    if (absenta == "motivata"){ //daca absenta este motivata
        out << "Samba si, trabajo no!"; //vorbe de duh
    }
    else{ //daca absenta nu este motivata
        out << "In momentul asta mergeti toti la scoala!"; //amenintare
    }

    return 0;
}