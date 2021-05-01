#include <iostream>

using namespace std;

int n, x, y;

bool prim(int nr)
{
    for(int i = 2;i*i <= nr;i++){
        if(nr % i == 0){
            return false;
        }
    }
    return true;
}

void prime(int n, int& x, int& y)
{
    for (int i = n - 1; i >= 1 and (y == 0 or x == 0); i--)
    {
        if (prim(i))
        {
            if (y == 0)
            {
                y = i;
            }
            else
            {
                x = i;
            }
        }
    }
}

int main()
{
    cin >> n;
    prime(n, x, y);
    cout << x << ' ' << y;
    return 0;
}