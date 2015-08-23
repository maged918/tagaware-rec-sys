//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 40;
const int MAXK = 105;

map<string,bool(*)(int,int)> fn;

int N, K, A[MAXK], B[MAXK];
string C[MAXK];
vector<int> id[2 * MAXN];
ll dp[MAXN][2 * MAXN], res;

bool check(int l, int r, int a, int b){
  if(a < 0 || b >= 2 * N) return 0;
  auto val = [=](int p){
    if(p == a || p == b) return 0;
    if(l <= p && p < r) return 1;
    return -1;
  };
  for(int i = 0; i < 2; i++){
    for(int k : id[a]){
      int x = val(A[k]);
      int y = val(B[k]);
      if(!fn[C[k]](x, y)) return 0;
    }
    swap(a, b);
  }
  return 1;
}

void init(){
  fn["<"] = [](int a, int b){ return a < b; };
  fn[">"] = [](int a, int b){ return a > b; };
  fn["="] = [](int a, int b){ return a == b; };
  fn["<="] = [](int a, int b){ return a <= b; };
  fn[">="] = [](int a, int b){ return a >= b; };
}

int main(){
  init();
  cin >> N >> K;
  for(int i = 0; i < K; i++){
    cin >> A[i] >> C[i] >> B[i];
    A[i] -= 1, B[i] -= 1;
    id[A[i]].push_back(i);
    id[B[i]].push_back(i);
  }
  dp[N][0] = 1;
  for(int i = N; i > 0; i--){
    for(int j = 0; j <= 2 * (N - i + 1); j++){
      int k = j + 2 * i - 2;
      ll &d = dp[i - 1][j];
      if(check(j, k, j - 2, j - 1)) d += dp[i][j - 2];
      if(check(j, k, j - 1, k)) d += dp[i][j - 1];
      if(check(j, k, k, k + 1)) d += dp[i][j];
      if(i == 1) res += d;
    }
  }
  cout << res / 3 << '\n';
}
