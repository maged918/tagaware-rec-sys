//Language: GNU C++


/* Have courage and be kind*/
#include<bits/stdc++.h>
#include<stdlib.h> //system("pause");
using namespace std;
#define inf (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define all(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR0(i,n) for(int i = 0;i<n;i++)
#define FOR1(i,n) for(int i = 1;i<=n;i++)
#define ABS(x) ((x)<0?-(x):(x))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define pi ((double)2*acos(0.0))
#define PI acos(-1.0)
#define sq(x) ((x)*(x))
#define EPS 1e-9
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())//vector must be sorted
#define min3(a,b,c) min(a,min(b,c))
#define maxx3(a,b,c) maxx(a,maxx(b,c))
#define NUMDIGIT(x,y) (((int)(log10((x))/log10((y))))+1)
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define lol long long
#define ulol unsigned long long
#define pf printf
#define sf scanf
#define bin2dec(b,d) for(int i=0,d=0;b[i];d=(d<<1)|(b[i++]-48));
#define dec2bin(d,b) int nnn=d;while(nnn){if(nnn%2)b+="1";else b+="0";nnn>>=1;}reverse(ALL(b));
#define fast_add(x,y) while(y){typeof(x) carry = x & y;x=x^y;y=carry<<1;} //answer is x
#define sz 100000
#define mod 1000000007 //10^9+7

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month
///string monthArray[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
///string dayArray[]={"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};//Day
/// for(map<int,int>::iterator i=mp.begin();i!=mp.end();i++)cout<<i->first<<" "<<i->second<<endl;
/// vector< pair<string,string> > result;  result.push_back(make_pair(words[i].word, words[j].word));
///nCr[0][0]=1; for(int i=1;i<1002005;i++){ nCr[i][0]=1; for(int j=1;j<=i;j++) nCr[i][j]=nCr[i-1][j]+nCr[i-1][j-1];}


lol mod_v(lol num)
{
    if(num>=0)
      return(num%mod);
    else
     return(num%mod+mod)%mod;
}

lol fast_pow(lol b,lol p,lol md)
{
    lol r=1%md; // if mo==1 the r should be equal to 0
    while(p>0)
    {
        if(p%2==1)
          r=(r*b)%md;
        p=p/2;
        b=(b*b)%md;
    }
    return r;
}
int countBits(int n)
{
    int sum=0;
    while(n>0)
    {
        if(n & 1 == 1) sum++;
        n=n>>1;
    }
    return sum;
}


/********** Solution ***************/
struct point
{
    int oc=0,l=0,f=0;
};
point arr[1000006];
//bool cmp(point a, point b)
//{
//    if(arr[a].oc<arr[b].oc)
//     return arr[a].oc>arr[b].oc;
//    else
//     return true;
//}
int main()
{
    //READ("input.txt");
    int n,x,mx=0;
    sf("%d",&n);
    FOR1(i,n)
    {
        sf("%d",&x);
        mx=MAX(mx,x);
        if(arr[x].oc==0)
        {
            arr[x].oc++;
            arr[x].f=i;
            arr[x].l=i;
        }
        else
        {
            arr[x].oc++;
            arr[x].l=i;
        }
    }
     //sort(arr+1,arr+mx+1,cmp);
     int ans=0;
     int ri=0;
     int le=inf;
     for(int i=1;i<=mx;i++)
     {
         if(arr[i].oc>ans)
         {
             ans=arr[i].oc;
            ri=arr[i].l;
            le=arr[i].f;
         }
         else if(arr[i].oc==ans)
         {
             if(ri-le>arr[i].l-arr[i].f)
             {
                 ri=arr[i].l;
                 le=arr[i].f;
             }
         }
     }
//     for(int i=2;i<=mx;i++)
//     {
//         if(arr[i].oc==arr[i-1].oc)
//         {
//             ri=MAX(ri,arr[i].l);
//             le=MIN(le,arr[i].f);
//         }
//     }
     pf("%d %d\n",le,ri);
     return 0;
}

