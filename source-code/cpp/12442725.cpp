//Language: GNU C++


#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,i,j;
    static int a[1000000],b[1000000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {   scanf("%d",&a[i]);
        b[a[i]]++;
    }
    j=1;
    for(i=0;i<n;i++)
    {
        if(b[a[i]]>0 && a[i]<=n)
        {
            cout<<a[i]<<" ";
            b[a[i]]=-1;
        }
        else
        {
            for(j=j;j<=n;j++)
            {
                if(b[j]==0)
                {   cout<<j<<" ";
                    b[j]=-1;
                    break;
                }
            }
        }
    }
    return 0;
}