#include <iostream>
#include <fstream>

using namespace std;

struct obiect
{
    int k;         //eticheta
    float g, p, e; //greutate, profit, eficienta
};

ifstream fin("greedy.in");
obiect a[1001], aux;
int n, profit;
float G, Gr, x[1001];

void citire()
{
    cin >> n >> G;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].g >> a[i].p;
        a[i].e = a[i].p / a[i].g;
        a[i].k = i;
    }
}

void sort()
{
    for (int j = n; j > 1; j--)
    {
        for (int i = 1; i <= j - 1; i++)
        {
            if (a[i].e < a[i + 1].e)
            {
                swap(a[i], a[i + 1]);
            }
        }
    }
}

void greedy()
{
    Gr = G;
    for (int i = 1; (i <= n) and Gr > 0; i++)
    {
        if (a[i].g <= Gr)
        {
            Gr -= a[i].g;
            x[i] = 1;
        }
        else
        {
            x[i] = Gr / a[i].g;
            Gr = 0;
        }
        profit += a[i].p * x[i];
        cout << a[i].k << ' ' << x[i] << "\n";
    }
}

void afisare()
{
    cout << profit;
}

int main()
{
    citire();
    sort();
    greedy();
    afisare();
    
    return 0;
}