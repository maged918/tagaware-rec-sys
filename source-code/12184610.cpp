//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

#define P9 1000000007
#define LL long long
#define fi first
#define se second

using namespace std;

LL fc[250020];
LL fcc[250020];

LL PW(LL A,LL B)
 {
  if (!B) return 1;
  LL D=PW(A,B/2); D*=D; D%=P9;
  if (B%2) D*=A;
  return D%P9;
 }

LL C(int a,int b)
 {
  LL sol=(((fc[b]*fcc[a])%P9)*fcc[b-a])%P9;
  return sol;
 }

long long solve(int a,int b)
 {
  if (a > b) swap(a,b);
  return C(a-1,a+b-2);
 }
pair < int , int > P[260000];
int h,w,n,i,j;
LL res[260000],now;

main()
 {
  fc[0]=fcc[0]=1;
  fc[1]=fcc[1]=1;
  for (i=2;i<=220000;i++)
   fc[i]=(fc[i-1]*i)%P9,
   fcc[i]=PW(fc[i],P9-2);

  cin>>h>>w>>n;
  for (i=1;i<=n;i++)
   cin>>P[i].fi>>P[i].se;
  sort(P+1,P+n+1);
  if (P[n].fi == h && P[n].se == w)
  {
    cout<<0<<endl;
    return 0;
  }
  if (P[1].fi== 1 && P[1].se == 1)
  {
    cout<<0<<endl;
    return 0;
  }
  n++;
  P[n].fi=h;
  P[n].se=w;
  for (i=1;i<=n;i++)
   {
    res[i]=solve(P[i].fi,P[i].se);
   for (j=1;j<i;j++)
      if (P[j].fi <= P[i].fi && P[j].se <= P[i].se)
       {
        now=solve(P[i].fi-P[j].fi+1,P[i].se-P[j].se+1);
        now=(now*res[j])%P9;
        res[i]-=now;
        if (res[i] < 0) res[i]+=P9;
       }
   }
  cout<<res[n]<<endl;
 }
