#include <fstream>
#include <algorithm>

using namespace std;

int n, a[10], b[10];

ifstream fin("sirpie.in");
ofstream fout("sirpie.out");

int cmmdc(int d, int i){
    int r;
    do{
        r = d % i;
        d = i;
        i = r;

    }while(i > 0);
    return d;
}

bool ok(int k){
    // fout << "ok" << endl;
    for(int i = 1;i <= k-1;i++){
        if(b[i] == b[k]){
            return false;    
        }
    }
    return true;
}

bool ok2(int k){
    // fout << "ok2" << endl;
    return k == n;
}

void afis(){
    for(int i = 1;i <= n;i++){
        fout << b[i] << ' ';
    }
    fout << endl;
}

bool sol(){
    // fout << sol << endl;
    for(int i = 1;i <= n-1;i++){
        // fout << cmmdc(a[i], a[i+1]);
        if(cmmdc(b[i], b[i+1]) != 1){
            return false;
        }
    }
    // fout << endl;
    return true;

}

void bt(int k){
    for(int i = 1;i <= n;i++){
        b[k] = a[i];
        if(ok(k)){
            if(ok2(k) and sol()){
                afis();

            }
            else{
                bt(k+1);
            }
        }
    }
}

int main(){
    fin >> n;
    for(int i = 1;i <= n;i++){
        fin >> a[i];
    }
    sort(a, a+n+1);
    bt(1);
}