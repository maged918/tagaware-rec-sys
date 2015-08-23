//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;

///==============[ Definings Here ]========================

#define sc              scanf
#define pr              printf
#define mx              100009          //====[10^6]====
#define PI              acos(-1)
#define pb              push_back
#define ll              long long
#define NN              100000000        //===[10^8]====
#define pll             pair<ll,ll>

#define readInt(a)      sc("%d",&a)
#define readChar(a)     sc("%c",&a)
#define readString(a)   sc("%s",&a)
#define readLong(a)     sc("%lld",&a)

#define FOR(i,a,b)      for(i=a;i<=b;i++)
#define ROF(i,a,b)      for(i=a;i>=b;i--)
#define readLong2(a,b)  sc("%lld %lld",&a,&b)


///==============[ Global Variables & Declared Functions Here ]================
int arr[mx],cnt[mx],f[mx];

///=====================================[ Main ]===========================================
int main()
{
    int n,i,h;
    vector<int>v;
    cin>>n;
    FOR(i,1,n){
        cin>>arr[i];
        f[arr[i]]=1;
    }
    FOR(i,1,n){
        if(f[i]==0) v.pb(i);
    }
    int ind=0;
    FOR(i,1,n){
        if(arr[i]>=1 and arr[i]<=n and cnt[arr[i]]==0)  cnt[arr[i]]=1;
        else{
            arr[i]=v[ind];
            ind++;
        }
    }
    FOR(i,1,n){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
