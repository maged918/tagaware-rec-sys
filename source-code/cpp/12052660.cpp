//Language: GNU C++11


#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
#define SZ(x) ( (int) (x).size() )
#define CNT(s, x) ( (s).find(x) != (s).end() )
#define ALL(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << " = " << x << endl;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
// const int INF = 1e9;
const int MAXN = 1e5 + 10;
const int SIGMA = 26;

int N, Q;

char S[MAXN];

int cnt[SIGMA];

struct segment_tree
{
    int lz[MAXN * 4];
    int C[MAXN * 4];

    segment_tree()
    {
        memset(lz, -1, sizeof lz);
        memset(C, 0, sizeof C);
    }

    void push(int cur, int L, int R)
    {
        if(lz[cur] == -1)
            return;
        C[cur] = (R - L + 1) * lz[cur];
        if(L < R)
        {
            lz[cur * 2 + 0] = lz[cur];
            lz[cur * 2 + 1] = lz[cur];
        }
        lz[cur] = -1;
    }

    void update(int cur, int L, int R, int i, int j, int k)
    {
        push(cur, L, R);
        if(j < L || R < i) return;
        if(i <= L && R <= j)
        {
            lz[cur] = k;
            push(cur, L, R);
        }
        else
        {
            int M = (L + R) / 2;
            update(cur * 2, L, M, i, j, k);
            update(cur * 2 + 1, M + 1, R, i, j, k);
            C[cur] = C[cur * 2] + C[cur * 2 + 1];
        }
    }

    int query(int cur, int L, int R, int i, int j)
    {
        if(j < L || R < i) return 0;
        push(cur, L, R);
        if(i <= L && R <= j)
        {
            return C[cur];
        }
        else
        {
            int M = (L + R) / 2;
            return 
            query(cur * 2, L, M, i, j) + 
            query(cur * 2 + 1, M + 1, R, i, j);
        }
    }

    void update(int i, int j, int k)
    {
        if(i <= j)
            update(1, 1, N, i, j, k);
    }

    int query(int i, int j)
    {
        return query(1, 1, N, i, j);
    }
} tree[SIGMA];

int main()
{
    scanf("%d%d%s", &N, &Q, S + 1);

    for(int i = 1; i <= N; i++)
        tree[S[i] - 'a'].update(i, i, 1);

    while(Q--)
    {
        int i, j, k;
        scanf("%d%d%d", &i, &j, &k);
        
        for(int l = 0; l < SIGMA; l++)
        {
            cnt[l] = tree[l].query(i, j);
            tree[l].update(i, j, 0);
        }

        if(k == 1)
        {
            for(int l = 0, s = 0; l < SIGMA; l++)
            {
                tree[l].update(i + s, i + s + cnt[l] - 1, 1);
                s += cnt[l];
            }
        }
        else
        {
            for(int l = SIGMA - 1, s = 0; l >= 0; l--)
            {
                tree[l].update(i + s, i + s + cnt[l] - 1, 1);
                s += cnt[l];
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < SIGMA; j++)
            if(tree[j].query(i, i))
            {
                printf("%c", j + 'a');
                break;
            }
    }

    puts("");

    return 0;
}
