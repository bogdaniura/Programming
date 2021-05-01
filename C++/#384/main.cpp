#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("saritura_calului1.in");
ofstream fout("saritura_calului1.out");

  int dl[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
  int dc[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
  int th[101][101];
  int nl, nc, l, c;
  int posibilitati(int l,int c){
    int posibilitati = 0, ln2, cn2;
    for(int j = 1;j <= 8;j++){
            ln2 = l + dl[j];
            cn2 = c + dc[j];
            if((ln2 >= 1 and ln2 <= nl and cn2 >= 1 and cn2 <= nc) and th[ln2][cn2] == 0)
                posibilitati++;}
    return posibilitati;
  }
  int main () {
    int ln, cn, lmin, cmin, mutare = 1, minim = 7, p;
    fin >> nl >> nc >> l >> c;
    for(int i = 1;i <= nl;i++)
        for(int j = 1;j <= nc;j++)
            th[i][j] = 0;
    do{
        th[l][c] = mutare;
        minim = 7;
        for(int i = 1;i <= 8;i++){
            ln = l + dl[i];
            cn = c + dc[i];
            if((ln >= 1 and ln <= nl and cn >= 1 and cn <= nc) and th[ln][cn] == 0){
            p = posibilitati(ln, cn);
            if(p >= 1)
                if(p <= minim){
                    minim = p;
                    lmin = ln;
                    cmin = cn;
                    }
                }
            }
    //if(p > 0){
        l = lmin;
        c = cmin;
        mutare++;//}
    }while(p >= 1);
    //mutare++;
    for(int i = 1;i <= nl;i++){
        if(i > 1)
        fout << endl;
        for(int j = 1;j <= nc;j++){
            if(th[i][j] == 0)
                th[i][j] = mutare;
            fout << th[i][j] << ' ';
            }
        }
    return 0;
  }
