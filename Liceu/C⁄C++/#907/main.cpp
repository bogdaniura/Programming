#include <iostream>

using namespace std;
int a, b;

void afisare(int a, int b)
{
   if (b < a)
   {
      swap(a, b);
   }

   a = a + a % 2;

   for (int i = a; i <= b; i += 2)
   {
      cout << i << ' ';
   }
}

int main()
{
   cin >> a >> b;
   afisare(a, b);
   return 0;
}