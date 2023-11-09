#include <iostream>
#include <fstream>

using namespace std;

int n, mat[24][24];

ifstream fin("chenar.in");
ofstream fout("chenar.out");

int main(){

    fin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            fin >> mat[i][j];
        }    
    }
    for(int i = 1;i <= n - 1;i++){
        fout << mat[1][i] << ' ';
    }
    for(int i = 1;i <= n - 1;i++){
        fout << mat[i][n] << ' ';
    }
    for(int i = n;i >= 2;i--){
        fout << mat[n][i] << ' ';
    }
    for(int i = n;i >= 2;i--){
        fout << mat[i][1] << ' ';
    }



    return 0;
}