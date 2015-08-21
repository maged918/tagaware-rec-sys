//Language: MS C++


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


struct no{
	int p[26];
	no(){
		for(int i=0;i<26;i++)p[i]=0;
	}
};
int n;
vector<int> adj[500500];
char str[500500];
int rnk[500500];
int r=1;
vector<no> ss[500500];
vector<int> rr[500500];

int mnr[500500];
int mxr[500500];

void dfs(int nd,int lvl){
	rnk[nd]=r;
	mxr[nd]=r;
	mnr[nd]=r;
	no t;
	int si=ss[lvl].size();
	if(si>0)
	for(int i=0;i<26;i++){
		t.p[i]=ss[lvl][si-1].p[i];
	}
	t.p[str[nd]-'a']++;
	ss[lvl].push_back(t);
	rr[lvl].push_back(r);
	r++;
	for(int i=0;i<adj[nd].size();i++){
		int ch=adj[nd][i];
		dfs(ch,lvl+1);
		mnr[nd]=min(mnr[nd],mnr[ch]);
		mxr[nd]=max(mxr[nd],mxr[ch]);
	}
}
int m;
int main(){
	scanf("%d %d",&n,&m);
	int tt;
	for(int i=2;i<=n;i++){
		scanf("%d",&tt);
		adj[tt].push_back(i);
	}
	scanf("%s",str+1);
	dfs(1,1);
	
	int v,lv;
	while(m--){
		scanf("%d %d",&v,&lv);

		int l=-1,r=ss[lv].size();
		int left,right;
		while(r-l>1){
			int m=(r+l)/2;
			if(rr[lv][m]<mnr[v]){
				l=m;
			} else {
				r=m;
			}
		}
		left=l;


		l=-1,r=ss[lv].size();
		while(r-l>1){
			int m=(r+l)/2;
			if(rr[lv][m]<=mxr[v]){
				l=m;
			} else {
				r=m;
			}
		}
		right=l;
		int nm=0;
		if(right==-1){
			cout<<"Yes"<<endl;
			continue;
		}
		for(int i=0;i<26;i++){
			int tgt=ss[lv][right].p[i];
			if(left!=-1){
				tgt-=ss[lv][left].p[i];
			}
			if(tgt%2){
				nm++;
			}
		}
		if(nm>1){
			cout<<"No"<<endl;
		} else {
			cout<<"Yes"<<endl;
		}
	}
}