//Language: GNU C++


//INAIS
#include<bits/stdc++.h>
using namespace std;
#define sz(a) ((int)a.size())
#define forv1(i,a) for(int i=0;i<sz(a);i++)
#define forv2(i,a) for(int i=sz(a)-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define dbg(x) printf("HERE COMES THE PACKAGE %d\n",x)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define refINF 100000
#define INF 0x7FFFFFFF
#define PI 3.1415926535897932384626433832795
#define SET(a,val) memset(a,val,sizeof(a))
#define eps 1e-9


#define in(a,x,y) (a>=x && a<=y)
#define out(a,x,y) (!in(a,x,y))


#define eq(a,b) (fabs(a-b)<eps)
#define less(a,b) (a+eps<b)
#define great(a,b) (a>b+eps)


#define uu first
#define vv second
#define ll long long
#define ld long double
#define ull unsigned long long
#define lld I64D

#define pii pair<int,int>
#define pll pair<ll,ll>

#define sI(a) scanf("%d",&a)
#define sII(a,b) scanf("%d %d",&a,&b)
#define sL(a) scanf("%lld",&a)
#define sLL(a,b) scanf("%lld %lld",&a,&b)

#define MAX
#define MOD

//int dx[]={-1,-1,-1,0,0,1,1,1}; int dy[]={-1,0,1,-1,1,-1,0,1}; // 8 direction
//int dx[]={-1,1,0,0}; int dy[]={0,0,-1,1}; // 4 direction
//int dx[] = {-1,-1,0,0,1,1}; int dy[] = {-1,0,-1,1,0,1}; // hexagonal direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1}; // Knight Direction
//int gcd(int a, int b){return b==0?a:gcd(b,a%b);}
//int lcm(int a, int b){return (int)a*(b/gcd(a,b));}



int main()
{
    //READ("input.txt");
    ll n,min1,max1,min2,max2,min3,max3;
    cin>>n;
    cin>>min1>>max1;
    cin>>min2>>max2;
    cin>>min3>>max3;
    ll a1,a2,a3;
    a1=min1,a2=min2,a3=min3;
    n=n-min1-min2-min3;
    //cout<<n<<endl;
    if(n==0)return cout<<a1<<" "<<a2<<" "<<a3<<endl,0;
    else{
        while(n>0&&a1<max1){
            a1++;n--;
        }
        while(n>0&&a2<max2){
            n--;
            a2++;
        }
        while(n>0&&a3<max3){
            n--;
            a3++;
        }
        

        cout<<a1<<" "<<a2<<" "<<a3<<endl;



    }




return 0;

}


