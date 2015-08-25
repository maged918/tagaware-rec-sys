//Language: GNU C++


#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair
#define F first
#define S second

int h, q;
vector<pair<ll,ll> > yes;
vector<pair<ll,int> > no;

ll goLeft(ll x, int k)
{
  while(k--) x*=2;
  return x;
}

ll goRight(ll x, int k)
{
  while(k--) x=2*x+1;
  return x;
}

ll przetnij(pair<ll,ll> a, pair<ll,ll> b)
{
  if(b.F<a.F) swap(a,b);
  if(b.F>a.S) return 0;
  return min(a.S,b.S)-b.F+1;
}

bool cmp(pair<ll,int> a, pair<ll,int> b)
{
  if(a.F<b.F) return true;
  if(a.F>b.F) return false;
  return a.F>b.F;
}

ll elementWspolny(pair<ll,ll> a, pair<ll,ll> b)
{
  return max(a.F,b.F);
}

int main()
{
  scanf("%d%d", &h, &q);
  
  while(q--)
  {
    int i, ans;
    ll L, R;
    scanf("%d%lld%lld%d", &i, &L, &R, &ans);
    
    pair<ll,ll> prz=MP(goLeft(L,h-i), goRight(R,h-i));
    
    if(ans==1) yes.PB(prz);
    else
    {
     // printf("no(%lld, %lld)\n", prz.F, prz.S);
      no.PB(MP(prz.F,1));
      no.PB(MP(prz.S,-1));
    }
  }
  
  ll begin=goLeft(1,h-1);
  ll end=goRight(1,h-1);
  
  no.PB(MP(begin-1,1)); no.PB(MP(begin-1,-1));
  no.PB(MP(end+1,1)); no.PB(MP(end+1,-1));
  
  if(yes.size()>0)
  {
    begin=yes[0].F, end=yes[0].S;
    for(vector<pair<ll,ll> >::iterator it=yes.begin(); it!=yes.end(); it++)
      begin=max(begin,it->F), end=min(end,it->S);
  }

  if(begin>end)
  {
    printf("Game cheated!");
    return 0;
  }
  
  sort(no.begin(), no.end(), cmp);
  
  ll wsp=0, prev=-1, wyn;
  int stan=0;
  for(vector<pair<ll,int> >::iterator it=no.begin(); it!=no.end(); it++)
  {
    if(stan==0 && prev!=-1 && prev+1<=(it->F)-1)
    {
      ll przeciecie=przetnij(MP(prev+1,(it->F)-1), MP(begin,end));
      wsp+=przeciecie;
      if(przeciecie>0) wyn=elementWspolny(MP(prev+1,(it->F)-1), MP(begin,end));//prev+1;
    }
    
    prev=it->F;
    stan+=it->S;
  }

  if(wsp==0)
    printf("Game cheated!");
  
  if(wsp==1)
    printf("%lld", wyn);

  if(wsp>1)
    printf("Data not sufficient!");
  
  return 0;
}