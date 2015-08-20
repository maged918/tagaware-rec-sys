//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll inp[100005];
ll dist[100005];
ll cnt[100005];

int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> inp[i];
    for(int i=1;i<n;i++) dist[i] = llabs(inp[i]-inp[i+1]);
    for(int i=1;i<n;i++) cnt[i] = cnt[i-1] + dist[i];
    cout << dist[1] << " " << cnt[n-1] << '\n';
    for(int i=2;i<n;i++){
        ll mn = min(dist[i-1],dist[i]);
        ll mx = max(cnt[i-1],cnt[n-1]-cnt[i-1]);
        cout << mn << " " << mx << '\n';
    }
    cout << dist[n-1] << " " << cnt[n-1] << '\n';
    return 0;
}
