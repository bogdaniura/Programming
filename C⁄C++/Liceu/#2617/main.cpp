#include <iostream>

using namespace std;

int N, M, T1, T2;

int main()
{
    cin >> N >> M;
    T1 = N - 1;
    T2 = N * (M - 1);
    cout << T1 + T2;
    return 0;
}
