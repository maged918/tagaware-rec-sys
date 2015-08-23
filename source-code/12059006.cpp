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
#define ll long long
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



int main(){
	ios::sync_with_stdio(false);

        ll h,q;
        cin>>h>>q;

        vector<pair<pll,ll>>V;

        while(q--){
            ll i,l,r,ans;
            cin>>i>>l>>r>>ans;
            for(ll j=i; j<h; j++){
                l*=2;
                r*=2;
                r+=1;
            }
            //cout<<l<<" "<<r<<en;
            V.PB(MP(MP(l,r),ans));
        }


            ll l=1LL<<(h-1),r=(1LL<<(h))-1;
            for(ll j=0; j<V.size(); j++){
                if(V[j].ss==1){
                    l=max(l,V[j].ff.ff);
                }
            }
            for(ll j=0; j<V.size(); j++){
                if(V[j].ss==1){
                    r=min(r,V[j].ff.ss);
                }
            }

            //cout<<"xxx "<<l<<" "<<r<<en;
            if(l>r){
                cout<<"Game cheated!"<<en;
                return 0;
            }

            //cout<<"som tu"<<endl;
            map<ll,ll>M;
            M[l]=r;

            sort(V.begin(),V.end());
            for(int i=0; i<V.size(); i++){
                if(V[i].ss==0){
                    ll le=V[i].ff.ff;
                    ll ri=V[i].ff.ss;
                    //cout<<"le="<<le<<" ri="<<ri<<en; 
                    while(M.lower_bound(le)!=M.end() && M.lower_bound(le)->first<=ri){
                        auto it=M.lower_bound(le);
                        auto x=*it;
                        M.erase(it);
                        if(x.second>ri){
                            M[ri+1]=x.second;
                        }

                    }
                    auto it=M.lower_bound(le);
                    if(it!=M.begin()){
                        it--;
                        if(it->second>=le){
                            auto x=*it;
                            it->second=le-1;
                            if(x.second>ri)
                            M[ri+1]=x.second;

                        }

                    }

                }


            }
/*
            cout<<en;
            for(auto it=M.begin(); it!=M.end(); it++)
                cout<<it->first<<" "<<it->second<<en;

cout<<en;
*/
  //          cout<<"aj tu som"<<endl;
            if(M.size()==1 && M.begin()->first==M.begin()->second){
                cout<<M.begin()->first<<en;
                return 0;
            }
            if(M.size()>0){
                cout<<"Data not sufficient!"<<en;
                return 0;
            }

            cout<<"Game cheated!"<<en;
}
