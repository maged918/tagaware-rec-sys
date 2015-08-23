//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
#define len(val) static_cast<long long>(val.size())
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K, A; cin >> N >> K >> A;
    int M; cin >> M;
    int S[M];
    for(int i=0; i<M; i++){
        cin >> S[i]; S[i]--;
    }
    int low = 0, high = M+1;
    while(high-low > 1){
        //cout << low << " " << high << "---------" << endl;
        int mid = (low+high)/2;
        bool ok = false;
        int imos[N];
        bool used[N];
        memset(used, false, sizeof(used));
        memset(imos, 0, sizeof(imos));
        for(int i=0; i<mid; i++){
            used[S[i]] = true;
            imos[S[i]] = 1;
        }
        for(int i=1; i<N; i++){
            imos[i] += imos[i-1];
        }
        int cnt = K;
        int now = 0;
        while(cnt > 0 && now+A-1 < N){
            //cout << cnt << " " << now << endl;
            if(used[now]){
                now++;
                continue;
            }
            if(imos[now] != imos[now+A-1]){
                now++;
                continue;
            }
            cnt--;
            now = now+A+1;
        }
        if(cnt == 0 && mid == M){
            cout << -1 << endl;
            return 0;
        }
        if(cnt == 0) ok = true;
        if(ok){
            low = mid;
        }else{
            high = mid;
        }
    }
    cout << low+1 << endl;
}
