#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int nl, nc, lac[1001][1001], nri, nrp;
int dl[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

struct coordonate{
    int l, c;
};

void completare(int l, int c){
    queue <coordonate> q;
    int ln, cn;
    coordonate p;
    lac[l][c] == 2;
    q.push({l, c});
    while(not q.empty()){
        p = q.front(); q.pop();
        for(int i = 0;i <= 3;i++){
            ln = p.l + dl[i];
            cn = p.c + dc[i];
            if(lac[ln][cn] == 1){
                q.push({ln, cn});
                lac[ln][cn] = 2;
            }
        }

    }
}

int main(){
ifstream fin("lac.in");
ofstream fout("lac.out");

    fin >> nl >> nc;
    for(int i = 1;i <= nl;i++)
        for(int j = 1; j <= nc;j++)
            fin >> lac[i][j];

    for(int j = 1;j <= nc;j++){
        if(lac[1][j] == 1){
            nrp++; completare(1 ,j);
            }
        if(lac[nl][j] == 1){
            nrp++; completare(nl, j);
            }
    }

    for(int i = 1;i <= nc;i++){
        if(lac[i][1] == 1){
            nrp++; completare(i, 1);
            }
        if(lac[i][nc] == 1){
            nrp++; completare(i, nc);
            }
    }
    for(int i = 2;i <= nl-1; i++){
        for(int j = 2; j <= nc-1;j++)
            if(lac[i][j] == 1){
                nri++; completare(i, j);}
    }
    fout << nri << ' ' << nrp;

    return 0;
}
