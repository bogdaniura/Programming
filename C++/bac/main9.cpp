#include <iostream>
#include <cstring>
using namespace std;

char s[21],t[21];
int i,j;
int main()
{
    strcpy(s,"ABCDUECDA");
    i=0,j=strlen(s)-1;
    while(i<j)
    if(s[i]==s[j]){
        strcpy(t,s+j+1);
        strcpy(s+j,t);
        strcpy(t,s+i+1);
        strcpy(s+i,t);
        j=j-2;
    }
    else{
        i++;
        j--;
    }
    cout<<s;
    return 0;
}

