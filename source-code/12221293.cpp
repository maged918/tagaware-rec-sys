//Language: GNU C++


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define ri(X) scanf("%d", &(X))
#define pi(X) printf("%d", (X))
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define lint long long
#define pii pair<int,int>
#define inf 1e9
#define linf 1e18
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define uni(X) X.erase(unique(X.begin(), X.end()), X.end());


#define MAXN 100009
#define T int
#define neutro 0


T sum[26][MAXN*17];
bool value[26][MAXN*17];
bool change[26][MAXN*17];

T f(T a, T b) { return a + b; } // Funcion que mantiene el segment tree


// query(1,1,N,i,j)
T query(int node, int b, int e, int i, int j, int k) {
  int m = (b + e) >> 1, lt = node << 1, rt = lt | 1;
  
  if(change[k][node]){
    value[k][lt] = value[k][rt] = value[k][node];
    sum[k][node] = value[k][node] * (e - b + 1);
    change[k][lt] = change[k][rt] = 1;
    change[k][node] = 0;
  }
	if(i > e || j < b) return neutro;
	if (i <= b && e <= j) return sum[k][node];
	else return f(query(lt, b, m, i, j, k), query(rt, m+1, e, i, j, k));
}

// modify(1,1,N,i,j,val)
void modify(int node, int b, int e, int i, int j, int k, int v) {
  int m = (b + e) >> 1, lt = node << 1, rt = lt | 1;  
  if(change[k][node]){
    value[k][lt] = value[k][rt] = value[k][node];
    sum[k][node] = value[k][node] * (e - b + 1);
    change[k][lt] = change[k][rt] = 1;
    change[k][node] = 0;
  }
  if(i > e || j < b) return;
	if (i <= b && e <= j) {
	  value[k][lt] = value[k][rt] = value[k][node] = v;
	  sum[k][node] = value[k][node] * (e - b + 1);
    change[k][lt] = change[k][rt] = 1;
    change[k][node] = 0;
	  return;
	}
	modify(lt, b, m, i, j, k, v);
	modify(rt, m+1, e, i, j, k, v);
	sum[k][node] = f(sum[k][lt], sum[k][rt]);
}

int n, q;
string s;
int main(){
  std::ios::sync_with_stdio(false);
  cin >> n >> q;
  cin >> s;
  for(int i = 0; i < n; i++){
    modify(1,1,n, i+1,i+1, s[i]-'a', 1);
  }
  int u,v,w;
  int sum[26];
  for(int i = 0; i < q; i++){
    cin >> u >> v >> w;
    for(int k = 0; k < 26; k++){
      sum[k] = query(1,1,n, u, v, k);
    }
    for(int k = 0; k < 26; k++){
      modify(1,1,n,u,v,k,0);
    }
    if(w == 1){
      int p = u;
      for(int k = 0; k < 26; k++){
        modify(1,1,n,p, p+sum[k]-1, k, 1);
        p = p+sum[k];
      }
    }else{
      int p = u;
      for(int k = 25; k >= 0; k--){
        modify(1,1,n,p, p+sum[k]-1, k, 1);
        p = p+sum[k];
      }
    }
  }
  for(int i = 0; i < n; i++){
    for(int k = 0; k < 26; k++){
      if(query(1,1,n, i+1,i+1,k)){
        s[i] = k+'a';
      }
    }
  }
  cout << s << endl;
  return 0;
}

