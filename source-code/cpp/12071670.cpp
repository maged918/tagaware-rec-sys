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
void fre(){freopen("c://test//input.in","r",stdin);freopen("c://test//output.out","w",stdout);}
template <class T> inline void scand(T &x){char c;x=0;while((c=getchar())<'0');while(c>='0'&&c<='9')x=x*10+(c-48),c=getchar();}
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned int UI;
template <class T> inline void gmax(T &a,T b){if(b>a)a=b;}
template <class T> inline void gmin(T &a,T b){if(b<a)a=b;}
using namespace std;
const int N=1e5+10,M=0,Z=1e9+7,maxint=2147483647,ms31=522133279,ms63=1061109567,ms127=2139062143;
const double eps=1e-8,PI=acos(-1.0);//.0
struct A
{
	LL l,r;
}a[N*2];
bool cmp(A a,A b)
{
	return a.l<b.l;
}
LL l,r;
int h,q,i,d,ord;
int main()
{
	while(~scanf("%d%d",&h,&q))
	{
		LL L=1ll<<(h-1);//出口标号的下届
		LL R=(1ll<<h)-1;//出口标号的上界
		int n=0;
		for(i=1;i<=q;i++)
		{
			scanf("%d%I64d%I64d%d",&d,&l,&r,&ord);//读入所有的judge
			while(d<h)//把深度降低到最后一层
			{
				l<<=1;
				r=r<<1|1;
				d++;
			}
			if(ord)//合法区间，反向处理
			{
				if(r<R)
				{
					++n;
					a[n].l=r+1;
					a[n].r=R;
				}
				if(l>L)
				{
					++n;
					a[n].l=L;
					a[n].r=l-1;
				}
			}
			else//非法区间，正向处理
			{
				++n;
				a[n].l=l;
				a[n].r=r;
			}
		}
		sort(a+1,a+n+1,cmp);a[++n].l=R+1;
		//排序的规则是第一关键字l，第二关键字r
		
		LL num=0;
		LL ans=0;
		L--;//初始化位置要停留在非法位置上，所以L--
		for(i=1;i<=n;i++)
		{
			if(a[i].l>L+1)//如果只判L,nun+=0会更新ans出错
			{
				num+=a[i].l-(L+1);
				if(num==1)ans=L+1;
			}
			gmax(L,a[i].r);
		}
		if(num==0)printf("Game cheated!\n");
		else if(num>1)printf("Data not sufficient!\n");
		else printf("%I64d\n",ans);
	}
	return 0;
}
/*
【题意】
树根是编号1，深度为1
节点i的左儿子是2i，右儿子是2i+1
迷宫的出口在某个叶节点上

总的深度可达50，也就是说叶节点数量可达2^49
接下来的q行，每行含有四个整数i,l,r,ans
表示深度为i的点中，l~r范围内的点包括或者不包括出口exit点的祖先

如果信息冲突，输出"Game cheated!"
如果能推断出出口节点的标号，输出标号
否则输出"Data not sufficient!"，表示信息不完整

【类型】
set
or
排序

【分析】
数据可能很大， 于是我们想到用set<LL>做

（1）问题一，这里的询问是有层次的，我们该如何处理这个问题呢？
因为答案是针对于最后一层的，所以我们可以把所有的询问都推到最后一层处理
如果一个节点是深度为i的（l,r）
那么它跳到深度为h，设h-i=d，（l，r）就会变成（2^d*l,blabla）

（2）问题二，对于ans==0和ans==1，分别意味着什么呢？
我们设初始的答案范围是[L,R]

如果ans==1
答案会在两个区间的交集上产生，如果没有交集，那显然Game cheated!

如果ans==0
那我们需要把这个区间排除掉
排除掉的结果是把正确答案的区间划分为若干个子区间


所以，究竟怎么做呢？
先用yes筛一个唯一的合法区间
然后再用no来筛掉一些不合法的段
最后如果恰好只剩一个点就是答案
否则无点的话——Game cheated!
多点的话——Data not sufficient!

【时间复杂度&&优化】
这道题是可以全部转换成非法区间并的
正难则反及合并思想是多么重要啊！

【trick】
我犯了一个错误，少考虑了一种情况
每个非法区间的筛除作用是建立在——
我们每次根据非法区间[l,r]
然后查找比右界比l大的合法区间

如果右界在[l,r]之中，右界是一定要筛掉的
那么对应的左界有两种情况，也在[l,r]之中或者比l小
如果也在[l,r]之中，那么自然要筛掉
如果比l小，那么会R.insert(l-1)

如果右界比r大，右界不会筛掉
★对应的左界却有三种情况★
比l小，在[l,r]之间，比r大
第一种情况是会被分成两个区间
第二种情况相当于左区间右移
第三种情况相当于不操作

★作死大坑★
（1）lower_bound和upper_bound要用set.lower_bound或upper_bound，否则因为它没有下标，时间复杂度会变成O(n)TLE
（2）iterater要先++ -- 再erase，或者写成erase(it++)否则会出错

【数据】
Sample test(s)

input
3 1
3 4 6 0
output
7

input
4 3
4 10 14 1
3 6 6 0
2 3 3 1
output
14

input
4 2
3 4 6 1
4 12 15 1
output
Data not sufficient!

input
4 2
3 4 5 1
2 3 3 1
output
Game cheated!



3 10
1 1 1 1
1 1 1 1
1 1 1 1
3 6 6 0
2 3 3 0
1 1 1 1
3 4 5 1
3 6 6 0
3 6 6 0
1 1 1 1

*/