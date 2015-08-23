//Language: GNU C++11


#include <bits/stdc++.h>
#define NMAX 500050
#define rf freopen("inp.in","r",stdin)

using namespace std;

int S[NMAX] , F[NMAX] , timer = 0;
char swag[NMAX];
vector<int>adjList[NMAX];
vector<int>LEVEL[NMAX][26];

void dfs( int node , int lvl){
	LEVEL[lvl][swag[node-1] - 97 ].push_back(timer+1);
	S[node] = ++timer;
	for(int i = 0 ; i < adjList[node].size() ; i++) 
		dfs( adjList[node][i] , lvl+1);
	F[node] = ++timer;
}

int main(){
	
	//rf;
	
	int N , Q;
	scanf("%d %d",&N,&Q);

	for(int i = 2 ; i <= N ; i++){
		int ajkrishpro = 0;
		scanf("%d",&ajkrishpro);
		adjList[ajkrishpro].push_back(i);
	}

	scanf("%s",swag);


	dfs(1,0);

	while(Q--){
		
		int v , h;
		
		scanf("%d %d",&v,&h);
		h--;
		int ans = 0;
		
		vector<int>::iterator lef , rig;

		for(int i = 0 ; i <= 25 ; i++){
			lef = lower_bound(LEVEL[h][i].begin() , LEVEL[h][i].end() , S[v]);
			rig = lower_bound(LEVEL[h][i].begin() , LEVEL[h][i].end() , F[v]);
			int cur = (rig - lef);
			if( cur % 2 == 1 ) ans++;
		}
		if( ans > 1) printf("No\n");
		else         printf("Yes\n");
	}

	return 0;
}