#include <iostream>
#include <fstream>

using namespace std;

ifstream in("f.in");
ofstream out("f.out");

int l1, l2, s1[100001], s2[100001], u1, u2, p1, p2, perechi;

int main()
{
    in >> l1 >> l2;
    for (int i = 1; i <= l1; i++)
    {
        in >> s1[i];
    }
    for (int i = 1; i <= l2; i++)
    {
        in >> s2[i];
    }
    for (int i = 1; i <= l1; i++)
    {
        u1 = s1[i] % 10;
        p1 = (s1[i] / 10) % 10;
        for (int j = 1; j <= l2; j++)
        {
            u2 = s2[j] % 10;
            p2 = (s2[j] / 10) % 10;
            out << s1[i] << ' ' << s2[j] << ' ' << (u1 == u2 && p1 == p2) || (u1 == p2 && p1 == u2);
            out << u1 << ' ' << u2 << ' ' << p1 << ' ' << p2 << ' ' << endl;
            if ((u1 == u2 && p1 == p2) || (u1 == p2 && p1 == u2))
            {
                perechi++;
            }
        }
    }
    out << perechi;
    return 0;
}

/*

112 321

u1 = 2
p2 = 1
u2 = 1
p2 = 2



*/