#include <iostream>
#include <fstream>

using namespace std;

ifstream in("f.in");

int main()
{
    int n, a, p = 0;
    in >> n;
    while(in >> a){
        if(a < n){
            p++;
        }
    }
    cout << p+1;

    return 0;
}