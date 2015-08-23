//Language: MS C++


#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long node[1<<19];
bool tag[1<<19];
long long a[1<<19];
long long l[1<<19],r[1<<19];
void build_tree(int num,int l,int r)
{
    if (l==r-1)
    {
        node[num]=a[r]-a[l];
        return;
    }
    int mid=(l+r)/2;
    build_tree(num*2+1,l,mid);
    build_tree(num*2+2,mid,r);
    node[num]=node[num*2+1]+node[num*2+2];
}
void push_down(int num)
{
    if (tag[num])
    {
        tag[num]=false;
        tag[num*2+1]=true;
        tag[num*2+2]=true;
        node[num*2+1]=0;
        node[num*2+2]=0;
    }
}
inline void change(int num,int l,int r,int l0,int r0)
{
    if (l0>=r0) return;
    if ((l0<=l)&&(r<=r0))
    {
        node[num]=0;
        tag[num]=true;
        return;
    }
    push_down(num);
    int mid=(l+r)/2;
    if (l0<mid) change(num*2+1,l,mid,l0,r0);
    if (mid<r0) change(num*2+2,mid,r,l0,r0);
    node[num]=node[num*2+1]+node[num*2+2];
}
inline long long query(int num,int l,int r,int l0,int r0)
{
    if ((l0<=l)&&(r<=r0))
    {
        return node[num];
    }
    push_down(num);
    int mid=(l+r)/2;
    long long sum=0;
    if (l0<mid) sum+=query(num*2+1,l,mid,l0,r0);
    if (mid<r0) sum+=query(num*2+2,mid,r,l0,r0);
    return sum;
}
int ans[1<<19];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    int h,q;
    cin>>h>>q;
    int i;
    for (i=0;i<q;i++)
    {
        int x;
        cin>>x;
        cin>>l[i]>>r[i];
        r[i]++;
        l[i]<<=(h-x);
        r[i]<<=(h-x);
        a[i]=l[i];
        a[i+q]=r[i];
        cin>>ans[i];
    }
    a[q+q]=(1ll<<(h-1));
    a[q+q+1]=(1ll<<h);
    sort(a,a+q+q+2);
    int n=unique(a,a+q+q+2)-a;
    n--;
    build_tree(0,0,n);
    for (i=0;i<q;i++)
    {
        int ll=lower_bound(a,a+n,l[i])-a;
        int rr=lower_bound(a,a+n,r[i])-a;
        if (ans[i]==0)
        {
            change(0,0,n,ll,rr);
        }
        else
        {
            change(0,0,n,0,ll);
            change(0,0,n,rr,n);
        }
    }
    long long t=query(0,0,n,0,n);
    if (t>=2)
    {
        puts("Data not sufficient!");
        return 0;
    }
    if (t==0)
    {
        puts("Game cheated!");
        return 0;
    }
    for (i=0;i<n;i++)
    {
        if (query(0,0,n,i,i+1))
        {
            cout<<a[i]<<endl;
        }
    }
    return 0;
}
