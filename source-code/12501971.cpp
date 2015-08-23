//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int b[n+1];
    for(int i=1;i<=n;i++)
        b[i]=0;
    for(int i=0;i<m;i++)
    {
        int maxval=-1;
        int maxindex=0;
        for(int j=1;j<=n;j++)
        {
            int a;
            scanf("%d",&a);
            if(a>maxval)
            {
                maxval=a;
                maxindex=j;
            }
        }
       // cout<<maxindex<<endl;
        b[maxindex]++;
    }
    int maxval=-1,maxindex=-1;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>maxval)
        {
            maxval=b[i];
            maxindex=i;
        }
    }
    printf("%d\n",maxindex);
    return 0;
}
