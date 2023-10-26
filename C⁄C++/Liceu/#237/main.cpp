#include <iostream>
#include <fstream>

using namespace std;

int n, vec[101], s;

ifstream fin("sume.in");
ofstream fout("sume.out");

int main(){

    fin >> n;
    for(int i = 1;i <= n;i++){
            fin >> vec[i];
            s = s + vec[i];
        }
    for(int i = n;i >= 1;i--){
        fout << s << endl;
        s = s - vec[i];
    }

    return 0;
}