#include <iostream>

using namespace std;

int powerrec(int a, int b){
    int P = 1;
    for(int i = 1; i <= b;i++)
        P = P * a;
    return P;
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << powerrec(a,b);

    return 0;
}
