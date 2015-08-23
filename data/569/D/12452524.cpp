//Language: GNU C++


#include <cstdio>
#define MOD 1000000007
using namespace std;
int a[5000],b[5000],n,cnt;
int main()
{
    scanf("%d",&n);
    a[1]=1;
    b[1]=1;
    b[2]=2;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=i+2;j++)a[j]=b[j];
        b[1]=a[i+1];
        for(int j=2;j<=i+2;j++)b[j]=(b[j-1]+a[j-1])%MOD;
        if(i==n-2)cnt-=b[i+2];
        if(i==n-1)cnt+=b[i+2];
    }
    cnt+=MOD;
    cnt%=MOD;
    if(n==1)cnt=1;else if(n==2)cnt=3;
    printf("%d",cnt);
    return 0;
}
