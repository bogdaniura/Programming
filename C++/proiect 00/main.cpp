#include <iostream>

using namespace std;

int x[10] ,n;

void Afis()
{
    for( int j=1;j<=n;j++)
        cout<<x[j]<<" ";
    cout<<endl;
}

bool OK(int k){
    for(int i=1;i<k;i++)
        if(x[k]==x[i])
            return false;
    return true;
}

bool Solutie(int k)
{
    return k == n;
}

void back(int k){
    for(int i=1 ; i<=n ; ++i)
    {
        x[k]=i;
        if( OK(k) )
            if(Solutie(k))
                Afis();
            else
                back(k+1);
    }
}
int main(){
    cin>>n;
    back(1);
    return 0;
}