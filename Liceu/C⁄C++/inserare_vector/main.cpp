#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("vector.in");
ofstream fout("vector.out");

int n1, n2, p = 3;
vector<int> v1, v2;

int main()
{
    int a;
    fin >> n1;
    for (int i = 1; i <= n1; i++)
    {
        fin >> a;
        v1.push_back(a);
    }
    fin >> n2;
    for (int i = 1; i <= n2; i++)
    {
        fin >> a;
        v2.push_back(a);
    }
    v1.insert(v1.begin() + p, v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); i++)
    {
        fout << v1[i];
    }
    return 0;
}