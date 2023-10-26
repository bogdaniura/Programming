#include <iostream>

using namespace std;

int a, x, s;

int main()
{
    cin >> a;
    do{
        x = a % 10;
        s = s + x;
        a = a /10;
    }while (a != 0);
    cout << s ;
    return 0;
}
