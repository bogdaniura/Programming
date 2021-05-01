#include <cstdlib>
#include <ctime>
#include <iostream>
int pariu, mana;
using namespace std;

int carte(){
int ln = 1,un = 10;
    srand(time(0));
    carte = ln + (rand()%un);
    return carte;
}

int main(){
    cin >> pariu;
    mana = carte();
    cout << mana;
}
