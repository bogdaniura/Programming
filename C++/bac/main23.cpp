#include <iostream>
#include <fstream>

using namespace std;

ifstream in("f.in");

int a, s;
bool p[101];

int main()
{

    while (in >> a)
    {
        if (!p[a])
        {
            s = s + 10 + a * a;
            p[a] = true;
        }
        else{
            s = s + a * a;
        }
    }
    cout << s;

    return 0;
}