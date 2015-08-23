//Language: GNU C++11


#include<iostream>
using namespace std;
int main ()
{
    int t,s=0,q,i,p;
    cin>>t>>s>>q;
    p=s;
    i=0;
    while(s<t)
    {i++;
    if(i!=1)
    {
    p=s;
    }
        while(s<t && p>=1)
        {
            s=s+q-1;
            p=p-1;
        }
    }
    cout<<i<<endl;
    return 0;
}