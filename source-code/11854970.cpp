//Language: GNU C++


#include<iostream>
#include<cstdio>
using namespace std;
int main()
{

    int n,mn1,mn2,mn3,mx1,mx2,mx3,f,s,t;
    cin>>n;
    cin>>mn1>>mx1;
    f=mn1;
    n-=mn1;
    cin>>mn2>>mx2;
    s=mn2;
        n-=mn2;

    cin>>mn3>>mx3;
    t=mn3;
        n-=mn3;
    if(n)
    {
        if(n<=mx1-mn1)
        {
            f+=n;
            n=0;
        }
        else{
            f=f+(mx1-mn1);
            n=n-(mx1-mn1);
        }
    }
    if(n)
    {
        if(n<=mx2-mn2)
        {
            s+=n;
            n=0;
        }
        else{
            s=s+(mx2-mn2);
            n=n-(mx2-mn2);
        }
    }
    if(n)
    {
        if(n<=mx3-mn3)
        {
            t+=n;
            n=0;
        }
        else{
            t=t+(mx3-mn3);
            n=n-(mx3-mn3);
        }
    }
    printf("%d %d %d\n",f,s,t);
    return 0;


}
