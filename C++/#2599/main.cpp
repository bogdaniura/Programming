#include <iostream>

using namespace std;

long long s;

int a, i;

int main()
{
    cin >> a;
    s = 1;
    for(i = 1;i <= 16;i++)
        s = s * a;
    cout << s;
    return 0;
}
