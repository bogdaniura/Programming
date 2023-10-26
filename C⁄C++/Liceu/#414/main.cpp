#include <fstream>

using namespace std;

ifstream fin ("listavecini.in");
ofstream fout ("listavecini.out");

int graf[101][101], v1, v2, vecini[101], n;


int main()
{
    fin >> n;
    while(fin >> v1 >> v2){
        if(graf[v1][v2] == 0 and graf[v2][v1] == 0){
        vecini[v1]++;
        vecini[v2]++;
        }
        graf[v1][v2] = graf[v2][v1] = 1;

    }
    for(int i = 1;i <= n;i++){
        fout << vecini[i];
        for(int j = 1;j<=n;j++){
            if(graf[i][j] == 1){
                fout << ' ' << j;
            }

        }
        fout << endl;
    }


    return 0;
}
