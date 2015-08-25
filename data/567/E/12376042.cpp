//Language: GNU C++


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long int ll;

const int limite=1000000;
ll modulo=999999929;//1e9+7;
ll modulo2=999999937;
const ll infinito=100000000000000LL;
int n,m;

void calcula(vector<pair<int,ll> > g[limite],ll dist[limite],ll cuantos[limite],ll cuantos2[limite],int s)
{
  for (int i=1;i<=n;i++)
    dist[i]=infinito;
  dist[s]=0;
  cuantos[s]=1;
  cuantos2[s]=1;
  priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
  q.push(pair<ll,int> (0,s));
  while (not q.empty()) {
    pair<ll,int> p=q.top();
    q.pop();
    int u=p.second;
    ll du=p.first;
    if (du==dist[u]) {
      vector<pair<int,ll> > &ar=g[u];
      for (int i=0;i<int(ar.size());i++) {
	int v=ar[i].first;
	ll duv=ar[i].second;
	if (du+duv<dist[v]) {
	  dist[v]=du+duv;
	  cuantos[v]=cuantos[u];
	  cuantos2[v]=cuantos2[u];
	  q.push(pair<ll,int> (dist[v],v));
	} else if (du+duv==dist[v]) {
	  cuantos[v]=(cuantos[v]+cuantos[u])%modulo;
	  cuantos2[v]=(cuantos2[v]+cuantos2[u])%modulo;
	}
      }
    }
  }
}

ll dist[limite],distinv[limite];
ll cuantos[limite],cuantosinv[limite];
ll cuantos2[limite],cuantosinv2[limite];
vector<pair<int,ll> > g[1000000],ginv[1000000];

int s,t;

int au[limite],av[limite],al[limite];

int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>m>>s>>t;
  for (int i=1;i<=m;i++) {
    int u,v,l;
    cin>>u>>v>>l;
    au[i]=u;
    av[i]=v;
    al[i]=l;
    g[u].push_back(pair<int,ll> (v,l));
    ginv[v].push_back(pair<int,ll> (u,l));
  }
  calcula(g,dist,cuantos,cuantos2,s);
  calcula(ginv,distinv,cuantosinv,cuantosinv2,t);
  for (int i=1;i<=m;i++) {
    int u=au[i];
    int v=av[i];
    int l=al[i];
    ll dsuvt=dist[u]+l+distinv[v];
    if (dsuvt==dist[t]) {
      if (cuantos[u]*cuantosinv[v]%modulo==cuantos[t] and cuantos2[u]*cuantosinv2[v]%modulo==cuantos2[t])
	cout<<"YES"<<endl;
      else if (l>1) cout<<"CAN 1"<<endl;
      else cout<<"NO"<<endl;
    } else {
      //cout<<u<<" "<<v<<" "<<l<<" "<<dsuvt<<" "<<dist[t]<<endl;
      if (dsuvt-(dist[t]-1)<=l-1) cout<<"CAN "<<dsuvt-(dist[t]-1)<<endl;
      else cout<<"NO"<<endl;
    }
  }
}
