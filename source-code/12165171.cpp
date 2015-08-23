//Language: MS C++


#include<iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a;
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a==1)
        {
            flag=true;
        }
    }
    if(flag)
        cout<<-1<<endl;
    else
        cout<<1<<endl;
    return 0;
}