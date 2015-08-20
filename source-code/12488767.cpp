//Language: GNU C++11


#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int a[100005],b[100005],c[100005];

int main()
{
    int n,j,i;
    while(cin>>n)
    {
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            //if(a[i]<=n)
                b[a[i]]++;
        }
        for(i=0;i<n;i++)
        {
            if(b[a[i]]!=1&&b[a[i]]!=0)
            {
                b[a[i]]--;
                a[i]=0;
            }
            if(a[i]>n)
                a[i]=0;
        }
        j=0;
        for(i=1;i<=n;i++)
        {
            if(b[i]==0)
            {
                c[j]=i;
                j++;
            }
        }
        j=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                a[i]=c[j];
                j++;
            }
        }
        for(i=0;i<n;i++)
        {
            cout<<a[i];
            if(i!=n-1)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
