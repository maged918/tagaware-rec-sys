//Language: GNU C++


#include<vector>
#include<cstring>
#include<algorithm>
#include<stdio.h>
#include<climits>
#include<set>
#include<fstream>
#include<cmath>
#include<bitset>
#include<map>
#include<stack>
#include<fstream>
#include<iostream>
#include<queue>
#include<assert.h>
#define test(t) while(t--)
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)

#define p(n) printf("%lld\n",n)
#define rep(i,a,n) for(i=a;i<=n;i++)
#define vi vector<int>
#define vii vector< vector<int> >
#define vpii vector< pair<int,int> >
#define mii map<int,int>

#define pb push_back
#define inf 1000000000LL
#define mp make_pair

#define N 500004
#define LN 20
//#define inf 100000000
#define ll  long long
using namespace std;



int depth[N] ;
vector<int>adj[N];
vector<int>hei[N];
vector<int>cum[N][26];
pair<int,int>inout[N];
string col ;


int dfs_time ;
int maxh = 0;
void dfs(int curr,int prev,int dep){
 dfs_time++;
 depth[curr]=dep;
 hei[dep].pb(curr);
 int sy = (int)col[curr-1]-97;
 cum[dep][sy].pb(hei[dep].size()-1);
 inout[curr].first = dfs_time ;
 for(int i=0;i<adj[curr].size();++i)
     dfs(adj[curr][i],curr,dep+1);

  inout[curr].second = dfs_time ;
}



int calc1(int ht,int l,int r){

   int odd = 0;
   int i,j;
   for(i=0;i<26;++i){

       int ct = 0;
       int lt = -1 , rt = - 1;
       int lo = 0;
       int hi = cum[ht][i].size()-1;
       while(lo<=hi){
          int mi = (lo+hi)/2;
          if(cum[ht][i][mi]>=l && cum[ht][i][mi]<=r){
               lt = mi ;
               hi = mi - 1;
          }
          else if(cum[ht][i][mi]<l)
            lo = mi + 1;
          else
             hi = mi - 1;
       }
       if(lt==-1)
          continue;
       lo = lt;
       hi = cum[ht][i].size()-1;
       while(lo<=hi){
          int mi = (lo+hi)/2;
          if(cum[ht][i][mi]>=l && cum[ht][i][mi]<=r){
               rt = mi ;
               lo = mi + 1;
          }
          else if(cum[ht][i][mi]<l)
            lo = mi + 1;
          else
             hi = mi - 1;
       }


            ct = (rt-lt+1);
       if(ct&1)
          odd++;
       if(odd==2)
            return odd ;
   }
   return odd ;
}



bool calc2(int ht,int parent){

    if(depth[parent]>=ht)
        return 1;

    int lr = -1 , rr = -1;
    int lo = 0;
    int hi = hei[ht].size()-1;
    int upper = hi ;
    while(lo<=hi){
      int mi = (lo+hi)/2;
       int node = hei[ht][mi];
      if((inout[node].first>=inout[parent].first) && (inout[node].second<=inout[parent].second)){
         lr = mi ;
         hi = mi - 1;
      }
      else if(inout[node].first<inout[parent].first)
         lo = mi + 1;
      else{
         hi = mi - 1;
         upper = hi ;
      }
    }

    if(lr==-1)
        return 1;

    lo = lr;
    hi = upper;
    while(lo<=hi){

      int mi = (lo+hi)/2;
      int node = hei[ht][mi];

      if((inout[node].first>=inout[parent].first) && (inout[node].second<=inout[parent].second)){
         rr = mi ;
         lo = mi + 1;
      }
      else
         hi = mi - 1;
    }



      int odd = calc1(ht,lr,rr);
      if(odd==0||odd==1)
        return 1;
      else
        return 0;

}

int main(){

    int n,m,par,i,parent,height,j;
    dfs_time = 0;
    cin>>n>>m;
    for(i=2;i<=n;++i){
       scanf("%d",&par);
       adj[par].pb(i);
    }
    cin>>col;


     dfs(1,-1,1);

    for(i=0;i<m;++i){
       scanf("%d%d",&parent,&height);

       if(calc2(height,parent))
           printf("Yes\n");
        else
           printf("No\n");
    }

}
