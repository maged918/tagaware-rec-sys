//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define FOR(i,a,b) for(int i = (a), _b=(b); i<= _b; ++i)
#define FOD(i,a,b) for(int i = (a), _b=(b); i>= _b; --i)
#define REP(i,b) for(int i = 0, _b=(b); i< _b; ++i)
#define eeuler exp(1)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define Pi acos(-1.0)
#define Eps 1e-10
#define INF 1000000007
#define mod 1000000007
#define oo 1000000007
#define ED pair<ll,ll>
#define EG pair<ll,int>
#define EDGE pair<ED,int>
#define maxn 11000000000ll
#define maxe 1000111
#define maxv 10011
#define linf 1e16+5

int va[200111][26],vb[200111][26],n;
char A[200111];
char B[200111];

bool Cal(int x,int y,int u,int v){
//  cout << x << ' '<< y << ' '<< u << ' ' << v << endl;
    if((y-x+1)&1){
        REP(i,y-x+1)
            if(A[i+x]!=B[i+u])
                return false;
        return true;
    }else{
        REP(j,26)
            if( va[y+1][j]-va[x][j] != vb[v+1][j]-vb[u][j])
                return false;
        if(x==y) return true;
        int mid1 = (y+x)>>1;
        int mid2 = (u+v)>>1;
        if(Cal(x,mid1,u,mid2) && Cal(mid1+1,y,mid2+1,v)) return true;
        if(Cal(x,mid1,mid2+1,v) && Cal(mid1+1,y,u,mid2)) return true;
    }
}

int main(){
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    
    scanf("%s\n",&A);
    scanf("%s\n",&B);
    n = strlen(A);
    REP(i,n){
        va[i+1][A[i]-'a'] = 1;
        vb[i+1][B[i]-'a'] = 1;
        REP(j,26){
            va[i+1][j] += va[i][j];
            vb[i+1][j] += vb[i][j];
        }
    }
    if(Cal(0,n-1,0,n-1)) printf("YES");
    else printf("NO");
    return 0;
}


