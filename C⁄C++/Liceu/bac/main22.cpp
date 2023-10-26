#include <iostream>

using namespace std;

int n, a[101];

void sortare()
{
    int aux;
    bool s;
    do
    {
        for (int i = 1; i <= n-1; i++)
        {
            s = false;
            if(a[i] > a[i+1]){
                aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
                s = true;
            }
        }
    }while(s);
}

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sortare();
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }

    return 0;
}