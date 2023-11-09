#include <iostream>

using namespace std;

int cifreImpare(int n){
    bool pare = false, impare = false;
    int p[10],i, u, a=0;
    for(i = 1;n > 0;n /= 10){
        u = n % 10;
        if(u % 2 == 0){
            pare = true;
            p[i] = u;
            i++;
            }
        else
            impare = true;
    }
    if(pare and impare)
        for(;i > 0 ;i--)
            a = a * 10 + p[i];
    else
        a = -1;
    return a;

}

int main()
{
    int n;
    cin >> n;
    cifreImpare(n);
    return 0;
}

/*
12345
p:4 2
  1 2 3 4 5
*/
