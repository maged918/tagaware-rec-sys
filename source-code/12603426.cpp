//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ULL unsigned long long
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define LL long long
#define MAXN 500010
#define eps 1e-10

using namespace std;

int dep[MAXN];
vector <int> tree[MAXN];
int vis[MAXN];
char s[MAXN];
vector <int> q[MAXN][30];
int cnt;
int out[MAXN];

int dfs(int root, int dis){
    dep[root] = ++cnt;
//    printf("%d %d\n", root, cnt);
//    printf("dep %d char %d %d\n", dis, s[root] - 'a', cnt);
    q[dis][s[root] - 'a'].push_back(cnt);
    vis[root] = 1;
    for(int i = 0; i < tree[root].size(); i++){
        if(vis[tree[root][i]] == 0){
            dfs(tree[root][i], dis+1);
        }
    }
    out[root] = cnt;
//    printf("%d %d\n", root, cnt);
}

int main (){
    int n, m;
    cnt = 0;
    scanf("%d%d", &n, &m);
    for(int i = 2; i <= n; i++){
        int x;
        scanf("%d", &x);
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
    scanf("%s", s+1);
    dfs(1, 1);
    while(m--){
        int root, depth;
        scanf("%d%d", &root, &depth);
        int sum = 0;
        int in = dep[root];
        int ou = out[root];
//        printf("in %d  out %d\n", in, ou);
        for(int i = 0; i < 26; i++){
            int l = lower_bound(q[depth][i].begin(), q[depth][i].end(), in) - q[depth][i].begin();
            int r = upper_bound(q[depth][i].begin(), q[depth][i].end(), ou) - q[depth][i].begin();
//            printf("%d %d...........\n", l, r);
            int num = r - l;
            if(num & 1)
                sum++;
            if(sum >= 2)
                break;
        }
        if(sum < 2)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
