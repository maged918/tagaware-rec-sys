//Language: GNU C++


/*
classifier : 
link : 
desc : 
date : 
*/
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>
#include <queue>
#include <stack>

using namespace std;

#define SYNC ios_base::sync_with_stdio(0)
#define mp make_pair
#define pb push_back
#define FOR(i,k,n) for(int i=k ;i<n ;i++)
#define mem(kevinganteng) memset(kevinganteng,-1,sizeof(kevinganteng));
#define INF1 1000000000
#define INF2 2147483647
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
int n,k;
LL arr[200005];
map<LL,LL> maps[4];
LL ans;
int main(){
	scanf("%d %d",&n,&k);
	for (int i=0;i<n;i++) {
		scanf("%I64d",&arr[i]);
	}
	for (int i=n-1;i>=0;i--) {
		if (maps[2].find(arr[i]*k) != maps[2].end()) maps[3][arr[i]] += maps[2][arr[i]*k];
		if (maps[1].find(arr[i]*k) != maps[2].end()) maps[2][arr[i]] += maps[1][arr[i]*k];
		maps[1][arr[i]]++;
	}
	for (map<LL,LL>::iterator it=maps[3].begin();it!=maps[3].end();it++) {
		ans += it->second;
	}
	printf("%I64d",ans);
}