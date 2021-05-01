#include <iostream>
#include <fstream>

using namespace std;

int a[10], n, S;

ofstream fout("numere.out");

bool sol(int k){
    return a[1] != 0 and k == n;
}

bool ok(int k){   
    int s = 0, p = 1;
    for(int i = 1; i <= n;i++){
        s = s + a[i];
    }
    for(int i = 1; i <= n;i++){
        p = p + a[i];
    }
    return s == p;
}

void bt(int k){
    for(a[k] = 0; a[k] <= 9;a[k]++){
        if(ok(k)){
            if(sol(k)){
                S++;
            }
            else{
                bt(k+1);
            }
        }
    }
}

int main(){
    cin >> n;
    bt(1);
    fout << S;
}
