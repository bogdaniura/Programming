#include <iostream>
#include <windows.h>

using namespace std;
int d, i;
string c, s, gresite;
char a;
bool buna;
int span()
{
    cout << "SPANZURATOARE" << endl;
    cout << "Reguli: " << endl << "-cuvintele vor avea doar caractere mici" << endl << "-dupa 6 incercari esuate jocul se va opri" << endl;
    //c = "calculator";
    cin >> c;
    system("cls"); //sterge ce e afisat
    s=c;
    d=c.size();
    for(i = 0;i <= d-1;i++)
        if(c[i] == c[0] or c[i] == c[d-1])
            s[i] = c[i];
        else
            s[i] = '-';
            cout << s;
            cout << endl;
    do{
        cin >> a; buna = false; system("cls");
        for(i = 0;i <= d-1;i++){
            if(c[i] == a){
                s[i] = a;
                buna = true;
                }
                    }
            if(buna == false)
                    gresite = gresite + a; //concatenarea literelor gresite
            cout << s << ' ' << gresite << ' ' <<gresite.size() << endl; // afiseaza cuvantul cu litere lipsa si literele gresite
    }while(s != c and gresite.size() < 6);
    if(gresite.size() >= 6) //daca nr incercarilor gresite este mai mare de 6
        cout << "Ai pierdut!" << endl << "Cuvant: " << c;
    else
        cout << "Ai castigat!";

    return 0;
}


int main(){
    int l;
    cin >> l;
    for(int y=1;y<=l;y++)
 span();
}
