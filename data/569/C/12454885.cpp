//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;

vector<int> sieve(int n){
  bool is_prime[n + 1] = {0};
  vector<int> sum(n + 1, 0);
  is_prime[0] = is_prime[1] = true;
  for (int i = 2; i <= n; i++) {
    if(is_prime[i] == true)continue;
    sum[i]++;
    for (int j = 2*i; j <= n; j += i)is_prime[j] = true;
  }
  for (int i = 0; i < n; i++) {
    sum[i + 1] += sum[i];
  }
  return sum;
}

vector<int> prindrom(int n){
  vector<int> res(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    stringstream ss;
    ss << i;
    string rev = ss.str();
    string s = rev;
    reverse(rev.begin(), rev.end());
    if(s == rev)res[i]++;
  }
  for (int i = 0; i <= n; i++) {
    res[i + 1] += res[i];
  }
  return res;
}
int main(int argc, char *argv[]){
  int p, q;
  cin >> p >> q;
  const int m = 1250000;
  vector<int> sum_prime = sieve(m);
  vector<int> sum_prindrom = prindrom(m);
  double a = (double)p / q;
  for (int i = m; i > 0; i--) {
    if(sum_prime[i] <= a*sum_prindrom[i]){
      std::cout << i << std::endl;
      return 0;
    }
  }
  std::cout << "Palindromic tree is better than splay tree" << std::endl;
  return 0;
}

