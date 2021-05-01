#include <iostream>

using namespace std;

int a, b;
long long S;

int main()
{
    S = 1;
    cin >> a >> b;
    if(b == 0)
        cout << 1;
    else{
    do{
        S = S * a;
        b--;
    }while(b >= 1);
    cout << S;}
    return 0;
}
