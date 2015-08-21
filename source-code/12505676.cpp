//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<limits.h>
#define si(n) scanf("%d",&n)
//#define sl(n) scanf("%lld",&n)
#define ss(n) scanf("%s",n)
#define sf(n) scanf("%f",&n)

#define pi(n) printf("%d\n",n)
//#define pl(n) printf("%lld\n",n)
#define ps(n) printf("%s\n",n)
#define pf(n) printf("%.0f\n",n)

//#define ll long long int
#define r0 return 0
#define INF INT_MAX
#define FR(i,a,b) for(i=a;i<b;i++)
#define decit int i,j,k

using namespace std;


int main()
{
    int n,m;
    si(n);
    si(m);
    decit;
    vector<int> a(n+5);
    vector<int> b(n+5);
    FR(i,0,n+2)
        b[i]=0;
    int min=0;
    FR(i,0,m)
    {
        si(a[0]);
        min=0;
        FR(j,1,n)
        {
            si(a[j]);
            if(a[min]<a[j])
                min=j;
        }
        b[min]++;
    }
    min=0;
    FR(i,1,n)
    {
        if(b[i] > b[min])
            min=i;
    }
    pi(min+1);
r0;
}
