#include <iostream>

using namespace std;

int h, m, x, y, h1, m1;

int main()
{
    cin >> h >> m >> x >> y;
    h1 = h + x;
    if (m + y >= 60){
        m1 = (m + y) - 60;
        h1 = h1 + 1;
        cout << h1 << ' ' << m1;}
    else{
        m1 = m + y;
        cout << h1 << ' ' << m1;}
    return 0;
}
