#include <iostream>

using namespace std;

int main()
{
  int n = 0;
  int arr[5]={1, 2, 3, 4, 5};
  for(int i = 0;i < 5;i++){
    n = n + arr[i];
  }
  cout << n;
  return 0;
}