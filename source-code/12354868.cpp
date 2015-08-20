//Language: GNU C++11


#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define LET(x,a) __typeof(a) x(a)
#define tr(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define present(x,c) ((c).find(x) != (c).end())    //stl container find
#define cpresent(x,c) (find(all(c),x) != (c).end())       //standard library find
#define sorti(a) sort(a.begin(),a.end())
#define sortd(a) sort(a.rbegin(),a.rend())

#define MEM(a,b) memset(a,b,sizeof(a))
#define rep0(i,n) for(int i=0; i<(int)n;i++)
#define rep1(i,n) for(int i=1; i<=(int)n;i++)
#define rep(i,st,en) for(int i=(int)st; i<=(int)en;i++)
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)


using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main()
{
    long long n,arr[110000];
    cin>>n;
    rep0(i,n)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<arr[1]-arr[0]<<" "<<arr[n-1]-arr[0]<<"\n";
    for(int i=1;i<n-1;i++)
    {
        cout<<min(arr[i+1]-arr[i],arr[i]-arr[i-1])<<" "<<max(arr[n-1]-arr[i],arr[i]-arr[0])<<"\n";
    }
    cout<<arr[n-1]-arr[n-2]<<" "<<arr[n-1]-arr[0]<<"\n";
    return 0;
}
