#include <iostream>
#include <stack>

using namespace std;
int n, p = 1, k, g, x;
bool posibil = true;
string act[2002];
stack<int> a, b, c;

int main()
{
    cin >> n;
    for(int i = 1; i <= n;i++){
        cin >> x;
        a.push(x);
    }
    do{
        if(a.top() == p or b.top() == p){
            if(a.top() == p){
                //c.push(a.top());
                a.pop();
                p++;
                g++;
                act[g] = "A C";
            }
            if(b.top() == p){
                //c.push(b.top());
                b.pop();
                p++;
                g++;
                act[g] = "B C";
            }
        }
        else{
            if(a.top() > b.top())
                posibil = false;
            else{
                b.push(a.top());
                a.pop();
                g++;
                act[g] = "A B";
            }
        }
    }while(not a.empty() and not b.empty() and posibil);
    if(posibil){
        cout << g;
        for(int i = 1;i <= 5;i++){
            cout << endl;
            cout << act[i];
            }
    }
    else
        cout << 0;

    return 0;
}


/*
  g++;
  act[g] = "A B";
*/
