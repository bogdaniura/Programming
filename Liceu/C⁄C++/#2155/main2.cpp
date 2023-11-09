#include <iostream>
#include <fstream>

using namespace std;

int n, m, k, a, grad[1001], pr[1001], j, graf[1001][1001], n1, n2;

ifstream fin("fb_fmi.in");
ofstream fout("fb_fmi.out");

int main(){
    fin >> n >> m >> k;
    for(int i = 1;i <= 2*m;i++){
        fin >> n1 >> n2;
        if(graf[n1][n2] != 1){
            graf[n1][n2] = graf[n2][n1] = 1;

        }
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++)
            if(graf[i][j] == 1){
                grad[i]++;
            }
    }
    
    for(int i = 1;i <= n;i++){
        fout << i << ' ' << grad[i] << endl;
    }
    
    return 0;
}

/*
for(int i = 1;i <= n;i++){
        if(grad[i] >= k){
            pr[++j] = i;

        }
    }
*/

/*
for(int i = 1;i <= n;i++){
        fout << endl;
        for(int j = 1;j <= n;j++)
            fout << graf[i][j] << ' ';
    }
*/

/*
if(j >= 1){
        fout << j << endl;
        for(int i = 1;i <= j;i++)
            fout << pr[i] << ' ';
    }
    else{
        fout << 0;
    }
*/