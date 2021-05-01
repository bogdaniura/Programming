#include <iostream>

using namespace std;

int st, dr, minim = 500001, t;
short n, a[500001];



int main()
{
    cin >> n;                    //citim n
    for (int i = 1; i <= n; i++) //citim n elemente
    {
        cin >> a[i];
    }

    for (st = 1; st < n and t != 1; st++) //pentru fiecare element, atata timp cat t e diferit de 1(distanta minima)
    {
        dr = st + 1;                      //dr incepe din dreapta lui st
        while (a[st] != a[dr] and dr < n) //cat timp sunt diferite si dr < n
        {
            dr++; //dr se deplaseaza in  6 7 8 9dreapta
        }
        if (a[st] == a[dr]) //daca am gasit o pereche
        {
            t = dr - st; //aflam perioada
            if (t < minim) //dc e mai mica decat minimul, minimul = t
            {
                minim = t;
            }
        }
    }
    if (minim != 500001)
    {
        cout << minim;
    }
    else
    {
        cout << n;
    }
    
    return 0;
}