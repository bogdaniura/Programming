#include <iostream>

using namespace std;

int n, c, s;

int main()
{
    cin >> n;
    do{
        c = n % 10;
        s = s * 10 + c;
        n = n / 10;
    }while(n > 0);
        cout << s;
    return 0;
}
