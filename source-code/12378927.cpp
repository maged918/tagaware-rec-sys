//Language: GNU C++


#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>
#include <ctime>
 
#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define LL long long
 
#define MAX 100005
#define AMAX 26
#define MOD 1499999957

#define f(c,d) ((1<<(c))*(d))
 
using namespace std;

struct w{
	int a,b,c;
} ww[MAX];

int n,m,s,t,ta,tb;
LL tc;
vector<int> to[MAX],from[MAX];
LL da[MAX],db[MAX],dd;
LL wa[MAX],wb[MAX],www;
pair<LL,int> pt;
priority_queue<pair<LL,int> > q;

int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	F1(a,0,m){
		scanf("%d%d%d",&ww[a].a,&ww[a].b,&ww[a].c);
		to[ww[a].a].pb(a);
		from[ww[a].b].pb(a);
	}
	F2(a,1,n)da[a]=db[a]=LLONG_MAX;
	q.push(make_pair(-0,s));
	da[s]=0;
	wa[s]=1;
	while(!q.empty()){
		pt=q.top();
		q.pop();
		if(da[pt.second]!=-pt.first)continue;
		F1(a,0,to[pt.second].size()){
			if(da[pt.second]+ww[to[pt.second][a]].c<da[ww[to[pt.second][a]].b]){
				da[ww[to[pt.second][a]].b]=da[pt.second]+ww[to[pt.second][a]].c;
				q.push(make_pair(-da[ww[to[pt.second][a]].b],ww[to[pt.second][a]].b));
				wa[ww[to[pt.second][a]].b]=wa[pt.second];
			}else if(da[pt.second]+ww[to[pt.second][a]].c==da[ww[to[pt.second][a]].b])wa[ww[to[pt.second][a]].b]=(wa[ww[to[pt.second][a]].b]+wa[pt.second])%MOD;
		}
	}
	q.push(make_pair(-0,t));
	db[t]=0;
	wb[t]=1;
	while(!q.empty()){
		pt=q.top();
		q.pop();
		if(db[pt.second]!=-pt.first)continue;
		F1(a,0,from[pt.second].size()){
			if(db[pt.second]+ww[from[pt.second][a]].c<db[ww[from[pt.second][a]].a]){
				db[ww[from[pt.second][a]].a]=db[pt.second]+ww[from[pt.second][a]].c;
				q.push(make_pair(-db[ww[from[pt.second][a]].a],ww[from[pt.second][a]].a));
				wb[ww[from[pt.second][a]].a]=wb[pt.second];
			}else if(db[pt.second]+ww[from[pt.second][a]].c==db[ww[from[pt.second][a]].a])wb[ww[from[pt.second][a]].a]=(wb[ww[from[pt.second][a]].a]+wb[pt.second])%MOD;
		}
	}
	dd=da[t];
	www=wa[t];
	F1(a,0,m){
		if(da[ww[a].a]==LLONG_MAX||db[ww[a].b]==LLONG_MAX)printf("NO\n");
		else if(da[ww[a].a]+ww[a].c+db[ww[a].b]==dd&&(wa[ww[a].a]*wb[ww[a].b])%MOD==www)printf("YES\n");
		else{
			tc=dd-1-da[ww[a].a]-db[ww[a].b];
			if(tc<=0)printf("NO\n");
			else printf("CAN %I64d\n",ww[a].c-tc);
		}
	}
	//system("pause");
    return 0;
}
