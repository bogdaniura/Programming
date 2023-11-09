#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("izolate.in");
ofstream fout("izolate.out");

int n, v1, v2, nni, a[101];
bool grad[101];

int main()
{
    fin >> n;
    while(fin >> v1 >> v2){
        grad[v1]=true;
        grad[v2]=true;
    }
    for(int i = 1;i<=n;i++){
        if(grad[i] == 0){
            nni++;
        }
    }
    fout << nni;
    for(int i = 1;i<=n;i++){
        if(grad[i] == 0)
            fout << ' ' << i;
    }
    return 0;
}
