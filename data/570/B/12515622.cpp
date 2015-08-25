//Language: GNU C++


#include<bits/stdc++.h>

#define lld long long int

using namespace std;
lld n, m, c, l, r, a;

int main(void)
{

  cin>>n>>m;

  l=m-1;
  r = n-m;
  if(l>=r)
    if(m>1)
        a=m-1;
    else
        a=m;
  else if(r>l)
    a=m+1;

  cout<<a<<endl;
    return 0;
}
