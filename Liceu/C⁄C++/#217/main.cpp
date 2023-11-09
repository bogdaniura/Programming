#include <iostream>

using namespace std;

int n, mat[25][25];

int main(){

    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i % 2 == 1){
                mat[i][j] = i;
            }
            else{
                mat[i][j] = j;
            }
            
        }    
    }

    for(int i = 1;i <= n;i++){
        if(i != 1)
            cout << endl;
        for(int j = 1;j <= n;j++){
            cout << mat[i][j] << ' ';
            
        }    
    }
    



    return 0;
}