#include <iostream>

using namespace std;

int n, a ,s[200001], v, ia = -1 ,y;

void push (int c) {
  v++; s[v] = c;
}

void pop () {
  v--;
}

int top () {
  return s[v];
}

bool empty () {
  return v == 0;
}

int main()
{
    cin >> n;
    v = n;
    for(int i = n;i >= 1;i--){
        cin >> y;
        s[i] = y;
    }
    for(int i = 1;i <= n;i++){
        ia = -1;
        cin >> a;
        for(int j = 1;j <= v;j++){
            if(s[j] == a)
                ia = j;
        }
        if(ia != -1){
            cout << v - ia + 1 << ' ';
            for(int k = v;k >= ia;k--)
                pop();
        }
        else
            cout << 0 << ' ';
    }
    return 0;
}



/*
5
2
4
1
3


4 5 1 3 2




*/
