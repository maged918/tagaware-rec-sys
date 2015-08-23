//Language: GNU C++11


#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

#define FOR(i,a,b) for(int (i)=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define RANGE(vec) (vec).begin(),(vec).end()

using namespace std;


class Div2C {
public:
    // a[i] = 10101111100001 のような二進表現にすると operations は
    //
    // a[i] <<= 1
    // a[i] >>= 1
    //
    // なので取りうる遷移の状態は
    //
    // 10101111100000 や 1010000000 や 1010 など prefix+0...0 のような数字になる
    //
    // max{a[i]} よりも大きくなるように a[i]*=2 する必要はないので max{a[i]} のビット長を m
    // とすると一般の a[i] の遷移は最大
    //
    // (1+2+...+m)+1 = m(m+1)/2+1 となる(+1 は自分自身への遷移)
    //
    // なぜなら
    //
    // (1111111 -> 1000000, 1100000, 1110000, ...) のように
    // bits = ((1<<m)-1) から
    // bits -> { (bits>>k)<<k | 0<=k<=m-1 } と m 個の遷移が考えられるため。
    //
    // よって計算量は O(n*m^2) 程度なので全探索でやる
    //
    // O(n*m^2+maxA)
    void solve(void) {
            int N;
            cin>>N;
            vector<int> a(N,0);
            int maxA = 0;
            REP(i, N)
            {
                cin>>a[i];
                maxA = max(a[i], maxA);
            }

            vector<int> cnt(maxA+1,0);  // cnt[x] := a[i]-> x に遷移できたものの数
            vector<int> step(maxA+1,0); // step[x] := a[i]->x に遷移したときのstep総数

            // bfs で取りうる遷移の最小ステップを求める
            // O(N*m^2)
            REP(i, N)
            {
                queue<pair<int,int>>  que;
                vector<bool> vis(maxA+1,false);
                que.emplace(a[i], 0);
                vis[a[i]] = true;
                ++cnt[a[i]];
                while (!que.empty())
                {
                    int x, s;
                    tie(x,s) = que.front();
                    que.pop();
                    if (x/2 > 0 && !vis[x/2])
                    {
                        vis[x/2] = true;
                        ++cnt[x/2];
                        step[x/2] += (s+1);
                        que.emplace(x/2, s+1);
                    }
                    if (x*2 <= maxA && !vis[x*2])
                    {
                        vis[x*2] = true;
                        ++cnt[x*2];
                        step[x*2] += (s+1);
                        que.emplace(x*2, s+1);
                    }
                }
            }
            // 結果の参照
            // O(maxA)
            int minStep = (1<<30);
            FOR(x, 1, maxA+1)
            {
                if (cnt[x] != N) // 遷移が到達できないケースは飛ばす
                    continue;
                minStep = min(minStep, step[x]);
            }
            cout<<minStep<<endl;
    }
};

#if 1
int main(int argc, char *argv[])
{
        ios::sync_with_stdio(false);
        auto obj = new Div2C();
        obj->solve();
        delete obj;
        return 0;
}
#endif
