#include <iostream>

using namespace std;

int fact(int n){
    int fn = 1;
for(int i = 1;i <= n;i++)
    fn = fn * i;
    return fn;
}

int main()
{
    cout << fact(241);
    return 0;
}
