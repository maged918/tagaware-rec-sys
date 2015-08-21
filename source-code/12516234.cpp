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
 
#define MAX 500005
#define AMAX 55
#define MOD 1000000007

#define f(c,d) ((1<<(c))*(d))
 
using namespace std;

int n,m,ta,tb,tc;
vector<int> child[MAX];
int now;
int start[MAX],end[MAX];
char x[MAX];
vector<int> hy[MAX][26];
vector<int>::iterator it;

void dfs(int a,int c){
	start[a]=now;
	hy[c][x[a]-'a'].pb(now);
	now++;
	c++;
	F1(b,0,child[a].size())dfs(child[a][b],c);
	end[a]=now;
}

int main(){
	scanf("%d%d",&n,&m);
	F1(a,1,n){
		scanf("%d",&ta);
		child[ta-1].pb(a);
	}
	scanf("%s",x);
	dfs(0,0);
	while(m--){
		scanf("%d%d",&ta,&tb);
		ta--;
		tb--;
		tc=0;
		F1(a,0,26){
			it=lower_bound(hy[tb][a].begin(),hy[tb][a].end(),end[ta]);
			if((it-lower_bound(hy[tb][a].begin(),it,start[ta]))%2==1)tc++;
		}
		if(tc>=2)printf("No\n");
		else printf("Yes\n");
	}
	//system("pause");
    return 0;
}
