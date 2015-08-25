//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
  int len[6];
  for (int i = 0; i < 6; i++) {
    cin >> len[i];
  }
  int add = len[0], lim = min(len[1], len[5]);
  long long int ans = 0;
  for (int i = 0; i < lim; i++) {
    ans += 2*add + 1;
    add++;
  }
  for (int i = lim; i < max(len[1], len[5]); i++) {
    ans += 2*add;
  }
  lim = add;
  for (int i = 0; i < lim - len[3]; i++) {
    ans += 2*add - 1;
    add--;
  }
  std::cout << ans << std::endl;
  return 0;
}
