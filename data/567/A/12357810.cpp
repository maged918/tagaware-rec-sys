//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long int a[1000000];
int main()
{

    long long int i,n;
    scanf("%I64d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
    }


    for(i=0;i<n;i++)
    {
        long long int mn,mx;
        if(i!=0&&i!=n-1)
        {
                mn=min(a[i]-a[i-1],a[i+1]-a[i]);
                mx=max(a[i]-a[0],a[n-1]-a[i]);
        }
        else if(i==0)
        {
            mn=a[i+1]-a[i];
            mx=a[n-1]-a[i];
        }

        else if(i==n-1)
        {
            mn=a[i]-a[i-1];
            mx=a[i]-a[0];
        }

         printf("%I64d %I64d\n",mn,mx);
    }
    return 0;
}
