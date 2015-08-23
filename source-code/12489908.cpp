//Language: GNU C++11


#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

bool isprime(int x)
{
  if(x<2) return 0;
  for(int i=2;i*i<=x;i++)
    if(x%i==0) return 0;
  return 1;
}

bool ispalindromic(int x)
{
  int re=x,next=0;
  while(x)
  {
    next*=10;
    next+= (x%10);
    x/=10;
  }
  if(re==next)
    return 1;
  return 0;
}

int main()
{
  unsigned long long int p,q,pnum=0,qnum=0,Max;
  cin>>p>>q;
  for(int i=1;i<1200000;i++)
  {
    if(isprime(i))
      qnum++;
    if(ispalindromic(i))
      pnum++;
    if(q*qnum<=p*pnum)
      Max=i;
  }
  cout<<Max<<endl;
}