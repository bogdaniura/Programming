#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("subgraf1.in");
ofstream fout("subgraf1.out");
int n, v1, v2, grad[101], minim=101, muchii;
bool graf[101][101];

int main()
{
    fin >> n;
    while(fin >> v1 >> v2){
        if(graf[v1][v2] == 0 and graf[v2][v1] == 0){
        graf[v1][v2]=graf[v2][v1]=1;
        grad[v1]++;
        grad[v2]++;
        muchii++;}
    }
//    for(int i=1; i<=n; i++){ //verificare
//        fout << endl;
//        for(int j=1; j<=n; j++){
//            fout << graf[i][j] << ' ';
//        }
//    }
//    fout << endl << endl;
//    for(int i=1; i<=n; i++){
//        fout << i << ' ' << grad[i] << endl;
//    }   //verificare

    for(int i=1; i<=n; i++){
        if(grad[i]<minim){
            minim=grad[i];
        }
    }
//    fout << endl << minim << endl; //verificare//
    for(int i=1; i<=n; i++){
        if(grad[i]==minim){
            for(int j=1; j<=n; j++){
                if(graf[i][j]==1){
                    graf[i][j]=0;
                    graf[j][i]=0;
                    muchii--;
                }
            }
        }
    }
//    for(int i=1; i<=n; i++){ //verificare
//        fout << endl;
//        for(int j=1; j<=n; j++){
//            fout << graf[i][j] << ' ';
//        }
//    }
//    fout << endl << endl; //verificare
    fout<< muchii;
    return 0;
}
