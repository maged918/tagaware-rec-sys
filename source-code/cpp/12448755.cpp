//Language: MS C++


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define N 100010
int n;
int A[N];
bool flag[N],B[N];
queue<int> Q;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        A[i]=read();
        flag[A[i]]=true;
    }
    for(int i=1;i<=n;i++)
    {
        if(!flag[i])
            Q.push(i);
    }
    memset(flag,0,sizeof(flag));
    for(int i=1;i<=n;i++)
    {
        if(!flag[A[i]]&&A[i]<=n)
        {
            flag[A[i]]=true;
        }
        else
        {
            int now=Q.front();Q.pop();
            A[i]=now;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
