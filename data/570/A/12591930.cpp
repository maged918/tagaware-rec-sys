//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define allR(v) v.rbegin(),v.rend()
#define V vector
#define IO cin.tie(0);std::ios::sync_with_stdio(false);
#define S string
#define pb push_back
#define pf push_front
#define set(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define sz size()
#define dist(x1,y1,x2,y2) (x1-x2)*(x1-x2) + ((y1-y2)*(y1-y2))
#define get cin>>
#define print cout<<
#define getArr(ar,n) for(int i=0;i<n;get ar[i++])
#define printArr(ar,n) for(int i=0;i<n;print ar[i++]<<' ')
#define OO 1e6
#define pii pair<int,int>
#define st first
#define nd second
#define file freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
int dx[] = { 1 , -1 , 0 , 0 };
int dy[] = { 0 , 0 , 1 , -1 };
const ll mod = 1000000007;
const lf pi = 3.1415926536;
//int u[100000+1];
int main(){
    IO //set(u,0);
    int n,m; get n>>m;
    V<int>ar(n+1,0); int maximum=0;
    for(int i=0;i<m;i++){
        int mx=-1,idx;
        for(int j=0;j<n;j++){
            int x ;get x;
            if(x>mx){
                mx = x;
                idx = j+1;
            }
        }
        ar[idx]++;
        maximum=max(maximum,ar[idx]);
    }
    for(int i=1;i<=n;i++){
        if(ar[i]==maximum){
            print i; return 0;
        }
    }
}
/*
*/
