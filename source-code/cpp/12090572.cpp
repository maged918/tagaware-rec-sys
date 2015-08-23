//Language: GNU C++11


#include<bits/stdc++.h>
#define P(x,y) make_pair(x,y)
using namespace std;
const long long MXL=59;
void work(vector < pair < long long , long long > > &v){
    if(v.empty()) return;
    sort( v.begin() , v.end() );
    vector < pair < long long , long long > > v2;
    long long sz=v.size();
    v2.push_back(v[0]);
    for(long long j=1;j<sz;j++){
        if(v[j].first > v2.back().second)
            v2.push_back(v[j]);
        else v2.back().second=max(v2.back().second , v[j].second);
    }
    v.swap(v2);
 //   for(int j=0;j<v.size();j++) printf("(%lld,%lld)  " , v[j].first , v[j].second);
    //puts("");
}
bool check(vector < pair < long long , long long > > &v  , long long X){
    long long sz=v.size() , st=0 , en=sz-1 , last=-1 , mid;
    while(st<=en){
        mid=(st+en)/2;
        if(v[mid].first<=X){
            last=mid;
            st=mid+1;
        }
        else en=mid-1;
    }
    if(last==-1) return true;
   // cout<<X<<' '<<sz<<' '<<last<<' '<<v[mid].first<<' '<<v[mid].second<<endl;
    return v[last].second<X;
}
vector < pair < long long  , long long >  > v[MXL];
long long h , Q  , sol , node;
void dfs(long long depth , long long x){
    if(!check(v[depth] , x)) {
      //  cout<<depth<<' '<<x<<endl;
        return;
    }
    if(depth==h){
        sol++;
        node=x;
        if(sol>1){
            puts("Data not sufficient!");
            exit(0);
        }
        return;
    }
    dfs(depth+1 , x*2);
    dfs(depth+1 , x*2+1);
}
void upd(long long L , long long a , long long b){
    while(L>0){
        if(a>b || !a || !b) break;
        v[L--].push_back(P(a,b));
        //cout<<L+1<<' '<<a<<' '<<b<<endl;
        if(a%2) a++;
        if(b%2==0) b--;
        a/=2; b/=2;
    //    puts("");
    }
}
int main(){
    cin>>h>>Q;
    while(Q--){
        long long L , a , b , c;
        cin>>L>>a>>b>>c;
        if(c==0) upd(L , a , b);
        else{
            long long l=(1ll<<(L-1)) , r=a-1;
            if(l<=r) upd(L , l , r);
            l=b+1 , r=(1ll<<L)-1;
            if(l<=r) upd(L , l, r);
        }
    }
    for(long long j=1;j<=h;j++) work(v[j]);
    dfs(1,1);
    if(sol==0) puts("Game cheated!");
    else cout<<node<<endl;

}
