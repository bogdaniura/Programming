#include <fstream>

using namespace std;

ifstream fin ("adiacenta.in");
ofstream fout ("adiacenta.out");

int a, b, graf[101][101], v, m;


int main(){
    fin >> v >> m;
    for(int i = 1;i <= m;i++){
            fin >> a >> b;
            graf[a][b] = graf[b][a] = 1;
    }

    for(int i = 1;i <= v;i++){
        for(int j = 1; j <= v;j++){
            fout << graf[i][j] << ' ';
        }
        fout << endl;
    }
    return 0;
}
