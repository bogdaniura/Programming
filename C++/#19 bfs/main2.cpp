#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int n, m, s, v1, v2, nc;
bool mat[101][101], d[101];
queue<int> a;

ifstream fin ("BFS.in");
ofstream fout ("BFS.out");

int main(){
    fin >> n >> m >> s;
    for(int i = 1; i<= m; i++){
        fin >> v1 >> v2;
        mat[v1][v2] = mat[v2][v1] = true;
    }
    a.push(s);
    d[s] = true;
    while(not a.empty()){
        nc = a.front();
        fout << nc << ' ';
        for(int i = 1;i <= n;i++){
            if(mat[nc][i] and not d[i]){
                d[i] = true;
                a.push(i);    
            }
        }
        a.pop();
    }



    return 0;
}