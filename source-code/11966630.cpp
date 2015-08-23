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


int main(){
  int n;
  int a[3];
  int b[3];

  cin >> n;
  for(int i = 0; i < 3; i++){
    cin >> a[i] >> b[i];
  }
  
  int res[3] = {0,0,0};
  for(int k = 0; k < 3; k++){
    res[k] = a[k];
    n-=a[k];
  }
  
  for(int k = 0; k < 3; k++){
    int rp = min(n,b[k]-a[k]);
    res[k]+= rp;
    n -=rp;
  }
  for(int k = 0; k < 3; k++){
    cout << res[k] << (k==2?'\n':' ');
  }
  return 0;
}

