//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (400000+10)
#define MAXQ (50000+10)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int n,q;

int l,r,v,_ans;
class Stree{
public:
    int mark[MAXN],tree[MAXN];
    Stree(){
        MEM(mark) MEM(tree) 
    }
    void pushdown(int o,int L,int R)
    {
        if (L<R) if (mark[o]) mark[Lson]=mark[Rson]=mark[o],mark[o]=0;
    }
    void maintain(int o,int L,int R)
    {
        if (mark[o]) tree[o]=(R-L+1)*(mark[o]-1);
        else if (L<R) tree[o]=tree[Lson]+tree[Rson];
    }
    void set(int o,int L,int R)
    {
        if (l<=L&&R<=r) {
            mark[o]=v;
            maintain(o,L,R);
            return;
        }
        pushdown(o,L,R);
        int M=(L+R)>>1;
        if (l<=M) set(Lson,L,M);else maintain(Lson,L,M);
        if (M<r) set(Rson,M+1,R);else maintain(Rson,M+1,R);
        maintain(o,L,R);
    }
    void get_sum(int o,int L,int R)
    {
                
        if (l<=L&&R<=r) 
        {
            _ans+=tree[o];
            return; 
        }
        if (mark[o]) {
            _ans+=(min(r,R)-max(L,l)+1)*(mark[o]-1);
            return;
        }
        
        int M=(L+R)>>1;
        if (l<=M) get_sum(Lson,L,M);
        if (M<r) get_sum(Rson,M+1,R);
    }
    
}S[26];
char s[MAXN];

int cnt[26]={0};

int main()
{
//  freopen("E.in","r",stdin);
//  freopen(".out","w",stdout);
    
    scanf("%d%d%s",&n,&q,s);
    Rep(i,n) {
        l=r=i+1,v=2;
        S[s[i]-'a'].set(1,1,n);
    }
    For(qcase,q)
    {
        int b;
        scanf("%d%d%d",&l,&r,&b);
        
        v=1;
        Rep(i,26) {
            _ans=0;
            S[i].get_sum(1,1,n);
            cnt[i]=_ans;
            S[i].set(1,1,n);
        }
        v=2;
        if (b) //increasing
        {
            Rep(i,26)
            {
                if (!cnt[i]) continue;
                r=l+cnt[i]-1; 
                S[i].set(1,1,n);
                l=r+1;
            } 
        } else {
            Rep(i,26)
            {
                if (!cnt[i]) continue;
                l=r-cnt[i]+1; 
                S[i].set(1,1,n);
                r=l-1;
            } 
            
        } 
        
    }
    For(i,n) 
    {
        Rep(j,26)
        {
            l=r=i;_ans=0;
            S[j].get_sum(1,1,n);
            if (_ans) {
                s[i-1]='a'+j;
                break;
            }
        }
    } 
    
    printf("%s\n",s);
    
    return 0;
}
