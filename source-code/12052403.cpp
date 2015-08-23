//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1<<30
#define N 1000010
int vis[N];
int cnt[N];
struct P
{
    int f, s;
}p[N];
struct X
{
    int num ,f, s;
}x[N];
struct Y
{
    //char c;
    int f, s;
}y[N];
bool cmp(Y c, Y d) {return c.s-c.f < d.s-d.f;}

int main()
{
    int n, a;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        cnt[a]++;
        if(!vis[a])
        {
            vis[a] = 1;
            p[a].f = i;
            p[a].s = i;
        }
        else
        {
            p[a].s = i;
        }
    }
    int maxn = 0;
    for(int i=1; i<N; i++)
        maxn = max(maxn,cnt[i]);
    queue<int> q;
    for(int i=1; i<N; i++)
    {
        if(cnt[i] == maxn) q.push(i);
    }
    //cout << "hahh";
    int t = 0;
    while(q.size())
    {
        int v = q.front(); q.pop();
        y[t].f = p[v].f;
        y[t++].s = p[v].s;
    }

    sort(y,y+t,cmp);
    cout << y[0].f+1 << " " << y[0].s+1 << endl;
    return 0;
}

/*
【题意】


【类型】


【分析】


【优化】


【trick】


【数据】


*/
