#include <iostream>

using namespace std;

int main()
{
    int miniml[101], maximl[101], minimc[101], maximc[101];
    int l ,c, sa = 0;
    int nl, nc, k[101][101];
    cin >> nl >> nc;
    for(int l = 1;l <= nl;l++)
        for(int c = 1;c <= nc;c++)
            cin >> k[l][c];
    for(l = 1;l <= nl;l++){
        miniml[l]=10;
        maximl[l]=0;
        for(c = 1;c <= nc;c++){
            minimc[c]=10;
            maximc[c]=0;
            if(k[l][c] < miniml[l])
                miniml[l] = k[l][c];
            else
                if(k[l][c] > maximl[l])
                maximl[l] = k[l][c];
            if(k[l][c] < minimc[c])
                minimc[c] = k[l][c];
            else
                if(k[l][c] > maximc[c])
                maximc[c] = k[l][c];
            }
        }
    for(l = 1;l <= nl;l++)
        for(c = 1;c <= nc;c++)
            if((k[l][c] == maximc[c] and k[l][c] == miniml[l]) or (k[l][c] == minimc[c] and k[l][c] == maximl[l]))
                sa++;
    cout << sa;
    return 0;
}
/*
 3 2
  c 1 2 3
l
1   4 5 6
2   9 3 7
sa =/0/1
miniml1 = 4
maximl1 = 6
miniml2 = 3
maximl2 = 9
minimc1 = 4
maximc1 = 9
minimc2 = 3
maximc2 = 5
minimc3 = 6
maximc3 = 7*/
