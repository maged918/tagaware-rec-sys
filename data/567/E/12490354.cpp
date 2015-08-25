//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iterator>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;
const LL  M = 200009;
LL INF = 1000000000000LL;
LL prime = 1044556773;
LL V, E, s, e;
struct edges{LL from, to, cost;};
struct edge{LL to, cost;};
vector<struct edge> G1[M], G2[M];
vector<edges > g;
struct dot{LL x, ways;}d1[M], d2[M];

void input(void)
{
    scanf("%I64d%I64d%I64d%I64d", &V, &E, &s, &e);
    for (LL i = 0; i < E; i++) {
        LL x, y, z;
        scanf("%I64d%I64d%I64d", &x, &y, &z);
        G1[x].push_back({y, z});
        G2[y].push_back({x, z});
        g.push_back({x, y, z});
    }
}

void dijkstra1(LL s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    for (LL i = 0; i  < V + 100; i++) d1[i].x = INF, d1[i].ways = 0;
    d1[s].x = 0;
    d1[s].ways = 1;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        LL v = p.second;
        if (d1[v].x < p.first) continue;
        for (LL i = 0; i < G1[v].size(); i++) {
            edge ed = G1[v][i];
            if (d1[ed.to].x == d1[v].x + ed.cost ) {
                d1[ed.to].ways = (d1[v].ways % prime + d1[ed.to].ways % prime) % prime;
            } else
            if (d1[ed.to].x > d1[v].x + ed.cost){
                d1[ed.to].x = d1[v].x + ed.cost;
                d1[ed.to].ways = d1[v].ways;
                que.push(P(d1[ed.to].x, ed.to));
            }
        }
    }
}

void dijkstra2(LL s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    for (LL i = V + 100; i  > 0; i--) d2[i].x = INF, d2[i].ways = 0;
    d2[s].x = 0;
    d2[s].ways = 1;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        LL v = p.second;
        if (d2[v].x < p.first) continue;
        for (LL i = 0; i < G2[v].size(); i++) {
            edge ed = G2[v][i];
            if (d2[ed.to].x == d2[v].x + ed.cost) {
                d2[ed.to].ways = (d2[v].ways % prime + d2[ed.to].ways % prime) % prime;
            } else
            if (d2[ed.to].x > d2[v].x + ed.cost){
                d2[ed.to].x = d2[v].x + ed.cost;
                d2[ed.to].ways = d2[v].ways;
                que.push(P(d2[ed.to].x, ed.to));
            }
        }
    }
}

void qian(set<LL> s) {for (set<LL>::iterator it = s.begin(); it != s.end(); it++) cout << *it << endl; cout << "over" << endl;}

int main(void)
{
    input();
    dijkstra1(s);//for (LL i = 1 ; i < V + 1; i++) {cout << "�㣺" << i << "����̾���:" << d1[i].x << " ���·��: " << d1[i].ways  << endl; }

    dijkstra2(e);
    for (LL i = 0; i < g.size(); i++) {
        LL sx = g[i].from, ex = g[i].to, y = g[i].cost;
        if (d1[sx].x + d2[ex].x == d1[e].x - y && ((d1[sx].ways%prime) * (d2[ex].ways%prime))%prime == d1[e].ways % prime) {
            printf("YES\n");
        } else {
            LL z = d1[e].x - d1[sx].x - d2[ex].x;
            if (z - 1<= 0) printf("NO\n");
            else {printf("CAN %I64d\n", y - z + 1);}
        }
    }
    return 0;
}

  		  	 		 				 		 	   	 		  		