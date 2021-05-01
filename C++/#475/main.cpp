#include <fstream>

using namespace std;

ifstream fin("lant.in");
ofstream fout("lant.out");

int n, m, s, d, v1, v2, nnl, sl[101];
bool mat[101][101], v[101];

void lant(int nc){
    v[nc] = true;
    nnl++;
    sl[nnl] = nc;
    if(sl[nnl] == d){
        for(int i = 1;i <= nnl;i++)
            fout << sl[i] << ' ';
        fout << endl;
    }
    for(int c = 1;c <= n;c++){
        if(mat[nc][c] and not v[c]){
            lant(c);
        }
    }            
    v[nc] = false;
    nnl--;
        

}

int main(){
    fin >> n >> m;
    for(int i = 1;i <= m;i++){
        fin >> v1 >> v2;
        mat[v1][v2] = mat [v2][v1] = true;
    }
    fin >> s >> d;
    lant(s);

    return 0;
}