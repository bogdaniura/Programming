#include <iostream>

using namespace std;
long long n;
int main()
{
    cin >> n;
    if (n % 2 == 0)
        cout << n << ' ' << "este par";
    else
        cout << n << ' ' << "nu este par";
    return 0;
}
