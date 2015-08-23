//Language: GNU C++11


#include <iostream>

using namespace std;



int main()
{
    int n, m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<1<<endl; return 0;
    }

    if(n%2) //odd
    {
        if(m < n/2+1)
            cout<<m+1<<endl;
        else
            cout<<m-1<<endl;
    }
    else
    {
        if(m<=n/2)
            cout<<m+1<<endl;
        else
            cout<<m-1<<endl;
    }
    return 0 ;
}
