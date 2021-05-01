#include <iostream>
#include <fstream>

using namespace std;

int n, m, k, a, grad[1001], pr[1001], j;;

ifstream fin("fb_fmi.in");
ofstream fout("fb_fmi.out");

int main(){
    fin >> n >> m >> k;
    for(int i = 1;i <= 2*m;i++){
        fin >> a;
        grad[a]++;
    }
    for(int i = 1;i <= n;i++){
        if(grad[i] >= k){
            pr[++j] = i;

        }
    }
    if(j >= 1){
        fout << j << endl;
        for(int i = 1;i <= j;i++)
            fout << pr[i] << ' ';
    }
    else{
        fout << 0;
    }
    
    return 0;
}