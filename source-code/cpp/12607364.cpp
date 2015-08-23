//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> ii;

ll S[71][71][36][36];
bool check[71][71][36][36], F[71][71][5], xxx;
int gtraicung[71][5], gphaicung[71][5];
int n, k;

bool ok(int L, int R, int type) {
    if (type==0) {
        if (L <= 2) return false;
        if (gtraicung[L-1][1] != 0)
            if (gtraicung[L-1][1] < L || gphaicung[L-1][1] > R) return false;
        if (gtraicung[L-1][0] != 0)
            if (F[L-1][L-2][0]==false) return false;
        if (gtraicung[L-1][3] != 0)
            if (gphaicung[L-1][3] > R || gtraicung[L-1][3] < L-2) return false;
        ///////////////
        if (gtraicung[L-2][0] != 0)
            if (F[L-2][L-1][0]==false) return false;
        if (gtraicung[L-2][1] != 0)
            if (gtraicung[L-2][1] < L || gphaicung[L-2][1] > R) return false;
        if (gtraicung[L-2][3] != 0)
            if (gphaicung[L-2][3] > R || gtraicung[L-2][3] < L-2) return false;
    }
    else if (type==1) {
        if (L==1 || R == 2*n) return false;
        if (gtraicung[L-1][0] != 0)
            if (F[L-1][R+1][0]==false) return false;
        if (gtraicung[L-1][1] != 0)
            if (gtraicung[L-1][1] < L || gphaicung[L-1][1] > R) return false;
        if (gtraicung[L-1][3] != 0)
            if (gtraicung[L-1][3] < L-1 || gphaicung[L-1][3] > R+1) return false;
        /////////////
        if (gtraicung[R+1][0] != 0)
            if (F[R+1][L-1][0]==false) return false;
        if (gtraicung[R+1][1] != 0)
            if (gtraicung[R+1][1] < L || gphaicung[R+1][1] > R) return false;
        if (gtraicung[R+1][3] != 0)
            if (gtraicung[R+1][3] < L-1 || gphaicung[R+1][3] > R+1) return false;
    }
    else {
        if (R > 2*n-2) return false;
        if (gtraicung[R+1][1] != 0)
            if (gtraicung[R+1][1] < L || gphaicung[R+1][1] > R) return false;
        if (gtraicung[R+1][0] != 0)
            if (F[R+1][R+2][0]==false) return false;
        if (gtraicung[R+1][3] != 0)
            if (gtraicung[R+1][3] < L || gphaicung[R+1][3] > R+2) return false;
        ////////////////////
        if (gtraicung[R+2][0] != 0)
            if (F[R+2][R+1][0]==false) return false;
        if (gtraicung[R+2][1] != 0)
            if (gtraicung[R+2][1] < L || gphaicung[R+2][1] > R) return false;
        if (gtraicung[R+2][3] != 0)
            if (gtraicung[R+2][3] < L || gphaicung[R+2][3] > R+2) return false;
    }
    return true;
}

ll dp(int i, int j, int k, int l) {
    if (i==1 && j==2*n) return 1;
    if (check[i][j][k][l]) return S[i][j][k][l];
    check[i][j][k][l] = true;
    int p = min(k,l)-1;
    if (ok(i,j,0)) S[i][j][k][l] += dp(i-2,j,p,l);
    if (ok(i,j,1)) S[i][j][k][l] += dp(i-1,j+1,p,p);
    if (ok(i,j,2)) S[i][j][k][l] += dp(i,j+2,k,p);
    return S[i][j][k][l];
}

void init() {
    for (int i = 1; i <= 2*n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= 2*n; ++j) {
            cnt += F[i][j][0];
            if (F[i][j][0]) gphaicung[i][0] = j;
            if (F[i][j][1]) gphaicung[i][1] = j;
            if (F[i][j][3]) gphaicung[i][3] = j;
        }
        for (int j = 2*n; j >= 1; --j) {
            if (F[i][j][0]) gtraicung[i][0] = j;
            if (F[i][j][1]) gtraicung[i][1] = j;
            if (F[i][j][3]) gtraicung[i][3] = j;
        }
        if (cnt > 1) xxx = true;
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    scanf("%d%d\n",&n,&k);
    for (int i = 1; i <= k; ++i) {
        int u, v; char c[5];
        scanf("%d %s %d\n",&u,c,&v);
        int len = strlen(c);
        if (len==1) {
            if (u==v) {
                if (c[0]=='=') continue;
                cout << 0 << endl;
                return 0;
            }
            if (c[0]=='=') F[u][v][0] = F[v][u][0] = true;
            else if (c[0]=='<') F[u][v][1] = F[v][u][2] = true;
            else if (c[0]=='>') F[u][v][2] = F[v][u][1] = true;
        }
        else {
            if (u==v) continue;
            if (c[0]=='<') F[u][v][3] = F[v][u][4] = true;
            else F[u][v][4] = F[v][u][3] = true;
        }
    }
    xxx = false;
    init();
    if (xxx) {
        cout << 0 << endl;
        return 0;
    }
    ll res = 0;
    for (int i = 1; i < 2*n; ++i) {
        if (gtraicung[i][1] != 0 || gtraicung[i+1][1] != 0) continue;
        if (gtraicung[i][0] != 0 && F[i][i+1][0]==false) continue;
        if (gtraicung[i][3] != 0 && (gtraicung[i][3] < i || gphaicung[i][3] > i+1)) continue;
        if (gtraicung[i+1][3] != 0 && (gtraicung[i+1][3] < i || gphaicung[i+1][3] > i+1)) continue;
        res += dp(i,i+1,n,n);
    }
    cout << res;
    return 0;
}
