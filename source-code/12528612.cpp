//Language: GNU C++


#include<bits/stdc++.h>
#define pn() printf("\n")
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sll(x) scanf("%I64d",&x)
#define pll(x) printf("%I64d\n",x)
#define sc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define sf(x) scanf("%f",&x)
#define pf(x) printf("%f\n",x)
#define sd(x) scanf("%lf",&x)
#define pd(x) printf("%.9lf\n",x)
#define sld(x) scanf("%Lf",&x)
#define pld(x) printf("%.9Lf\n",x)
#define MOD 1000000007
#define ll long long
#define eps 1e-10
using namespace std;
vector<int> child[500001];
vector<pair<int,int> > layer[500001];
string s;
int in[500001];
int out[500001];
int ti=0;
void dfs(int vertex,int height){
    in[vertex]=++ti;
    layer[height].push_back(make_pair(ti,layer[height].back().second^(1<<(s[vertex-1]-'a'))));
    for(int i=0;i<child[vertex].size();i++){
        dfs(child[vertex][i],height+1);
    }
    out[vertex]=++ti;
}
int main(void){
    int n,m,p,v,h;
    si(n);si(m);
    for(int i=2;i<=n;i++){
        si(p);
        child[p].push_back(i);
    }
    cin>>s;
    for(int i=0;i<=500000;i++){
        layer[i].resize(1);
    }
    dfs(1,1);
    for(int i=1;i<=m;i++){
        si(v);si(h);
        int from=lower_bound(layer[h].begin(),layer[h].end(),make_pair(in[v],-1))-layer[h].begin()-1;
        int to=lower_bound(layer[h].begin(),layer[h].end(),make_pair(out[v],-1))-layer[h].begin()-1;
        int val1=layer[h][from].second;
        int val2=layer[h][to].second;
        int ans=val1^val2;
        int cnt=__builtin_popcount(ans);
        if(cnt>1){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
    return 0;
}
