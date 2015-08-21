//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 100010
using namespace std;
typedef long long ll;
ll read(){
	char ch=getchar();ll num=0;
	while(ch<'!')ch=getchar();
	while(ch>'!'){num=num*10+ch-48;ch=getchar();}
	return num;
}
typedef long long ll;
struct Edge{
	int from,to,next;
	bool bj;
	ll dis;
}e[maxn*2];
int cnt,h[maxn];
void add(int u,int v,ll d){
	cnt++;e[cnt].to=v;e[cnt].from=u;
	e[cnt].next=h[u];e[cnt].dis=d;h[u]=cnt;
}
int n,m,S,T;
ll disS[maxn],disT[maxn];
const ll inf=(ll)1<<45;
int que[10*maxn];
bool vis[maxn];
void SPFA(int s,ll* dis,bool modo){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)dis[i]=inf;
	int head=0,tail=1;
	que[head]=s;vis[s]=true;dis[s]=0;
	while(head!=tail){
		int u=que[head];	
		for(int i=h[u];i;i=e[i].next){
			if((i&1)==modo)continue;
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].dis){
				dis[v]=dis[u]+e[i].dis;
				if(!vis[v]){vis[v]=true;que[tail++]=v;}
			}
		}
		head++;vis[u]=false;
	}
}
struct EDGE{
	int pos,to,next;
	ll dis;
}edge[maxn*2];
int H[maxn],num;
void Add(int u,int v,ll d,int pos){
	num++;edge[num].dis=d;edge[num].to=v;
	edge[num].pos=pos;edge[num].next=H[u];H[u]=num;
}
int fa[maxn],low[maxn],pre[maxn],dfs_clock;
int bj[maxn];
void DFS(int u,int f){
	pre[u]=low[u]=++dfs_clock;
	int k=0;
	for(int i=H[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(!pre[v]){
			fa[v]=u;DFS(v,edge[i].pos);
			low[u]=min(low[u],low[v]);
			if(low[v]>pre[u])e[edge[i].pos].bj=true;
		}
		else if(pre[v]<pre[u]&&edge[i].pos!=f)
			low[u]=min(low[u],pre[v]);	
	}
}
struct Pair{
	ll dis;
	int node;
	bool operator<(const Pair& k)const{return dis>k.dis;}
	Pair(int x,ll y):node(x),dis(y){}
};
priority_queue<Pair>Q;
void Dijkstra(int S,ll* dis,int modo){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)dis[i]=inf;dis[S]=0;
	Q.push(Pair(S,0));
	while(!Q.empty()){
		int u=Q.top().node;Q.pop();
		if(vis[u])continue;vis[u]=1;
		for(int i=h[u];i;i=e[i].next){
			if((i&1)==modo)continue;
			int v=e[i].to;
			if(dis[u]+e[i].dis<dis[v]){
				dis[v]=dis[u]+e[i].dis;
				Q.push(Pair(v,dis[v]));
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	int u,v;ll d;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);d=read();
		add(u,v,d);add(v,u,d);
	}
//	SPFA(S,disS,0);
//	SPFA(T,disT,1);
	Dijkstra(S,disS,0);
	Dijkstra(T,disT,1);
	ll tmp=disS[T];
	for(int i=1;i<=cnt;i+=2){
		int u=e[i].from,v=e[i].to;
		ll d=e[i].dis;
		if(disS[u]+d+disT[v]==tmp){
			Add(u,v,d,i);
			Add(v,u,d,i);
		}
	}
	DFS(S,-1);	
	for(int i=1;i<=cnt;i+=2){
		if(e[i].bj){
			printf("YES\n");
			continue;
		}
		int u=e[i].from,v=e[i].to;
		ll d=disS[u]+disT[v];
		if(tmp-d-1<=0){
			printf("NO\n");
			continue;	
		}
		printf("CAN %d\n",e[i].dis+d-tmp+1);
	}
	return 0;	
}
