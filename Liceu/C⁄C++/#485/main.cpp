#include <iostream>

using namespace std;

int n, like[101][101], l[101], imaxim;

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i != j){
                cin >> like[i][j];
            }
        }    
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            l[i] = l[i] + like[j][i];
        }    
    }
    for(int i = 1;i <= n;i++){
        if(l[i] > l[imaxim]){
            imaxim = i;
        }
    }
    cout << imaxim;

    return 0;
}
