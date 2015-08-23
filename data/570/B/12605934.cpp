//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m,a; cin >> n >> m;
  a = (n-m) >=  m ?  m+1 : m-1;
  cout << (a > 0 ? a : 1)  << "\n";
  return 0;
}
