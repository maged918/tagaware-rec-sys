//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const int maxn = 508;
char g[maxn][maxn];

ll d[maxn][maxn];
ll tmp[maxn][maxn];
int n,m;

bool ok(int x1,int y1,int x2,int y2){
    if (x1<n && y1<m && x2>=0 && y2>=0 && g[x1][y1] == g[x2][y2])
        return true;
    return false;
}

void add(ll &x ,ll y){
    x += y;
    if (x>=MOD)
        x -= MOD;
}

void print(){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)
            cout << d[i][j] << " ";
        cout << endl;
    }
}

void input(){
    for (int i=0;i<n;i++)
        scanf("%s",g[i]);
    if (g[0][0]!=g[n-1][m-1]){
        puts("0");
        return ;
    }

    memset(d,0,sizeof(d));
    memset(tmp,0,sizeof(tmp));
    
    d[0][n-1] = 1;

    int s = n + m - 2;

    for (int step = 0; step < s/2;step++){
        for (int x0 = 0;x0 < n && step - x0 >=0;x0++){
            int y0 = step - x0;
            for (int x1 = 0;x1 < n && s - step - x1>=0 ;x1++){
                
                int y1 = s - step - x1;

                if (ok(x0+1,y0,x1-1,y1)){
                    add(tmp[x0+1][x1-1],d[x0][x1]);
                }
                if (ok(x0+1,y0,x1,y1-1)){
                    add(tmp[x0+1][x1],d[x0][x1]);
                }
                if (ok(x0,y0+1,x1-1,y1)){
                    add(tmp[x0][x1-1],d[x0][x1]);
                }
                if (ok(x0,y0+1,x1,y1-1)){
                    add(tmp[x0][x1],d[x0][x1]);
                }
            }
        }
        for (int i=0;i<500;i++)
            for (int j=0;j<500;j++){
                d[i][j] = tmp[i][j];
                tmp[i][j] = 0;
            }
    }
    if (n + m - 1 & 1){
        ll ans = 0;
        for (int i=0;i<n;i++){
            add(ans,d[i][i]);
        }
        printf("%I64d\n",ans);
    }else {
        ll ans = 0;
        s /= 2;
        for (int i=0;i<n;i++){
            if (s - i + 1 < m && g[i][s-i]==g[i][s-i+1])
                add(ans,d[i][i]);
            if (i + 1 < n && g[i][s-i] == g[i+1][s-i])
                add(ans,d[i][i+1]);
        }
        printf("%I64d\n",ans);
    }

}

int main(){
    //freopen("1.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF){
        input();
    }
    return 0;
}
