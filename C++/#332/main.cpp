#include <iostream>

using namespace std;

int n, a, S;

int main()
{
    S = 0;
    cin >> n;
    for(a = 1;a <= n;a++)
        S = S + (a*(a +1));
    cout << "Rezultatul este" << ' ' << S;
    return 0;
}
