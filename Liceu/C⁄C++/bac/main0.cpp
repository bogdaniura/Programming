#include <iostream>

using namespace std;

int main()
{
    for(int i = 1;i <= 100000;i++){
        if(i/2/2 == 1){
            cout << i;
        }
    }

    return 0;
}