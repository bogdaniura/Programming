#include <iostream>

using namespace std;

int d, i, r;

int main()
{
cin >> d >> i;
if (i == 0)
cout << "i nu poate sa fie 0    ";
else
do {
r = d % i;
d = i;
i = r;
} while (r > 0);
cout << d;
return 0;
}
