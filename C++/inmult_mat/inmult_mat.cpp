#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("inmult_mat.in");
ofstream fout("inmult_mat.out");

int l1, c1, l2, c2, mat1[101][101], mat2[101][101], mat3[101][101];

void cit_mat(){
    fin >> l1 >> c1;
    for(int i = 1;i <= l1;i++){
        for(int j = 1;j <= c1;j++){
            fin >> mat1[i][j];
        }    
    }
    fin >> l2 >> c2;
    for(int i = 1;i <= l2;i++){
        for(int j = 1;j <= c2;j++){
            fin >> mat2[i][j];
        }    
    }
}

void inmult_mat(){

    if(c1 == l2){
        for(int i = 1;i <= l1;i++){
            for(int j = 1;j <= c2;j++){
                for(int a = 1;a <= c1;a++){
                    mat3[i][j] = mat3[i][j] + mat1[i][a] * mat2[a][j];

                }
            }
        }

    }

}

void afis_mat(){

    for(int i = 1;i <= l1;i++){
        fout << endl;
        for(int j = 1;j <= c2;j++){
            fout << mat3[i][j] << ' ';
        }    
    }

}

int main(){
    cit_mat();
    inmult_mat();
    afis_mat();
}