#include <iostream>
#include <fstream>

using namespace std;

#define MARGINE 9999

int l, c, mat[101][101], D, R;
bool P;

ifstream fin("mat.in");
ofstream fout("mat.out");

void citmat() //citim matricea
{
    fin >> l >> c; //cate linii cate coloane
    for (int l1 = 1; l1 <= l; l1++)
    {
        for (int c1 = 1; c1 <= c; c1++)
        {
            fin >> mat[l1][c1];
        }
    }
}

void afismat() //afisam matricea
{
    for (int l1 = 1; l1 <= l; l1++)
    {
        fout << endl;
        for (int c1 = 1; c1 <= c; c1++)
        {
            fout << mat[l1][c1] << ' ';
        }
    }
    fout << endl;
}

bool patratica() //verificam daca matricea e patratica
{
    return l == c;
}

int determinant(int ord, int mat[101][101]) //aflam determinantul //transmitem ordinul determinantului de funtie la alta(functie recursiva)
{
    
    if (ord == 2)
    {
        return (mat[1][1] * mat[2][2]) - (mat[1][2] * mat[2][1]);
    }
    else
    {
        for(int l1 = 1;l1 <= l;)
    }
    
}

void afisdet() //afisam determinantul
{
    fout << "detMAT = ";
    if (P) //daca matricea e patratica
    {
        D = determinant(l); //memoram valoarea determinantului
        fout << D;
    }
    else
    {
        fout << "NU EXISTA";
    }
}

int rangmat() //aflam rangul matricii nepatratice
{

    // for (int l1 = 1; l1 <= l; l1++)
    // {
    //     for (int c1 = 1; c1 <= c; c1++)
    //     {
    //         if (mat[l1][c1] != 0)
    //         {
    //             l2 = l1; //retinem valoarea
    //             c2 = c1;
    //             l1 = l+1; //iesim din structura repetitiva
    //             c1 = c+1;
    //         }
    //     }
    // }
}

void afisrang() //afisam rangul matricii
{
    fout << "rangMAT = ";
    if (P and D != 0) //daca e patratica si determinantul este diferit de 0
    {
        fout << D; //rangul este egal cu determinantul
    }
    else
    {
        R = rangmat();
        fout << R;
    }
}

int main()
{
    citmat();
    P = patratica();
    afisdet();
    fout << endl;
    afisrang();

    return 0;
}
