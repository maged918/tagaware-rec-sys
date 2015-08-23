//Language: GNU C++


#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int flag;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        {
           flag=1;
            break;
        }
        if(a[i]>0)
            flag=0;
    }
    if(flag==1){
        cout<<-1<<endl;}
    if(flag==0)
        cout<<1<<endl;
    return 0;
}
