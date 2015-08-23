//Language: GNU C++


#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<deque>
#include<vector>
#include<set>
#include<ctype.h>
using namespace std;
#define inf 999999
#define MAX 100
#define gcd(a,b) __gcd(a,b)
#define ll long long
int getInt()
{
    int x;
    scanf("%d",&x);
    return x;
}
long long getLongLong()
{
    long long x;
    scanf("%I64d",&x);
    return x;
}
double getDouble()
{
    double x;
    scanf("%lf",&x);
    return x;
}
char  getChar()
{
    char x;
    scanf("%c",&x);
    return x;
}
#define Int getInt()
#define Char getChar()
#define I64 getLongLong()
#define Double getDouble()
/////////////////////////////////

int main()
{
    int a[100001],ansx1=0,ansx2=0,ansx=0,ansm=0,b[100001]={0};
    int k=Int;
    a[0]=Int;
    for(int i=1; i<k; i++)
    {
        a[i]=Int;
        b[i]=a[i]-a[i-1]+b[i-1];
    }
    for(int i=0; i<k; i++)
    {
        ansx1=0;
        ansx2=0;
        ansx=0;
        ansm=0;
        if(i==0)
        {
            ansm=a[i+1]-a[i];
        }
        else if(i==k-1)
        {
            ansm=a[i]-a[i-1];
        }
        else
            ansm=min(a[i+1]-a[i],a[i]-a[i-1]);


   // for(int j=0; j<i; j++)
        //ansx1+=a[j+1]-a[j];
    for(int j=i; j<k-1; j++)
        ansx2+=a[j+1]-a[j];
    ansx=max(b[i],ansx2);

    printf("%d %d\n",ansm,ansx);
}

return 0;

}

