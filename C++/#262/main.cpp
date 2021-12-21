#include <fstream>

using namespace std;

ifstream in("intervale1.in");
ofstream out("intervale1.out");

int n;
float a, b, dif = 999999999;

int main()
{
    in >> n;
    in >> a;
    for (int i = 1; i <= n - 1; i++)
    {
        in >> b;
        dif = min(dif, (b - a));
        a = b;
    }
    if (int(dif) == dif or int(dif) == dif - 0.5)
        out << (int)(dif + 0.5) - 1;
    else
        out << (int)(dif + 0.5);

    return 0;
}