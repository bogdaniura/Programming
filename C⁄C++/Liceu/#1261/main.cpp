#include <iostream>

using namespace std;

int a, k;

int main()
{
    k = 0;
    cin >> a;
    while(a != 0){
        if (a % 2 == 0)
            k = k + 1;
            cin >> a;}
        if (k == 0)
            cout << "NU EXISTA";
        else
            cout << k;
    return 0;
}
