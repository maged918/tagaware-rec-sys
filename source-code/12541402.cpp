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
#define MP(x,y) make_pair(x,y)
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned int UI;
template <class T> inline void gmax(T &a,T b){if(b>a)a=b;}
template <class T> inline void gmin(T &a,T b){if(b<a)a=b;}
using namespace std;
const int N=5e5+10,M=0,Z=1e9+7,maxint=2147483647,ms31=522133279,ms63=1061109567,ms127=2139062143;
const double eps=1e-8,PI=acos(-1.0);//.0
map<int,int>mop;
int id,tim;
int n,m,i;
int first[N],w[N],nxt[N],p[N],d[N],in[N],ou[N],low[N];
vector<pair<int,int>>a[N];
char s[N];
int b[32];
void ins(int x,int y)
{
	id++;
	w[id]=y;
	nxt[id]=first[x];
	first[x]=id;
}
void dfs(int x)
{
	in[x]=++tim;
	a[d[x]].push_back(MP(tim,a[d[x]].back().second^b[s[x]-'a']));
	if(!first[x])low[x]=d[x];
	else for(int z=first[x];z;z=nxt[z])
	{
		int y=w[z];
		d[y]=d[x]+1;
		dfs(y);
		gmax(low[x],low[y]);//最大深度
	}
	ou[x]=tim;
}
void init()
{
	//MS(low,0);
	//MS(first,0);id=tim=0;
	for(int i=1;i<=n;i++)a[i].resize(1);
	//★resize(size)函数，clear到只剩下前面size和个元素★
}
int main()
{
	for(int i=0;i<26;i++)b[i]=1<<i;
	while(~scanf("%d%d",&n,&m))
	{
		init();
		for(i=2;i<=n;i++)
		{
			scanf("%d",&p[i]);
			ins(p[i],i);
		}
		scanf("%s",s+1);
		d[1]=1;dfs(1);
		int x,h;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&h);
			//没有这个深度的子节点则直接输出YES
			if(h<d[x]||h>low[x])
			{
				printf("Yes\n");
				continue;
			}
			//有这个深度的子节点，则两次二分找到第一个和最后一个
			int g=a[h].size();
			int lft=(--lower_bound(a[h].begin(),a[h].end(),MP(in[x],-1)))->second;
			int rgt=(--lower_bound(a[h].begin(),a[h].end(),MP(ou[x],ms63)))->second;
			int v=rgt^lft;
			if(v==(v&-v))printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
/*
【题意】
给你一棵树，n个节点，定义1为root。1的深度d[1]=1
m个询问，每个询问(x,h)
问——以节点x为根的子树。在深度h这一层的所有子节点，能否构成（可以任意排列）回文串

【类型】
dfs序
倍增祖先

【分析】
首先——
否能构成回文串，
如果串长为偶数——是要看这些字符是否都为偶数个
如果串长为奇数——是要看这些字符是否最多只有一个为奇数个

想法很简单——
我们首先要建树，并且处理出每个节点的深度
然后我们要找到这个节点深度在h的所有节点
而且要很快找到

怎么找呢？
显然要记录在某个深度的所有节点
而且还要有顺序，这样一个节点在这一层的子节点才会是连续的一段

于是我们在dfs建树的过程中就把深度为某个深度的所有点压进去（程序中是a[]）
而且显然，这样的话，一个节点的所有儿子必然是连续的一段

然后，我们还可以标记出每个点入和出的dfs序
我们知道——一个节点子节点的[入子，出子]必然是[入父，出父]的子集
这样我们就能O(1)判定一个节点是不是另外一个节点的子节点

于是做法出炉，当当当当——
dfs出所有深度的所有节点，并且对每个深度求一个字符集数量的前缀和
然后对于每个询问，通过2次二分操作，查找出这一层这个节点的第一个儿子和最后一个儿子
然后通过前缀和判定是否可以重构成回文串

【时间复杂度&&优化】
O(26n+26m*2log(n))

字符数26，以后都可以把它用一个inthash存储，我们只需要用xor sum知道它是奇数还是偶数即可


【trick】
变量对应好，不要写错了

【数据】
7 7
1 1 1 2 3 4
aabcdde
1 1
1 2
1 3
2 1
2 2
2 3
2 4
*/