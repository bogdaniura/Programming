#include <iostream>

using namespace std;

int a, b, i, I, x, y, p;

int main()
{ cin >> a >> b;
i = a % 2 + b % 2;
x = a / 10;
y = b / 10;
I = x % 2 + y % 2;
i = i + I;
if (a % 2 != b % 2)
cout << i;
else {
p = 4 - i;
cout << p;
}
return 0; }
