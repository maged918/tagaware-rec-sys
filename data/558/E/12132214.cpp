//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
#define f first
#define pii pair<pi,ll>
#define pi pair<ll,ll>
#define pb emplace_back

#define ll long long
#define s second
#define rep(i,n) for(int i=0;i<n;i++)
#define mp make_pair
#define fr freopen("input-4.txt","r",stdin)
#define fo freopen("output-4.txt","w",stdout)
int tree[400011][26];
int lazy[400011][26];
struct node{
	int l,r,idx,w;
	node(){}
	node(int _l,int _r,int _idx,int _w){
		l=_l;
		r=_r;
		idx=_idx;
		w=_w;
		lazy_update();
	}
	node left(){
		return node(l,(l+r)/2,2*idx,w);
	}
	node right(){
		return node((l+r)/2+1,r,2*idx+1,w);
	}
	void lazy_update(){
		if(lazy[idx][w]==-1) return ;
		if(l!=r){
			lazy[2*idx][w]=lazy[idx][w];
			lazy[2*idx+1][w]=lazy[idx][w];
		}
		tree[idx][w]=lazy[idx][w]*(r-l+1);
		lazy[idx][w]=-1;
	}

	void update(int s,int e,int val){
		if(r<s or e<l or s>e) return;
		if(s<=l and r<=e){
			lazy[idx][w]=val;
			lazy_update();
			return;
		}
		left().update(s,e,val);
		right().update(s,e,val);
		tree[idx][w]=tree[2*idx][w]+tree[2*idx+1][w];
	}
	int query(int s,int e){
		if(r<s or e<l or s>e) return 0;
		if(s<=l and r<=e) return tree[idx][w];
		return left().query(s,e)+right().query(s,e);
	}

};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q,l,r,w;
	cin >> n >> q;
	string s;
	cin >> s;
	rep(i,4*n){
		rep(j,26){
			//tree[i+1][j]=-1;
			lazy[i+1][j]=-1;
		}
	}
	node stree[26];
	rep(i,26){
		stree[i]=node(1,n,1,i);
	}
	rep(i,n){
		stree[s[i]-'a'].update(i+1,i+1,1);
	}
	while(q--){
		cin >> l >> r >> w;
		w=1-w;
		vector<int>v(26);
		rep(i,26){
			v[i]=stree[i].query(l,r);
			//cout<<v[i]<<" ";
		}
		if(w==1){
			reverse(v.begin(),v.end());
		}
		int s=l;
		rep(i,26){
			if(v[i]>0){
				if(w){
					stree[25-i].update(s,s+v[i]-1,1);
					stree[25-i].update(l,s-1,0);
					stree[25-i].update(s+v[i],r,0);
				}
				else{
					stree[i].update(s,s+v[i]-1,1);
					stree[i].update(l,s-1,0);
					stree[i].update(s+v[i],r,0);
				}
			}
			s+=v[i];
		}
		//cout<<"\n";
		rep(i,26){
			v[i]=stree[i].query(l,r);
		//	cout<<v[i]<<" ";
		}
	}
	s="";
	for(int i=1;i<=n;i++){
		rep(j,26){
			if(stree[j].query(i,i)==1){
				s+=char(j+'a');
				break;
			}
		}
	}
	cout<<s;
}
