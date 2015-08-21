//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
char q[3];
int a;
char tmp[300010];
struct st
{
    int s,e,zu,num;
};
st tree[300010<<2];
void build(int st,int ed,int k)
{
    tree[k].s=st;
    tree[k].e=ed;
    if(st==ed)
    {
        if(tmp[st-1]=='.')
        {
            tree[k].num=1;
            tree[k].zu=1;
        }
        else
        {
            tree[k].num=0;
            tree[k].zu=0;
        }
        return;
    }
    int mid=(st+ed)>>1;
    build(st,mid,k<<1);
    build(mid+1,ed,k<<1|1);
    tree[k].zu=tree[k<<1].zu+tree[k<<1|1].zu;
    tree[k].num=tree[k<<1].num+tree[k<<1|1].num;
    if(tmp[tree[k<<1|1].s-1]=='.'&&tmp[tree[k<<1].e-1]=='.')
        tree[k].zu--;
}
void update(int k)
{
    int st=tree[k].s;
    if(tree[k].s==tree[k].e)
    {
        if(tmp[st-1]=='.')
        {
            tree[k].num=1;
            tree[k].zu=1;
        }
        else
        {
            tree[k].num=0;
            tree[k].zu=0;
        }
        return;
    }
    int mid=(tree[k].s+tree[k].e)>>1;
    if(mid<a)
        update(k<<1|1);
    else
        update(k<<1);
    tree[k].zu=tree[k<<1].zu+tree[k<<1|1].zu;
    tree[k].num=tree[k<<1].num+tree[k<<1|1].num;
    if(tmp[tree[k<<1|1].s-1]=='.'&&tmp[tree[k<<1].e-1]=='.')
        tree[k].zu--;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    getchar();
    scanf("%s",tmp);
    build(1,n,1);
    for(int i=0;i<m;i++)
    {
        getchar();
        scanf("%d%s",&a,q);
        tmp[a-1]=q[0];
        update(1);
        printf("%d\n",tree[1].num-tree[1].zu);
    }
}

      	 		 	   	  		  	 				