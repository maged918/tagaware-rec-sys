//Language: GNU C++


using namespace std;
#include<iostream>
int main()
{
    int i,j,k,l,n,m;
    cin>>n>>m;
    if(m==1)
    {
        if(n==1)
            l = 1;
        else
            l=2;
    }
    else if(m==n)
        l = n-1;
    else
    {
        if(m>(n-m))
                l = m-1;
        else
            l = m+1;
    }
    cout<<l<<endl;
    return 0;
}



