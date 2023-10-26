#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("atestat2.in");
ofstream fout("atestat2.out");

int y, a[1001], n;

int cifredistincte(int n)
{
    int cd = 0, c[10] = {0};
    for (int i = 1; i <= 4 and n != 0; i++) //pt lungimea numarului(maxim 4 cifre)
    {
        c[n % 10] = 1; //constatam ca numarul din coada lui este prezent
        n = n / 10; //eliminam nr din coada
    }
    for (int i = 0; i <= 9; i++) //pentru toate cifrele din baza 10
    {
        cd += c[i]; //nr de cifre distincte creste cu 1, daca i apare in nr, si cu 0 daca nu apare
    }
    return cd;
}

void factoriprimi(int nr)
{
    int div[5001] = {0};
    int lim = nr / 2;
    for (int i = 2; i <= nr and i <= lim; i++) //nr se actualizeaza deci ne trebuie si o constanta in cazul asta
    {
        while (nr % i == 0)
        {
            div[i]++; //creste numarul de divizari pe care le putem efectua pe nr
            nr = nr / i; //impartim nr cu divizorul
        }
        if (div[i] != 0) //daca nr de divizari posibile este diferit de 0
        {
            fout << i << ' ' << div[i] << endl; //afisam divizorul si nr de divizari posibile
        }
    }
}

void citire() //citim numerele
{
    while (fin >> n) //cat timp avem ce sa citim
    {
        if (cifredistincte(n) == 1) //daca are toate cifrele egale
        {
            a[++y] = n; //il punem in vector
        }
    }
}

int main()
{
    citire();
    if (y != 0) //daca avem elemente in vectorul a
    {
        sort(a, a + y + 1); //sortam crescator
        for (int i = 1; i <= y; i++)
        {
            fout << a[i] << ' '; //afisam elementele
        }
        fout << endl;
        factoriprimi(a[y]);
    }
    else //daca vectorul a este nul
    {
        fout << "NU EXISTA";
    }

    return 0;
}