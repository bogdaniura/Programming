#include <iostream>

using namespace std;
int a[100], b[100], s[200], n, d, x = 1, y = 1, u;

bool diferite(){
    int t = 0;
    for(int i = 1;i <= n;i++)
        if(a[i] == 1)
            t++;
    return t != n;
}

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++){
        a[i] = 1;
        b[i] = 0;
    }
    do{
    for(int i = 1, j = 1;j <= 2*n;i += 2,j++){
        s[i] = a[j];
        s[i+1] = b[j];
    }
    for(int i = 1;i <= n*2;i++)
        cout << s[i] << ' ';
    for(int i = 1;i <= n;i++)
        a[i] = s[i];
    for(int i = n+1, j = 1;i <= n*2;i++, j++)
        b[j] = s[i];
        d++;
    cout << endl;
    }while(diferite());
    cout << d;
    return 0;
}
