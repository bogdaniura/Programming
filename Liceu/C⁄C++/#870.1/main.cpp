#include <iostream>
#include <stack>
using namespace std;

int n, x, as = 1, g = 0;
stack<int> a, b, c;
string act[2002];
bool posibil = true;

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> x;
        a.push(x);
    }
    do{
        if(a.top() == as){
            c.push(a.top());
            a.pop(); g++; act[g] = "A B"; as++;
        }
        else{
            if(not b.empty() and b.top() == as){
                c.push(b.top());
                b.pop(); g++; act[g] = "B C"; as++;
            }
            else{
                if(b.top() > a.top()){
                    b.push(a.top());
                    a.pop();
                    g++; act[g] = "A B";
                }
                else
                    posibil = false;
            }
        }
    }while(c.top() != n and posibil);

    if(not posibil)
        cout << 0;
    else{
        cout << g;
        for(int i = 1;i <= g;i++)
            cout << endl << act[i];
    }

    return 0;
}
