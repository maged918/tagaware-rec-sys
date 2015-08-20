//Language: GNU C++


/*****************
    Ashutosh Tiwari
    NIT PATNA
*****************/
#include<string>
#include<iostream>
#include<map>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<bitset>
#include<utility>
#include<cstring>
#include<climits>
#include<cassert>
#include<queue>
using namespace std;
#define LL long long int
#define mfor(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b)  for(int i=a;i<=b;i++)
#define RFOR(i,a,b)   for(int i=a;i>=b;i--)
#define snd(n) int (n); scanf("%d",&(n))
#define sd(n)  scanf("%d",&n)
#define sd2(n,m) scanf("%d %d",&(n),&(m))
#define snd2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define snd3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define ptd(x) printf("%d\n",(x))
#define ptl printf("\n");
#define OPEN freopen("in1.txt","r",stdin)
#define pb push_back
#define mp make_pair
#define IS_ODD( num ) ((num) & 1)
#define IS_EVEN( num ) (!IS_ODD( (num) ))
#define MEM(dest,val) memset(dest,val,sizeof(dest))
#define MOD 1000000007
#define NMAX 1001
typedef vector<int>vi;
typedef pair<int,int>ii;
typedef vector<ii>vii;
typedef vector<vii>tvi;//adjlist
typedef map<int,int>MAP;
typedef set<int>SET;
int main(){
    //OPEN;
    vii pos,neg;
    int negno=0,cnt=0,posno;
    snd(tc);
    mfor(ik,tc){
        snd2(c,p);
       // cout<<c<< " " <<p<<endl;
        if(c>0)pos.pb(mp(c,p));
        else {neg.pb(mp(c,p));negno++;}
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    reverse(neg.begin(),neg.end());
    posno=tc-negno;
    //cout<<posno<<" "<<negno<<endl;
    if(posno<negno){
        mfor(i,posno)cnt+=pos[i].second+neg[i].second;
        cnt+=neg[posno].second;
        ptd(cnt);

    }
    else if(negno<posno){
        mfor(i,negno)cnt+=pos[i].second+neg[i].second;
        cnt+=pos[negno].second;
        ptd(cnt);

    }
    else{
        mfor(i,negno)cnt+=pos[i].second+neg[i].second;
        ptd(cnt);

    }
    return 0;

}
