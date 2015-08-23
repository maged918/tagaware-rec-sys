//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
#define PI           3.14159265358979323846264338327950
#define gcd(a,b)      __gcd(a,b)
#define nl            printf("\n")
#define spc           printf(" ")
#define yes           printf("YES\n")
#define no            printf("NO\n")
#define si(x)         scanf("%I64d",&x)
#define sii(x,y)      scanf("%I64d %I64d",&x,&y)
#define siii(x,y,z)   scanf("%I64d %I64d %I64d",&x,&y,&z)
#define sd(a)         scanf("%lf",&a)
#define sdd(a,b)      scanf("%lf %lf",&a,&b)
#define pi(x)         printf("%I64d",x)
#define pin(x)        printf("%I64d\n",x)
#define pis(x)        printf("%I64d ",x)
#define pii(a,b)      printf("%I64d %I64d",a,b)
#define piii(a,b,c)   printf("%I64d %I64d %I64d",a,b,c)
#define pd(a)         printf("%lf",a)
#define pdd(a,b)      printf("%lf %lf",a,b)
#define pb            push_back
#define iii(a,n)    for(long long i=a;i<=n;i++)
#define jjj(a,n)    for(long long j=a;j<=n;j++)
long long a,b,c,d,k,l,i,j,t,n,m,p,cs,kk,q,r,s;
char o;
double e,f,g;
string x,y,z;
int main()
{
    while(cin>>m>>n)
    {
        if(m==1&&n==1)
        {
            cout<<1<<endl;
            return 0;
        }
        s=abs(m-n);
        b=abs(n-1);
        if(s==b)
            cout<<n-1<<endl;
          else  if(s>b)
                cout<<n+1<<endl;
            else if(s<b)
                cout<<n-1<<endl;
    }

    return 0;
}



