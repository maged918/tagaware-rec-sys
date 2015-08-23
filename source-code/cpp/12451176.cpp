//Language: GNU C++


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<cstdlib>
#pragma comment(linker, "/STACK:102400000,102400000")
#define root 1, n, 1
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1
#define intxt  freopen("in.txt","r",stdin);
#define outtxt freopen("out.txt","w",stdout);
#define _LL __int64
#define LL long long
#define pi acos(-1.0)
#define PB(a) push_back(a)
#define MP(a,b) make_pair(a,b)
#define BG begin()
#define ED end()
#define IS(a) insert(a)
#define SZ size()
#define clr(a,b)  memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define Mod  1e9+7
using namespace std;

const int maxn = 2000105;
const int Max = 2000100;
int p[maxn];
int s[maxn], f[maxn];
int d[maxn];

void GetPrime(int n){
    clr(p,0);
    for(int i=2; i<=n; ++i) {
        if(!p[i]) {p[++p[0]] = i;}
        for(int j=1; j<=p[0] && p[j]<=n/i; ++j) {
            p[p[j]*i] = 1;
            if(i%p[j]==0) break;
        }
    }
}

int GCD(int a,int b)
{
    return   b==0?a:GCD(b,a%b);
}


void Ex_gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return ;
    }
    else
    {
        Ex_gcd(b,a%b,y,x);
        y-=x*(a/b);
    }
}

void init()
{
	int n = Max;
	int a=0;
	int b=0;
	s[0] = f[0] = 0;
	int l = 1;
	for(int i=1; i<=n; ++i) {
			s[i] = s[i - 1];
			if(i==p[l]){
				s[i]++;
				l++;
			}
			f[i] = f[i-1];
			bool flag = true;
			int len = 0, m = i;
            int ss=max(a,b);
			while(m){ d[len++] = m%10; m/=10;}
			for(int i=0; i<len/2; ++i) {
				if(d[i] != d[len-i-1]) {
					flag = false;
					break;
				}
			}
			if(flag) f[i]++;
	}

}

void Solve(int p, int q)
{
    int a=2;
    int b=3;
    int ss=GCD(a,b);
	int i;
	for(i=Max; i>=1; --i) {
			if(s[i]*q <= p*f[i]) break;
	}
	printf("%d\n", i);
}

int main()
{
    #ifndef ONLINE_JUDGE
    //intxt;outtxt;
     #endif // ONLINE_JUDGE
	GetPrime(Max);
	init();
	int p, q;
	while(~scanf("%d%d", &p, &q)){
		Solve(p, q);
	}
	return 0;
}




