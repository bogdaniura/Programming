#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, vec[1001], vec2[1001], m, a;

ifstream fin("paresort.in");
ofstream fout("paresort.out");

int main(){

    fin >> n;
    for(int i = 1;i <= n;i++){
        fin >> a;
        if(a % 2 == 0){
            m++;
            vec2[m] = a;
        }
    }
    sort(vec2, vec2 + m + 1);
    if(m > 0){
        fout << m << endl;
        for(int i = 1;i <= m;i++){
            fout << vec2[i] << ' ';
        }
    }
    else
        fout << "nu exista";
    fout << "hello there";

    return 0;
}