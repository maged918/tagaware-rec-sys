//Language: GNU C++


#include<iostream>
#define ll long long
using namespace std;
int main()
{
    ll a,b;
    cin>>a>>b;
    if(a==1 && b==1)
    {
        cout<<1<<endl;
        return 0;
    }
    if(b<=a/2)
        cout<<b+1<<endl;
    else
        cout<<b-1<<endl;
        return 0;
}

