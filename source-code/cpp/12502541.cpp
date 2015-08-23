//Language: GNU C++


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
if(n==1&&m==1)
{

 cout<<"1"<<endl;
return 0;
}    if(abs(m-1)>abs(n-m)&&m>1)
        cout<<m-1<<endl;
    else if(abs(m-1)==abs(n-m)&&m>1)
        cout<<m-1<<endl;
    else
        cout<<m+1<<endl;






    return 0;
}
