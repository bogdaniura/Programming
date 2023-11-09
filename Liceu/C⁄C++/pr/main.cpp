#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int n, pc, uc, k, c1[11], c2[11], c3[11], v1, v2, v3, a[11][6], nrm;

void c1push(int x){
    v1++;
    c1[v1] = x;
}

void c2push(int x){
    v2++;
    c2[v2] = x;
}

void c3push(int x){
    v3++;
    c3[v3] = x;
}

char c1top() {
    return c1[v1];
}

char c2top() {
    return c2[v2];
}

char c3top() {
    return c3[v3];
}

void c1pop() {
  c1[v1] = 0;
  v1--;
}

void c2pop() {
  c2[v2] = 0;
  v2--;
}

void c3pop() {
  c3[v3] = 0;
  v3--;
}

void turnuri(){
    for(int i = 1, j = n;i <= n;i++, j--)
        a[j][1] = c1[i];
    for(int i = 1, j = n;i <= n;i++, j--)
        a[j][2] = c2[i];
    for(int i = 1, j = n;i <= n;i++, j--)
        a[j][3] = c3[i];
    for(int i = 1;i <= n;i++){
        cout << endl;
        for(int j = 1;j <= 3;j++){
            if(a[i][j] == 0 and i != n)
                cout << "  ";
            else
                cout << a[i][j] << '*';
        }
    }
}

void c1af(){
    if(v1 != 0)
        for(int i = 1;i <= v1;i++)
            cout << c1[i];
    else
        cout << 0;
}

void c2af(){
    if(v2 != 0)
        for(int i = 1;i <= v2;i++)
            cout << c2[i];
    else
        cout << 0;
}

void c3af(){
    if(v3 != 0)
        for(int i = 1;i <= v3;i++)
            cout << c3[i];
    else
        cout << 0;

}

void afis(){
    c1af();
    cout << endl;
    c2af();
    cout << endl;
    c3af();
    cout << endl;
}

int main()
{
    cin >> n;
    for(int i = n;i >= 1;i--)
        c1push(i);
    while(v3 != n){
        //afis();
        turnuri();
        cout << endl;
        cin >> k;
        system("cls");
        pc = k / 10;
        uc = k % 10;
        if(pc == 1 and uc == 2){
            if(c1top() < c2top() or v2 == 0){
                c2push(c1top());
                c1pop();
            }
            else
                cout << endl << "Ne se poate" << endl;
        }
        if(pc == 1 and uc == 3){
            if(c1top() < c3top() or v3 == 0){
                c3push(c1top());
                c1pop();
            }
            else
                cout << endl << "Ne se poate" << endl;
        }
        if(pc == 2 and uc == 1){
            if(c2top() < c1top() or v1 == 0){
                c1push(c2top());
                c2pop();
            }
            else
                cout << endl << "Ne se poate" << endl;
        }
        if(pc == 2 and uc == 3){
            if(c2top() < c3top() or v3 == 0){
                c3push(c2top());
                c2pop();
            }
            else
                cout << endl << "Ne se poate" << endl;
        }
        if(pc == 3 and uc == 1){
            if(c3top() < c1top() or v1 == 0){
                c1push(c3top());
                c3pop();
            }
            else
                cout << endl << "Ne se poate" << endl;
        }
        if(pc == 3 and uc == 2){
            if(c3top() < c2top() or v2 == 0){
                c2push(c3top());
                c3pop();
            }
            else
                cout << endl << "Ne se poate" << endl;
        }
    nrm++;
    }

    turnuri();
    cout << endl << "Ai terminat jocul, felicitari!" << endl << "Numar de mutari: " << nrm;

    return 0;
}
