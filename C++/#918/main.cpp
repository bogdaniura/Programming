#include <iostream>

using namespace std;

int sumcif(int a, int& b){
    if(a>=10){
        b = b + sumcif(a % 10, b);
    }
    else
    {
        return a;
    }
    
    

}

int main(){
    int n, s = 0;
    cin >> n;
    sumcif(n, s);
    cout << s;

    return 0;
}