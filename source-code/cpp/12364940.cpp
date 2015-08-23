//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#define INF 0x7fffffff
using namespace std;
int main()
{
    int n,d[105],b[105];
    d[0]=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a;
        int sign=0;
        getchar();
        scanf("%c %d",&a,&b[i]);
        if(a=='+')
            d[i]=d[i-1]+1;
        if(a=='-')
        {
            for(int j=1;j<i;j++)
            {
                if(b[j]==b[i])
                {sign=1;
                break;}
            }
            if(sign==0)
            {
                for(int j=0;j<i;j++)
                    d[j]++;
            }
            d[i]=d[i-1]-1;
        }
    }
    int maxs=0;
    for(int i=0;i<=n;i++)
    {
        maxs=max(maxs,d[i]);
    }
    cout<<maxs<<endl;
}
