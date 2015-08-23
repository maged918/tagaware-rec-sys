//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define xx first
#define yy second
#define mod 1000000007ll
#define pb push_back
#define mp make_pair
#define PI M_PI
using namespace std;

int dirx[] = {0,1,0,-1,1,1,-1,-1};
int diry[] = {1,0,-1,0,1,-1,1,-1};

long long powlog(long long a, long long b, long long c) {
  long long ret = 1ll;
  while(b>0) {
    if(b%2ll == 1ll) ret = (ret * a) % c;
    a = (a * a) % c;
    b /= 2ll;
  }
  return ret;
}

map<long long, long long> m,m2;
long long a[200009], ans[200009];

int main() {
  int n;
  long long k;
  scanf("%d%lld", &n, &k);
  for(int i=0;i<n;i++) {scanf("%lld", &a[i]);}
  unsigned long long ans2 = 0, c1, c2;
  for(int i=0;i<n;i++) {
    if(a[i]%(k)==0) {
      c1 = m[a[i]/k];
      ans[i] = c1;
    }
    m[a[i]] ++;
  }
  for(int i=n-1;i>=0;i--) {
    if(a[i]%k==0) {
      c1 = m2[a[i]*k];
      ans[i] *= c1;
    }
    m2[a[i]] ++;
  }
  for(int i=0;i<n;i++) ans2 += ans[i];
  cout << ans2 << endl;
}
