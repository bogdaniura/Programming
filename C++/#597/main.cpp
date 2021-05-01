#include <iostream>

using namespace std;

int l, c, a[101][101], li, lf, ci, cf;

void  afisare(){
   for (int l1 = li; l1 <= lf; l1++)
   {
      cout << endl;
      for (int c1 = ci; c1 <= cf; c1++)
      {
         cout << a[l1][c1] << ' ';
      }
   }
}

int main()
{
   cin >> l >> c;
   for (int l1 = 1; l1 <= l; l1++) //citim matricea
   {
      for (int c1 = 1; c1 <= c; c1++)
      {
         cin >> a[l1][c1];
      }
   }

   for (int l1 = 1; l1 <= l; l1++)
   {
      for (int c1 = 1; c1 <= c; c1++)
      {
         if (a[l1][c1] == 1)
         {
            li = l1;
            c1 = c+1;
            l1 = l+1;
         }
      }
   }
   for (int l1 = l; l1 >= 1; l1--)
   {
      for (int c1 = 1; c1 <= c; c1++)
      {
         if (a[l1][c1] == 1)
         {
            lf = l1;
            c1 = c+1;
            l1 = 0;
         }
      }
   }
   for (int c1 = 1; c1 <= c; c1++)
   {
      for (int l1 = li; l1 <= lf; l1++)
      {
         if (a[l1][c1] == 1)
         {
            ci = c1;
            c1 = c+1;
            l1 = lf+1;
         }
      }
   }
   for (int c1 = c; c1 >= 1; c1--)
   {
      for (int l1 = li; l1 <= lf; l1++)
      {
         if (a[l1][c1] == 1)
         {
            cf = c1;
            c1 = 0;
            l1 = lf+1;
         }
      }
   }
   cout << lf - li + 1 << ' ' << cf - ci + 1;
   afisare();

   
   return 0;
}