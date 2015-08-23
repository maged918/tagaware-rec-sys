//Language: GNU C++11


#include<bits/stdc++.h>
#define FRU freopen("out.txt","w",stdout)
#define FRO freopen("in.txt","r",stdin)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(ara,n) memset(ara,n,sizeof ara)
#define loop(i,j,n) for(i=j;i<n;i++)
#define rloop(i,j,n) for(i=n;i>=j;i--)
#define INF 2147483647
#define long long long
//const int row[]={-1, -1, -1,  0,  0,  1,  1,  1};  // Kings Move
//const int col[]={-1,  0,  1, -1,  1, -1,  0,  1};  // Kings Move
//const int row[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int col[]={-1,  1, -2,  2, -2,  2, -1,  1};  // Knights Move
//const int row[]={-1,0,0,1,0};
//const int col[]={0,-1,1,0,0};
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int lcm(int a,int b){return ((a*b)/gcd(a,b));}


using namespace std;

int main()
{
//FRO;
//FRU;
//std::ios_base::sync_with_stdio(false);
    int a,b,c,i,j,k,tc,t;
    int n,m,cnt=0;
    char s[300005];
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    for(i=0;i<n;i++)
    {
        //if(s[i]=='.')cnt++;
        if(i>0)
        {
            if(s[i]=='.'&& s[i-1]=='.')cnt++;
        }
    }
    //printf("!!!!!! %d\n",cnt);
    //cnt--;
    n--;
    char ch;
    for(i=0;i<m;i++)
    {
        scanf("%d %c",&a,&ch);
        a--;
        if(ch=='.')
        {
            if(a>0&& s[a-1]=='.'&& s[a]!='.')cnt++;
            if(a<n&& s[a+1]=='.'&& s[a]!='.')cnt++;
        }
        if(ch!='.')
        {
            if(a>0&& s[a-1]=='.'&& s[a]=='.')cnt--;
            if(a<n&& s[a+1]=='.'&& s[a]=='.')cnt--;
        }
        s[a]=ch;
        printf("%d\n",cnt);
    }

return 0;
}
