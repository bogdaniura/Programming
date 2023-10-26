#include <fstream>

using namespace std;

ifstream fin ("adiacenta1.in");
ofstream fout ("adiacenta1.out");

int graf[101][101], v1, v2, vecini[101], n, cmmn=0;


int main()
{
    while(fin >> v1 >> v2){
        graf[v1][v2] = graf[v2][v1] = 1;
        if(cmmn < v1){
            cmmn = v1;
        }
        if(cmmn < v2){
            cmmn = v2;
        }
    }
    for(int i = 1;i <= cmmn;i++){
        for(int j = 1;j<=cmmn;j++){
            fout << graf[i][j] << ' ';

        }
        fout << endl;
    }


    return 0;
}

