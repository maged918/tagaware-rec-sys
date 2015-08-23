//Language: GNU C++11


#include<bits/stdc++.h>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;

struct cell
{
    int nod,in;
};

const int NMAX=500005;

int n,m,len,start[NMAX],stop[NMAX],niv[NMAX],ans[NMAX];
int AIB[NMAX];
char c[NMAX];
vector<int>v[NMAX];
vector<cell>Q[NMAX];
vector<cell>::iterator sit;
vector<int>nodes[NMAX];
vector<int>::iterator it;

void DFS(int x,int nivel)
{
    niv[x]=nivel;
    len++;
    start[x]=len;
    for (vector<int>::iterator pit=v[x].begin();pit!=v[x].end();pit++)
        DFS(*pit,nivel+1);
    stop[x]=len;
}

inline int zeros(int x)
{
    return x^(x&(x-1));
}

inline void Update(int poz,int val)
{
    for (int i=poz;i<=n;i+=zeros(i)) AIB[i]^=val;
}

inline int Query(int poz)
{
    int i,rez=0;
    for (i=poz;i>=1;i-=zeros(i)) rez^=AIB[i];
    return rez;
}

int main()
{
    int i,j,x,aux,cnt;
    cell k;

    cin.sync_with_stdio(false);
    cin>>n>>m;
    for (i=1;i<n;i++)
        {
            cin>>x;
            v[x].push_back(i+1);
        }
    DFS(1,1);
    cin>>(c+1);
    for (i=1;i<=m;i++)
        {
            cin>>k.nod>>x;
            k.in=i;
            Q[x].push_back(k);
        }
    for (i=1;i<=n;i++) nodes[niv[i]].push_back(i);
    for (i=1;i<NMAX;i++)
        {
            //sterg nodurile trecute
            for (it=nodes[i-1].begin();it!=nodes[i-1].end();it++)
                Update(start[*it],1<<(c[*it]-'a'));
            //bag
            for (it=nodes[i].begin();it!=nodes[i].end();it++)
                 Update(start[*it],1<<(c[*it]-'a'));

            //raspund
            for (sit=Q[i].begin();sit!=Q[i].end();sit++)
                {
                    aux=Query(stop[(*sit).nod])^Query(start[(*sit).nod]-1);
                    cnt=0;
                    while (aux && cnt<=1)
                        {
                            aux-=aux^(aux&(aux-1));
                            cnt++;
                        }
                    if (cnt<=1) ans[(*sit).in]=1;
                }
        }
    for (i=1;i<=m;i++)
        if (ans[i]==1) cout<<"Yes\n";
        else cout<<"No\n";
    return 0;
}
