#include <iostream>

using namespace std;

int n, l, c, a[25][25], s, d;

int main()
{
    cin >> n;
    for(l = 1;l<= n;l++)
        for(c = 1;c<= n;c++)
            a[l][c] = 3;
    s = 1;d = n;
    for(l = s;l<= n;l++){
        a[l][s] = a[l][d] = 0;
        s++;d--;}
    s = 2;d = n - 1;
    for(l = 1;l <= n/2;l++){
        for(c = s;c <= d;c++)
            a[l][c] = 1;
            s++;d--;}
    s = 2;d = n - 1;
    for(l = n;l >= n / 2;l--){
        for(c = s;c <= d;c++)
            a[l][c] = 2;
            s++;d--;}
    for(l = 1;l<= n;l++){
        for(c = 1;c<= n;c++)
            cout << a[l][c] << ' ';
            cout << endl;
    }
    return 0;
}
