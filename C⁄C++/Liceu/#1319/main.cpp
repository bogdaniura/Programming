#include <iostream>

using namespace std;

int n, f;

int main()
{
cin >> n;
f =2;
do{
if (n % f == 0){
n = n / f;
cout << f << ' ';}
else
f++;
}while (n != 1);

return 0;
}
