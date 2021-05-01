#include <iostream>

using namespace std;

int n, s;

int main()
{
    cin >> n;
    while(n != 0){
        s = s + n-1;
        n--;}
        cout << s;
    return 0;
}
