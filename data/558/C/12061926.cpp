//Language: GNU C++


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
using namespace std;

typedef long long int ll;
typedef pair<int, int > pii;
typedef pair<long long, long long> pll;

#define MOD 1000000007
#define pb push_back

ll vis[100005], steps[100005], cnt[100005];

void solve()
{
    int n;
    cin>>n;
    ll x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        queue<pll> q;
        q.push(pll(x, 0));
        while(!q.empty())
        {
            ll num, step;
            num = q.front().first;
            step = q.front().second;
            q.pop();
            if(num > 100002)
                continue;
            if(vis[num] == i)
                continue;

            vis[num] = i;
            steps[num] += step;
            cnt[num]++;

            q.push(pll((ll)2 * num, step + 1));
            q.push(pll((ll)num/2, step + 1));
        }
    }
    ll res = 100000000000000000;
    for(int i=0;i<=100000;i++)
    {
        if(cnt[i] == n)
        {
            if(steps[i] < res)
                res = steps[i];
        }
    }
    cout<<res<<"\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    //cin>>t;
    t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}
