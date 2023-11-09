#include <iostream>

using namespace std;

int a, b, k;

int divsum(int i){
    int sum = 0;
    for(int j = 1;j <= i;j++){
        if(i % j == 0){
            sum = sum + j;
        }
    }
    return sum;
}

bool pnumar(int i){
    int n = 0;
    if(divsum(i)%2 == i %2){
        return true;
    }
    else{
        return false;
    }

}

int kpn(int a, int b, int k){
    int i, c = 0;
    for(i = a;i <= b and c < k;i++){
        if(pnumar(i)){
            c++;
        }
    }
    if(c == k){
        return i-1;
    }
    else{
        return -1;
    }
}

int main()
{
    cin >> a >> b >> k;
    cout << kpn(a, b, k) << "\n";
    // cout << pnumar(35);
    return 0;
}