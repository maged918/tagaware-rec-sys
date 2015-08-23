//Language: GNU C++


#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
int  a[10006];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i =0 ;i < n ; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
       if(a[0]==1)
        cout<<-1<<endl;
       else
        cout<<1<<endl;
    }
}
