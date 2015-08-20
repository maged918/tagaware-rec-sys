//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
bool primes[11111111]={1,1};
int p,q,cp,cq;
inline int pol(int x)
{
  int t=0,y=x;
  for(;y;y/=10)
    t=t*10+y%10;
  return t==x;
}
int main()
{
  cin>>p>>q;
  for(int i=2;i*1ll*i<=N;i++)
    if(!primes[i])
      for(int j=i*i;j<=N;j+=i)
        primes[j]=1;
  int pos;
  for(int i=1;i<=N;i++)
  {
    cp+=(!primes[i]);
    cq+=pol(i);
    if(cp<=cq*p/q)
     pos=i;
  }
  cout<<pos;
  return 0;
}