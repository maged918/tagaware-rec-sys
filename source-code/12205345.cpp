//Language: GNU C++11


#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//using namespace __gnu_pbds;
using namespace std;

//#pragma comment(linker, "/STACK:16777216")

#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define umap unordered_map
#define double long double
#define mod 1000000007
//template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;

vector<pii> v1;
ll dp[2010][2];
ll f[400001];
ll invf[400001];

ll power(ll b,ll e){
    if(e==0){
        return 1LL;
    }
    else if(e==1){
        return b;
    }
    else{
        ll p=power(b,e/2);

        if(e%2==0){
            return (p*p)%mod;
        }
        else{
            p=(p*p)%mod;
            p=(p*b)%mod;
            return p;
        }
    }
}

bool cmp(const pii a,const pii b){
    if(a.x!=b.x){
        return a.x<b.x;
    }
    else{
        return a.y>b.y;
    }
}

ll factor(int i,int j){
    ll answer1=0;
    answer1=f[v1[i].x-v1[j].x+v1[i].y-v1[j].y];
    //printf("(%d,%d)->(%d,%d)->%d,%d,%d\n",v1[i].x,v1[i].y,v1[j].x,v1[j].y,v1[i].x-v1[j].x-v1[i].y+v1[j].y,v1[i].x-v1[j].x,v1[j].y-v1[i].y);
    answer1=(answer1*invf[(v1[i].x-v1[j].x)])%mod;
    answer1=(answer1*invf[(v1[i].y-v1[j].y)])%mod;
    return answer1;
}

void preprocess(){
    f[0]=1LL;

    For(i,1,400001){
        f[i]=(f[i-1]*i)%mod;
    }

    invf[400000]=power(f[400000],mod-2);

    rof(i,399999,-1){
        invf[i]=(invf[i+1]*(i+1))%mod;
        //printf("%lld ",invf[i]);
    }

    return ;
}

int main(){

    preprocess();

    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);

    //printf("%lld\n",f[5]);

    For(i,0,n){
        int x,y;
        scanf("%d%d",&x,&y);
        v1.pb(mp(x,y));
    }

    v1.pb(mp(1,1));
    v1.pb(mp(h,w));

    sort(all(v1));

    /*rep(t1,v1){
        printf("(%d,%d) ",t1.x,t1.y);
    }*/

    //assert(v1[0].x==0 && v1[0].y==h);
    //assert(v1[v1.size()-1].x==w && v1[v1.size()-1].y==0);

    dp[0][1]=1;

    For(i,0,v1.size()){
        For(j,i+1,v1.size()){
            if(v1[i].x<=v1[j].x && v1[i].y<=v1[j].y && i!=j){
                dp[j][0]=(dp[j][0]+(dp[i][1]*factor(j,i))%mod)%mod;
                dp[j][1]=(dp[j][1]+(dp[i][0]*factor(j,i))%mod)%mod;
                //printf("%lld->(%d,%d)\n",factor(i,j),i,j);
            }
        }
        //printf("%d->(%lld,%lld)\n",i,dp[i][0],dp[i][1]);
    }

    ll answer1=0;
    answer1=((dp[v1.size()-1][0]-dp[v1.size()-1][1])%mod+mod)%mod;
    printf("%lld\n",answer1);
return 0;}