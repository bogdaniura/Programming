#include <iostream>

using namespace std;

int n, c, s, a;

int main()
{
    cin >> n;
    do{
        c = n % 10;
        s = s * 10 + c;
        n = n / 10;
    }while(n > 0);
        a = 1;
    for(int i = 1;i <= s/2;i++){
        if(s % i == 0)
            a++;}
            cout << a;
    return 0;
}
