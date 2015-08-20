//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m, s, t;
struct Edge {
    int u, v, w, next;
} edge[MAXN * 2];
int head[MAXN], edgeNum;

inline void clearEdge() {
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, int w) {
    edge[edgeNum] = {u, v, w, head[u]};
    head[u] = edgeNum++;
}

bool visit[MAXN];
int que[MAXN];
long long distS[MAXN], distT[MAXN];

void spfa(long long dist[], int s, int filter) {
    int front = 0, rear = 1;
    memset(dist, 0x3f, sizeof(long long) * MAXN);
    memset(visit, false, sizeof(visit));
    visit[s] = true;
    dist[s] = 0;
    que[0] = s;
    while (front != rear) {
        int u = que[front];
        if (++front >= MAXN) {
            front = 0;
        }
        for (int i = head[u]; i != -1; i = edge[i].next) {
            if ((i & 1) == filter) {
                continue;
            }
            int v = edge[i].v;
            int w = edge[i].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!visit[v]) {
                    visit[v] = true;
                    if (front != rear && dist[v] < dist[que[front]]) {
                        if (--front < 0) {
                            front = MAXN - 1;
                        }
                        que[front] = v;
                    } else {
                        que[rear] = v;
                        if (++rear >= MAXN) {
                            rear = 0;
                        }
                    }
                }
            }
        }
        visit[u] = false;
    }
}

int dfn[MAXN], low[MAXN], timeStamp;
bool bridge[MAXN];

void tarjan(int u, int f = -1) {
    dfn[u] = low[u] = ++timeStamp;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        if (f == i) {
            continue;
        }
        int v = edge[i].v;
        int w = edge[i].w;
        if (((i & 1) && distT[u] + w + distS[v] == distT[s]) ||
            (!(i & 1) && distS[u] + w + distT[v] == distS[t])) {
            if (dfn[v] == 0) {
                tarjan(v, i ^ 1);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    bridge[i >> 1] = true;
                }
            } else if (dfn[v] < dfn[u]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
}

int main() {
    int u, v, w;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    clearEdge();
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    spfa(distS, s, 1);
    spfa(distT, t, 0);
    for (int i = 1; i <= n; ++i) {
        if (dfn[i] == 0) {
            tarjan(i);
        }
    }
    long long shortest = distS[t];
    for (int i = 0; i < m; ++i) {
        int u = edge[i << 1].u;
        int v = edge[i << 1].v;
        int w = edge[i << 1].w;
        if (bridge[i]) {
            puts("YES");
        } else if (distS[u] + 1 + distT[v] >= shortest) {
            puts("NO");
        } else {
            printf("CAN %I64d\n", distS[u] + w + distT[v] - shortest + 1);
        }
    }
    return 0;
}

   		  	 		 						 	  	 	   	