//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
int n, q;
char arr[500005];
vector <int> G[500005];

int dep[500005];

vector <int> DEP[500005];
bitset <26> CNT[500005];

int in[500005];
int out[500005];
int idx = 1;

void dfs(int v, int cnt) {
    in[v] = idx++;
    dep[v] = cnt;
    DEP[cnt].push_back(v);
    for(int i = 0; i < G[v].size(); i++) {
        int &u = G[v][i];
        dfs(u, cnt + 1);
    }
    out[v] = idx;
}


int main() {
    scanf("%d %d", &n, &q);
    for(int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        G[x].push_back(i);
    }
    for(int i = 1; i <= n; i++)
        scanf(" %c", &arr[i]);
    dfs(1, 1);
    for(int i = 1; i <= n; i++) {
        if(DEP[i].size() == 0) continue;
        int m = DEP[i].size();
        int prev = -1;
        for(int j = 0; j < m; j++) {
            if(j > 0) {
                CNT[DEP[i][j]] = CNT[prev];
            }
            CNT[DEP[i][j]][arr[DEP[i][j]] - 'a'] = CNT[DEP[i][j]][arr[DEP[i][j]] - 'a'] ^ 1;
            prev = DEP[i][j];
        }
    }
    for(int i = 0; i < q; i++) {
        int v, b;
        scanf("%d %d", &v, &b);
        if(DEP[b].size() == 0) {
            printf("Yes\n");
            continue;
        }
        int s = 0;
        int t = DEP[b].size() - 1;
        while(s < t) {
            int k = (s + t) / 2;
            int u = DEP[b][k];
            if(in[u] < in[v]) {
                s = k + 1;
            } else {
                t = k;
            }
        }
        int start = s - 1;
        
        s = 0;
        t = DEP[b].size() - 1;
        while(s < t) {
            int k = (s + t + 1) / 2;
            int u = DEP[b][k];
            if((in[v] < in[u] && out[u] <= out[v]) || (in[u] < in[v])) {
                s = k;
            } else {
                t = k - 1;
            }
        }
        int end = s;
        bitset <26> licz = CNT[DEP[b][end]];
        
        if(start >= 0)
            licz ^= CNT[DEP[b][start]];
        
        int siz = end - start;
        int np = 0;
        for(int j = 0; j < 26; j++)
            np += licz[j];
        if(np == 0 || (siz % 2 == 1 && np == 1)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
}