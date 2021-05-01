//intai alcatuim un vector de frecventa pentru numerele citite
//verificam ca fiecare element al vectorului de frecventa sa fie par, exceptie fiind numarul din mijloc, in cazul in care se citeste un nr impar de numere
#include <iostream>

using namespace std;

int a, fr[1001], n, maxim = 0;

bool par()
{
    return n % 2 == 0;
}

int frecvimpare()
{
    int imp = 0;
    for (int i = 1; i <= maxim; i++)
    {
        if (fr[i] % 2 == 1)
        {
            imp++;
        }
    }
    return imp;
}

bool palindromic()
{
    if (par())
    {
        if (frecvimpare() != 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if (frecvimpare() != 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

void frecventa()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        fr[a]++;
        if (a > maxim)
        {
            maxim = a;
        }
    }
}

int main()
{
    cin >> n;
    frecventa();
    if (palindromic())
    {
        cout << "DA";
    }
    else
    {
        cout << "NU";
    }
}