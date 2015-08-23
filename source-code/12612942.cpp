//Language: GNU C++


#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>
#include<queue>
#include<map>
#include<functional>
using namespace std;
const int inf = 1<<28;
const double eps = 1e-8;

struct node
{
	int val;
	int dis;
	node(){}
	node(int x,int y):val(x),dis(y){};
};
int n,m;
int cnt[100010],step[100010],vis[100010];
queue<node> q;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("test.txt","r",stdin);
	#endif
	
	while(~scanf("%d",&n)){
		node t;
		int a;
		memset(cnt,0,sizeof cnt);
		memset(step,0,sizeof step);
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			
			q.push(node(a,0));
			while(!q.empty()){
				int x = q.front().val;
				int y = q.front().dis;
				q.pop();
				if(x >= 100001) continue;
				if(vis[x] == i) continue;

				vis[x] = i;
				cnt[x] ++;
				step[x] += y;

				q.push(node(x<<1,y+1));
				q.push(node(x>>1,y+1));
			}
		}
		int ans = inf;
		for(int i=0;i<=100000;i++)
			if(cnt[i] == n)
				ans = min(ans,step[i]);
		cout<<ans<<endl;
	}
	return 0;
}