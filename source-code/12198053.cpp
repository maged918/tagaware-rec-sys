//Language: GNU C++11


//Daniel Grzegorzewski
#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define ST first
#define ND second

using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef long long LL;

void init_ios()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
}

const int N = (int)1e5 + 10;

int n, a[N], ile[10*N], mx;
VI ind[10*N], yolo;
PII res;

int main()
{
    init_ios();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ile[a[i]]++;
        ind[a[i]].PB(i);
        mx = max(mx, ile[a[i]]);
    }
    for (int i = 1; i <= (int)1e6; ++i)
        if (ile[i] == mx)
            yolo.PB(i);
    for (int i = 0; i < yolo.size(); ++i)
        if (i == 0 || ind[yolo[i]].back() - ind[yolo[i]][0] < res.ND-res.ST)
            res = MP(ind[yolo[i]][0], ind[yolo[i]].back());
    cout<<res.ST<<" "<<res.ND<<"\n";
}

