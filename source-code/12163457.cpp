//Language: GNU C++


#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<vector>
#include<cmath>
#include<iostream>
#include<string>
#define N 1000010
#define M 1010
#define P 1000000007
using namespace std;
int v[N],s[N],l[N],r[N],tt;
int L[N],R[N],typ[N],n,q,i,j,tmp,ans[N];
string str;
void build(int x,int a,int b)
{
    int m;
    l[x]=a;r[x]=b;
    if (x>tt) tt=x;
    if (b-a>1)
    {
        m=(a+b)>>1;
        build(2*x,a,m);
        build(2*x+1,m,b);   
    }
    v[x]=-1;
}
void clean(int x)
{
    if (v[x]!=-1)
    {
        s[x]=(r[x]-l[x])*v[x];
        if (2*x<=tt) v[2*x]=v[x];
        if (2*x+1<=tt) v[2*x+1]=v[x];
        v[x]=-1;
    }
}
void change(int x,int a,int b,int c)
{
    int m;
    clean(x);
    if ((a<=l[x])&&(r[x]<=b))
    {
        v[x]=c;
        return;
    }
    m=(l[x]+r[x])>>1;
    if (a<m) change(2*x,a,b,c);
    if (m<b) change(2*x+1,a,b,c);
    clean(2*x);clean(2*x+1);
    s[x]=s[2*x]+s[2*x+1];
}
int query(int x,int a,int b)
{
    int m,ans=0;
    clean(x);
    if ((a<=l[x])&&(r[x]<=b))
        return s[x];
    m=(l[x]+r[x])>>1;
    if (a<m) ans+=query(2*x,a,b);
    if (m<b) ans+=query(2*x+1,a,b);
    return ans;
}
int main()
{
    cin>>n>>q;
    cin>>str;
    build(1,0,n);
    for (i=1;i<=q;i++)
    cin>>L[i]>>R[i]>>typ[i];
    
    for (j=1;j<=26;j++)
    {
        change(1,0,n,0);
        for (i=0;i<n;i++)
        if (str[i]-96<=j)
        change(1,i,i+1,1);
        for (i=1;i<=q;i++)
        {
            tmp=query(1,L[i]-1,R[i]);
            change(1,L[i]-1,R[i],0);
            if (tmp)
            {
            if (typ[i]==0)
            change(1,R[i]-tmp,R[i],1);
            else
            change(1,L[i]-1,L[i]-1+tmp,1);
            }
        }
        
        for (i=1;i<=n;i++)
        if ((query(1,i-1,i)==1)&&(ans[i]==0))
        ans[i]=96+j;
    }
    
    for (i=1;i<=n;i++)
    {
        char ch=ans[i];
        cout<<ch;
    }
}