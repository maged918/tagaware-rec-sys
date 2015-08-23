//Language: GNU C++


/* 
ID: myitaye1
PROG: 
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define min(a, b) ( ( (a) < (b) ) ? (a) : (b) )
#define max(a, b) ( ( (a) > (b) ) ? (a) : (b) )

using namespace std;

int main() {

  //freopen ("test1.in", "r", stdin);
  //freopen ("test2.out", "w", stdout);

  int n;
  cin >> n;
  int a[n];

  int hit1[n+1];
  int hit2[n+1];
  memset(&hit1, 0x00, sizeof(int)*(n+1));
  memset(&hit2, 0x00, sizeof(int)*(n+1));


  // input
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] <= n)
      hit1[a[i]] = 1;
  }

  // unused
  queue<int> q;
  for (int i = 0; i < n; i++)
    if (!hit1[i+1])
      q.push(i+1);


  // print out
  for (int i = 0; i < n; i++) {
    if (a[i] <= n && !hit2[a[i]]) {
      cout<<a[i]<<" ";
      hit2[a[i]] = 1;
    }
    else {
      cout<<q.front()<<" ";
      q.pop();
    }
  }

  cout<<endl;
  return 0;
}


