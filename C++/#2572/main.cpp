#include <iostream>
#include <cmath>

int a;
double n;

using namespace std;

int main()
{
    cin >> a;
    n = sqrt(a);
    if(n % 1 == 0)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
