//Language: GNU C++11


/*
 * This is my code,
 * my code is amazing...
 */
//Template v2.0
//iostream is too mainstream
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<iomanip>
//clibraries
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
//defines
#define ll int
#define lld long double
#define pll pair<ll,ll>
#define pld pair<lld,lld>
#define vll vector<ll>
#define vvll vector<vll>
#define INF 1000000000000000047
const char en='\n';
#define debug(x){cerr<<x<<en;}
#define prime 47
#define lprime 1000000000000000009
#define lldmin LDBL_MIN
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
using namespace std;

vvll V(600000);
vll ZZ(600000,0);
vector<pll>R(600000);
vector<vector<pair<ll,ll>>>Z(600000);

void insert(int h, int p, int c){
    ll X;
    if(Z[h].size()==0){
        X=0;
        Z[h].PB(MP(-1,X));
    }
    else
        X=Z[h].back().second;
    X^=1<<c;
    Z[h].PB(MP(p,X));
}


int init(int c, int f, int p, int h){

    insert(h,p,ZZ[c]);
    int pp=p+1;
    for(int i=0; i<V[c].size(); i++){
        if(V[c][i]!=f)
            pp=init(V[c][i],c,pp,h+1);
    }
    R[c]=MP(p,pp);
    return pp;
}


int bs(int h, int p){
    if(Z[h].size()==0)
        Z[h].PB(MP(-1,0));
    int z=0,k=Z[h].size();
    while(z<k-1){
        int mid=(z+k)/2;
        if(Z[h][mid].ff<p)
            z=mid;
        else
            k=mid;
    }
    return z;
}





int main(){
	ios::sync_with_stdio(false);

        int n,m;
        cin>>n>>m;

        for(int i=2; i<=n; i++){
            int t;
            cin>>t;
            V[t].PB(i);
            V[i].PB(t);
        }
        for(int i=1; i<=n; i++){
            char c;
            cin>>c;
            c-='a';
            ZZ[i]=c;
        }

        init(1,-1,1,1);
/*
        for(int i=1; i<=n; i++)
            cout<<R[i].ff<<" "<<R[i].ss<<en;
*/
        while(m--){
            int v, h;
            cin>>v>>h;
            int a=R[v].ff,b=R[v].ss;
            
            //auto it=Z[h].lower_bound(b);
            //it--;
            ll x2=Z[h][bs(h,b)].ss;
            //it=Z[h].lower_bound(a);
            //it--;
            ll x1=Z[h][bs(h,a)].ss;
            
            int p=0;
            ll x=x2^x1;
            while(x){
                if(x%2==1)
                    p++;
                x/=2;
            }
            if(p>1)
                puts("No");
            else puts("Yes");
        }


}
