#include <iostream>

using namespace std;

int h, m, x, p;

int main()
{
    cin >> h >> m >> x;
    if(m + x <60){
        if(m == 0)
            cout << h;
        else{
            m = m + x;
            cout << h << ' ' << m;}}
    else{
        p = (m + x) / 60;
        h = h + p;
        m = (m + x) - p * 60;
        if (h >= 24){
            h = h - 24;
            if (m == 0)
                cout << h;
            else
                cout << h << ' ' << m;}
        else
            cout << h << ' ' << m;}

    return 0;
}
