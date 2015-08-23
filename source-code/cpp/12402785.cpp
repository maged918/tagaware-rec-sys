//Language: GNU C++11


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<functional>
#include<string>
#include<algorithm>
#include<time.h>
#include<bitset>
void fre(){freopen("c://test//input.in","r",stdin);freopen("c://test//output.out","w",stdout);}
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
template <class T> inline void gmax(T &a,T b){if(b>a)a=b;}
template <class T> inline void gmin(T &a,T b){if(b<a)a=b;}
using namespace std;
const int N=1e5+10,M=N<<1,Z=1e9+7,maxint=2147483647,ms31=522133279,ms63=1061109567,ms127=2139062143;
const double eps=1e-8,PI=acos(-1.0);//.0
map<int,int>mop;
struct A
{
	int x,y,z;
}a[N];
int id,O,tim,top;
int n,m,ST,ED;
int x,y,z;
int first[2][N];
int w[2][M],c[2][M],nxt[2][M];//这里的边数依然是要*2的，因为我们有下标的映射关系
int ff[N];
int ww[M],nn[M];
LL f[2][N];
bool e[N];
int dfn[N],low[N],s[N];
bool isbridge[N];
struct node
{
	int x;LL v;
	node(){}
	node(int x_,LL v_){x=x_;v=v_;}
	bool operator<(const node &b)const
	{
		return v>b.v;
	}
};
priority_queue<node>q;
void ins(int o,int x,int y,int z)
{
	id++;
	w[o][id]=y;
	c[o][id]=z;
	nxt[o][id]=first[o][x];
	first[o][x]=id;
}
void ii(int x,int y)
{
	id++;
	ww[id]=y;
	nn[id]=ff[x];
	ff[x]=id;
}
void inq(int x,int y,LL v)
{
	if(v>=f[O][y])return;
	f[O][y]=v;
	q.push(node(y,v));
}
void dij(int ST)
{
	MS(f[O],31);
	MS(e,0);
	inq(0,ST,0);
	while(!q.empty())
	{
		int x=q.top().x;q.pop();
		if(e[x])continue;e[x]=1;
		for(int z=first[O][x];z;z=nxt[O][z])
		{
			inq(x,w[O][z],f[O][x]+c[O][z]);
		}
	}
}
void tarjan(int x,int lastz)
{
	int y,z;
	dfn[x]=low[x]=++tim;//时间戳赋值
	s[++top]=x;e[x]=1;//入栈
	for(z=ff[x];z;z=nn[z])if((z^lastz)!=1)//不能走反父边
	{
		y=ww[z];
		if(dfn[y]==0)tarjan(y,z);//tarjan没有处理过的点
		if(e[y])gmin(low[x],low[y]);//更新当前点的最早时间戳
	}
	if(dfn[x]==low[x])//这个点是一个双连通分量的根
	{
		while(1)
		{
			y=s[top--];e[y]=0;//取出栈中的当前节点
			if(y==x)break;//退掉
		}
		isbridge[lastz>>1]=1;//同时从之前连通块通向这个子连通块的就是桥
	}
}
int main()
{
	while(~scanf("%d%d%d%d",&n,&m,&ST,&ED))
	{
		MS(first,0);id=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			a[i].x=x;a[i].y=y;a[i].z=z;
			ins(0,x,y,z);
			ins(1,y,x,z);
		}
		O=0;dij(ST);LL DIS=f[O][ED];
		O=1;dij(ED);
		MS(ff,0);id=1;
		for(int i=1;i<=m;i++)
		{
			x=a[i].x;y=a[i].y;z=a[i].z;
			LL dis=f[0][x]+f[1][y]+z;
			if(dis==DIS)
			{
				ii(x,y);
				ii(y,x);
			}
			else id+=2;//细节，为了实现边的映射，这里要+2
		}
		MS(isbridge,0);
		MS(dfn,0);MS(low,0);
		tarjan(ST,0);
		for(int i=1;i<=m;i++)
		{
			if(isbridge[i])printf("YES\n");//必经之路
			else
			{
				x=a[i].x;y=a[i].y;z=a[i].z;
				LL dis=f[0][x]+f[1][y]+z;
				LL reduce=dis-(DIS-1);
				if(z>reduce)printf("CAN %I64d\n",reduce);
				else printf("NO\n");
			}
		}
	}
	return 0;
}
/*
【题意】
有n个城市，城市之间以单向边连通（★图论题一定要看边的方向性★），边权一定为正整数
我们想从s到t，而且一定走从s到t的最短路
我们想知道
对于每条路
（1）它是否必然是从s到t的必经之路，如果是则输出YES
（2）能否修改它的权值（肯定是往小修改啦）（修改后依然为正整数），使得这条路成为从s到t的必经之路，如果可以输出CAN和权值减少量
（3）无论如何，这条路都不可能是从s到t的必经之路，则输出NO

【类型】
图论

dijstra+heap最短路
&&
tarjan判桥算法

【分析】
首先肯定要求最短路了
这样我们检测一条边是否是最短路的边
要看它到ST和ED的距离
鉴于原图是单向图，所以我们要建立一个反图
原图从ST做最短路，反图从ED做最短路，对于是最短路上的边，需要判定它是否是必经之路
什么是必经之路呢？就是如果扔掉这条边，那么原图的连通性受到破坏。
桥是建立在无向图的基础上
于是对于这些边，我们建一个无向图，让后跑tarjan，标记所有是桥的边
然后就AC啦

【时间复杂度&&优化】

【trick】


【数据】
Sample test(s)
input
6 7 1 6
1 2 2
1 3 10
2 3 7
2 4 8
3 5 3
4 5 2
5 6 1
output
YES
CAN 2
CAN 1
CAN 1
CAN 1
CAN 1
YES

input
3 3 1 3
1 2 10
2 3 10
1 3 100
output
YES
YES
CAN 81

input
2 2 1 2
1 2 1
1 2 2
output
YES
NO

*/