#include <iostream>
#include <fstream>

int n;

using namespace std;

ifstream fin ("apnp.in");
ofstream fout ("apnp.out");

int prim(int a){
    bool p = true;

    for(int i = 2; i*i <= a;i++){
        if(a % i == 0){
            p = false;
        }
    }

    return p;
}

int main(){

    fin >> n;
    for(int i = 1; i <= n;i++){
        if(prim(i)){
            fout << i << ' ';
        }
    }
    
    return 0;
}