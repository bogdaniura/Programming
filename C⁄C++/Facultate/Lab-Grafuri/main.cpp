#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("date.in");

int main(){

    int v1,v2,mat_ad[100][100], lungime, lista_succ[100][100];
    while(fin >> v1){
        fin >> v2;
        mat_ad[v1][v2] = true;
        if(v1 > lungime){
            lungime = v1;
        }
        if(v2 > lungime){
            lungime = v2;
        }
    }
    
    for(int i = 1;i <= lungime;i++){
        int indice = 0;
        for(int j = 1;j <= lungime;j++){
            if(mat_ad[i][j]){
                lista_succ[i][indice++] = j;
            }
        }
    }
    for(int i = 1;i <= lungime;i++){
        cout << endl;
        for(int j = 1;j <= lungime;j++){
            cout << mat_ad[i][j] << ' ';
        }
    }
    for(int i = 1;i <= lungime;i++){
        cout << endl << i << ": ";
        for(int j = 0;j < lungime && lista_succ[i][j];j++){
            cout << lista_succ[i][j] << ' ';
        }
    }




    return 0;
}