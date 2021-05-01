#include <iostream>

using namespace std;

int n;
bool a[11][11];
bool gata = false;

bool sol(int k)
{
   return k == n; //daca am pus 4 de "1" pe tabla  atunci returnam "true"
}

bool valid()
{
   // cout << "valid?" << endl;
   for (int l1 = 1; l1 <= n; l1++) //parcurgen matricea
   {
      for (int c1 = 1; c1 <= n; c1++)
      {
         if (a[l1][c1] == 1) // cand am gasit 1
         {
            for (int l2 = 1; l2 <= n; l2++) //verificam daca mai exista o regina pe aceeasi coloana
            {
               if (a[l2][c1] == 1 and l2 != l1) //daca da, nu e valid
               {
                  return false; //iesim din funtie
               }
            }
            for (int c2 = 1; c2 <= n; c2++) ////verificam daca mai exista o regina pe aceeasi linie
            {
               if (a[l1][c2] == 1 and c2 != c1) //daca da, nu e valid
               {
                  return false; //iesim din funtie
               }
            }

            //un for ca sa verificam ca nu exista 1 pe diagonala

            int l2 = l1 + 1;
            int c2 = c1 + 1;
            while (l2 <= n and c2 <= n)
            {
               if (a[l2][c2] == 1)
               {
                  return false;
               }
               else
               {
                  l2++;
                  c2++;
               }
            }
            l2 = l1 + 1;
            c2 = c1 - 1;
            while (l2 <= n and c2 >= 1)
            {
               if (a[l2][c2] == 1)
               {
                  return false;
               }
               else
               {
                  l2++;
                  c2--;
               }
            }
            l2 = l1 - 1;
            c2 = c1 - 1;
            while (l2 >= 1 and c2 >= 1)
            {
               if (a[l2][c2] == 1)
               {
                  return false;
               }
               else
               {
                  l2--;
                  c2--;
               }
            }
            l2 = l1 - 1;
            c2 = c1 + 1;
            while (l2 >= 1 and c2 <= n)
            {
               if (a[l2][c2] == 1)
               {
                  return false;
               }
               else
               {
                  l2--;
                  c2++;
               }
            }
         }
      }
   }

   return true;
}

void tip() //funtie de afisare
{
   for (int l2 = 1; l2 <= n; l2++)
   {
      if (l2 != 1) //afiseaza endl inainte inainte de fiecare linie inafara de prima
      {
         cout << endl;
      }
      for (int c2 = 1; c2 <= n; c2++)
      {
         if (a[l2][c2] == 1)
         {
            cout << "*" << ' ';
         }
         else
         {
            cout << "-" << ' ';
         }
      }
   }
}

void bt(int k)
{
   if (k <= n and not gata)
   {
      for (int z2 = 1; z2 <= n; z2++) //parcurgem mat pe coloana
      {
         a[k][z2] = 1; //punem elementul
         // tip();
         // cout << endl;
         // cout << k << z2 << endl;
         if (valid()) //daca e valid
         {
            if (sol(k)) //daca e sol
            {
               tip(); //afisam
               gata = true;
            }
            else
               bt(k + 1); //daca nu e solutie, trecem la urmatoarea linie
         }
         a[k][z2] = 0;
      }
   }
}

int main()
{
   cin >> n;
   for (int l2 = 1; l2 <= n; l2++)
   {
      for (int c2 = 1; c2 <= n; c2++)
      {
         a[l2][c2] = 0;
      }
   }
   bt(1);
   return 0;
}