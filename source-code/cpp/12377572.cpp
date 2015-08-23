//Language: GNU C++11


#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
#define ZERO 1e-9
#define NIL -1
using namespace std;
bool vis[100005];
int n;
long long dis[2][100005];

// A class that represents an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<pair<int,int> > *adj;    // A dynamic array of adjacency lists
    bool* vis;
    void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]);
public:
    Graph(int V,bool* vis);   // Constructor
    void addEdge(int v, int w,int i);   // function to add an edge to graph
    void bridge();    // prints all bridges
};

Graph::Graph(int V,bool *vis)
{
    this->V = V;
    this->vis=vis;
    adj = new list<pair<int,int> >[V];
}

void Graph::addEdge(int v, int w,int i)
{
    adj[v].push_back(mp(w,i));
    adj[w].push_back(mp(v,i));  // Note: the graph is undirected
}

// A recursive function that finds and prints bridges using DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
void Graph::bridgeUtil(int u, bool visited[], int disc[],
                                       int low[], int parent[])
{
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;

    // Go through all vertices aadjacent to this
    list<pair<int,int> >::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = (*i).F;  // v is current adjacent of u

        // If v is not visited yet, then recur for it
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);

            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);

            // If the lowest vertex reachable from subtree under v is
            // below u in DFS tree, then u-v is a bridge
            if (low[v] > disc[u])
              vis[(*i).S]=true;
        }

        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}

// DFS based function to find all bridges. It uses recursive function bridgeUtil()
void Graph::bridge()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];

    // Initialize parent and visited arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }

    // Call the recursive helper function to find Bridges
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}
void dij(int s,vector<pair<int,int> >g[],int t){
    priority_queue<pair<int,long long > >pq;
    pq.push(mp(s,0));
    for(int i=0;i<n;++i)dis[t][i]=1e18;
    dis[t][s]=0;
    while(!pq.empty()){
        int nd=pq.top().F;
        long long w=pq.top().S;
        pq.pop();
        if(dis[t][nd]<w)continue;
        for(int i=0,v,ww;i<g[nd].size();++i){
            v=g[nd][i].F;
            ww=g[nd][i].S;
            if(w+ww<dis[t][v]){
                dis[t][v]=ww+w;
                pq.push(mp(v,ww+w));
            }
        }
    }
}
vector<pair<int,int>>G[100005],rG[100005];
int main(){
    ios_base::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int m,s,t;
    cin>>n>>m>>s>>t;
    --s;--t;
    vector<pair<int,pair<int,int> > >el;
    for(int i=0,u,v,w;i<m;++i){
        cin>>u>>v>>w;
        --u,--v;
        G[u].pb(mp(v,w));
        rG[v].pb(mp(u,w));
        el.pb(mp(w,mp(u,v)));
    }
    dij(s,G,0);
    dij(t,rG,1);
    long long sp=dis[0][t];
    Graph gg(n,vis);
    map<pair<int,int> ,vector<int> >ss;
    for(int i=0,u,v,w;i<el.size();++i){
        w=el[i].F;
        u=el[i].S.F;
        v=el[i].S.S;
        if(dis[0][u]+dis[1][v]+w==sp){
            if(ss.count(mp(min(u,v),max(u,v)))){
                ss[mp(min(u,v),max(u,v))].pb(i);
            }
            else{gg.addEdge(u,v,i);
            ss[mp(min(u,v),max(u,v))].pb(i);
            }
        }
    }
    gg.bridge();
    for(auto &k:ss){
        if(k.S.size()>1)
        for(int i=0;i<k.S.size();++i){
            vis[k.S[i]]=false;
        }
    }
    sp--;
    for(int i=0,u,v,w;i<el.size();++i){
        w=el[i].F;
        u=el[i].S.F;
        v=el[i].S.S;
        if(vis[i]){
            cout<<"YES\n";
        }else if(dis[0][u]+dis[1][v]+1<=sp){
            cout<<"CAN "<<dis[0][u]+dis[1][v]+w-sp<<endl;
        }else{
            cout<<"NO\n";
        }
    }
}
