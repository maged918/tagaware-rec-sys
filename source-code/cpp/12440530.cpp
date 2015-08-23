//Language: GNU C++


#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100010
#define oo 3e15
const long long mod = 1e8 + 7;

typedef pair <long long,long long> ii;
typedef pair <ii,long long> iii;
vector <ii> adj_s[MAX];
vector <ii> adj_t[MAX];
vector <iii> road; 
long long n,m,s,t;
long long d_s[MAX];
long long d_t[MAX];
long long f_s[MAX];
long long f_t[MAX];
priority_queue< ii , vector<ii> , greater<ii> > pq;

void dijkstra_s()
{
    priority_queue< ii , vector <ii>, greater <ii> > pq;
     for (int i = 1;i <= n;i++) {d_s[i] = oo;f_s[i] = 0;}
     d_s[s] = 0;
     f_s[s] = 1;
     pq.push(ii(0, s));
     while (!pq.empty())
     {
          long long du = pq.top().first;
          int u = pq.top().second;
          pq.pop();
          if (d_s[u] == du)
          {
               for (int i = 0;i < adj_s[u].size();i++)
               {
                    long long uv = adj_s[u][i].first;
                    int v = adj_s[u][i].second;
                    if (du + uv == d_s[v]) f_s[v] = (f_s[v] + f_s[u])%mod;
                    if (d_s[v]>du+uv)
                    {
                         d_s[v]=du+uv;
                         f_s[v]=f_s[u];
                         pq.push(ii(d_s[v],v));
                    }
               }
          }
     }

}

void dijkstra_t()
{
    priority_queue< ii , vector <ii>, greater <ii> > pq;
     for (int i = 1;i <= n;i++) {d_t[i] = oo;f_t[i] = 0;}
     f_t[t] = 1;
     d_t[t] = 0;
     pq.push(ii(0, t));
     while (!pq.empty())
     {
          long long du = pq.top().first;
          int u = pq.top().second;
          pq.pop();
          if (d_t[u] == du)
          {
               for (int i = 0;i < adj_t[u].size();i++)
               {
                    long long uv = adj_t[u][i].first;
                    int v = adj_t[u][i].second;
                    if (du + uv == d_t[v]) f_t[v] = (f_t[v] + f_t[u])%mod;
                    if (du + uv < d_t[v])
                    {
                         d_t[v] = du + uv;
                         f_t[v] = f_t[u];
                         pq.push(ii(d_t[v], v));
                    }
               }
          }
     }
}

int main()
{
//  freopen("TEST.inp","r",stdin);
    
    long long i,x,y,v;
    scanf("%lld %lld %lld %lld",&n,&m,&s,&t);
    
    for(i=0;i<m;i++){
        scanf("%lld %lld %lld",&x,&y,&v);
        adj_s[x].push_back(ii(v,y));
        adj_t[y].push_back(ii(v,x));
        road.push_back(iii(ii(x,y),v));
    }
    
    dijkstra_s();
    dijkstra_t();
   
    for(i=0;i<road.size();i++){
        x=road[i].first.first;
        y=road[i].first.second;
        v=road[i].second;
        if(d_s[x]+d_t[y]+v==d_s[t] && (f_s[x]*f_t[y])%mod==f_s[t]){
            printf("YES\n");
        }
        else if(d_s[x]+d_t[y]+v-(d_s[t]-1)<v){
            printf("CAN %lld\n",d_s[x]+d_t[y]+v-(d_s[t]-1));
        }
        else{
            printf("NO\n");
        }
    }
}