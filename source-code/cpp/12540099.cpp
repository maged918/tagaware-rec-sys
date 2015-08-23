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
typedef unsigned int UI;
template <class T> inline void gmax(T &a,T b){if(b>a)a=b;}
template <class T> inline void gmin(T &a,T b){if(b<a)a=b;}
using namespace std;
const int N=3e5+10,M=0,Z=1e9+7,maxint=2147483647,ms31=522133279,ms63=1061109567,ms127=2139062143;
const double eps=1e-8,PI=acos(-1.0);//.0
set<int>sot;
set<int>::iterator it,lt,rt;
struct A{};
int n,m;
char s[N];
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		scanf("%s",s+1);
		sot.clear();
		sot.insert(0);
		sot.insert(n+1);
		int ans=0;
		int num=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!='.')
			{
				if(num>=2)ans+=num-1;
				num=0;
				sot.insert(i);
			}
			else num++;
		}
		if(num>=2)ans+=num-1;
		int p;char c;
		for(int i=1;i<=m;i++)
		{
			scanf("%d %c",&p,&c);
			it=sot.find(p);
			if(c=='.')//变成.
			{
				if(it!=sot.end())//本来不是'.'才需要处理
				{
					lt=rt=it;
					--lt;
					++rt;
					num=*it-*lt-1;
					if(num>=2)ans-=(num-1);
					num=*rt-*it-1;
					if(num>=2)ans-=(num-1);
					num=*rt-*lt-1;
					if(num>=2)ans+=(num-1);
					sot.erase(it);
				}
			}
			else//变成非.
			{
				if(it==sot.end())//本来是'.'才需要处理
				{
					it=sot.insert(p).first;
					lt=rt=it;
					--lt;
					++rt;
					num=*rt-*lt-1;
					if(num>=2)ans-=(num-1);
					num=*it-*lt-1;
					if(num>=2)ans+=(num-1);
					num=*rt-*it-1;
					if(num>=2)ans+=(num-1);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*
【题意】
给定一个字符串，包含.
我们判定一个字符串的value
是看有多少个..
比如...，就有2个连续的..，所以其val就是2

同时我们有m个操作，操作有——
位置p和字符c
每个操作在之前操作的基础上，把原串的位置p的字符变成c
每次操作之后问你改变之后的value是多少

【类型】
set or 并查集 or找特征规律

【分析】
比赛时我用了set
维护一个位置左边的有多少.，右边有多少个.，然后合并xxx就AC了

【时间复杂度&&优化】

【trick】

【数据】
Sample test(s)
input
10 3
.b..bz....
1 h
3 c
9 f
output
4
3
1

input
4 4
.cc.
2 .
3 .
2 a
1 a
output
1
3
1
1

*/