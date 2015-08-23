//Language: GNU C++


#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <vector>
#define sqr(x) (x)*(x)
#define X first
#define Y second
#define sz(A) int(A.size())
#define mpair make_pair
#define inf 0xfffffff
using namespace std;
const int maxn=1e5;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pt;
typedef int tarr[maxn];
typedef double rl;
const int lg=20;
int n,m;
tarr a;
string s;
int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  //freopen("input.txt","r",stdin);
  cin>>n>>m;
  cin>>s;
  int res=0;
  char t[1];
  for (int i=0;i<n-1;i++)
  {
    if (s[i]=='.'&&s[i+1]=='.')
    res++;
  }
  int ans=res;
  for (int i=1;i<=m;i++)
  {
    int x; char c;
    cin>>x>>c;
    if (c=='.')
    {
      if (s[x-1]!='.')
      {
        if (s[x-2]=='.')
            res++;
        if (s[x]=='.')
            res++;
      }
    } else
    {
      if (s[x-1]=='.')
      {
        if (s[x-2]=='.')
            res--;
        if (s[x]=='.')
            res--;
      }
    }
   s[x-1]=c;
   cout<<res<<endl;
  }
}

