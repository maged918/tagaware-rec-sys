//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
      int Right=n-m;
      int Left=m-1;
      if(n==1){cout<<1;return 0;}
      if(Right>Left)cout<<m+1;
      else cout<<m-1;

    return 0;
}
