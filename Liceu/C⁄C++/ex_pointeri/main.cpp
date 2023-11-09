#include <iostream>

using namespace std;


struct Nod{
    int info;
    Nod * urm;
};

Nod p, c;


int main()
{
    p = new Nod;
    cout << p->info;

    return 0;
}
