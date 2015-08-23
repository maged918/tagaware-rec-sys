//Language: GNU C++


#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define f(i,a,b) for(int i =a; i <=b ; i++)
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define db(var) cout<<var<<" ";
#define gcd(a,b) __gcd(a,b)
#define p(A,a,b)  f(i,a,b) cout<<A[i]<<" ";
#define sj  cout<<"OK"<<endl;
#define ll long long int 
#define el cout<<endl;

#define MOD 1000000007
#define PI acos(-1.0)
#define e exp(1.0)
#define EPS 1e-9
using namespace std;

int ar[100005],moves[100005]={0},cnt[100005]={0},visited[100005]={0},maxm;
void bfs(int v,int a)
{
//  cout<<v<<" "<<a;el
             if(v==0)
             return ;
             visited[v]=1;
             cnt[v]++;
             moves[v]+=a;
            
                              if(visited[v/2]==0 && v/2<=maxm && v/2>0)bfs(v/2,a+1);
                               
                              if(visited[2*v]==0 && 2*v<=maxm && v*2>0) bfs(2*v,a+1);
                              
             visited[v]=0;
             return ;
}
             
int main() 
{
           ios :: sync_with_stdio(0);
           cin.tie(NULL);
           int n;
           cin>>n;
           f(i,0,n-1)
           {
                     cin>>ar[i];
                     if(maxm<ar[i])
                     maxm=ar[i];
           }
          
           f(i,0,n-1)
            bfs(ar[i],0);
           vector<int> v1;
           f(i,1,maxm)
           {
                     if(cnt[i]==n)
                     v1.pb(i);
           }
           ll minm=10000000000;
           for(int i=0;i<v1.size();i++)
           {
                             if(moves[v1[i]]<minm)
                             minm=moves[v1[i]];
           }
           cout<<minm;
    
  return 0;
}

