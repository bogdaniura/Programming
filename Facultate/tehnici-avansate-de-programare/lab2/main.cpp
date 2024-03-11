#include <iostream>

using namespace std;

int main() {
    float a, b, c, x;
    float *pa = &a, *pb = &b, *pc = &c, *px = &x;
    cin >> *pa >> *pb >> *pc;

    *px = (*pc - *pb) / *pa;
    cout << *px << endl;
}