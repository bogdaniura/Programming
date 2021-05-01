#include <iostream>
#include <fstream>

int ne, vec[101], ies, elems;

using namespace std;

ifstream fin("vec.in");
ofstream fout("vec.out");

int verif_prim(int a){
    bool p = true;

    for(int i = 2; i*i <= a;i++){
        if(a % i == 0){
            p = false;
        }
    }

    return p;
}

int main(){
    fin >> ne;
    for(int i = 1;i <= ne;i++){
        fin >> vec[i];
    }
    for(int ies = 1; ies <= ne; ies++){
        if(not verif_prim(vec[ies])){
            for(int i = ies;i <= ne;i++){
                vec[i] = vec[i+1];
                
            }
        ies--;
        ne--;
        }
    }
    for(int i = 1;i <= ne;i++){
        fout << vec[i] << ' ';
    }
    fout << endl;

    return 0;
}