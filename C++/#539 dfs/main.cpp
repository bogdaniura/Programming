#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

int n, m, s, v1, v2;
bool mat[101][101], visit[101];

void dfs(int nc){
    visit[nc] = true;
    for(int c = 1;c <= n;c++){
        if(mat[nc][c] and not visit[c]){
            fout  << ' ' << c;
            dfs(c);
        }
    }

}

int main(){
    fin >> n >> m >> s;

    for(int i = 1;i <= m;i++){
        fin >> v1 >> v2;
        mat[v1][v2] = mat [v2][v1] = true;
    }
    fout << s;
    dfs(s);
    
    
    return 0;
}