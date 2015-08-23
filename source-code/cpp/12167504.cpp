//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

int a1, b1, a2, b2, a3, b3;

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // ONLINE_JUDGE
  cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
  if(max(a2, a3) <= a1 && (b2 + b3 <= b1)) {cout << "YES"; return 0;}
  if(max(a2, b3) <= a1 && (a3 + b2 <= b1)) {cout << "YES"; return 0;}
  if(max(a3, b2) <= a1 && (a2 + b3 <= b1)) {cout << "YES"; return 0;}
  if(max(b2, b3) <= a1 && (a2 + a3 <= b1)) {cout << "YES"; return 0;}
  if(max(a2, a3) <= b1 && (b2 + b3 <= a1)) {cout << "YES"; return 0;}
  if(max(a2, b3) <= b1 && (a3 + b2 <= a1)) {cout << "YES"; return 0;}
  if(max(a3, b2) <= b1 && (a2 + b3 <= a1)) {cout << "YES"; return 0;}
  if(max(b2, b3) <= b1 && (a2 + a3 <= a1)) {cout << "YES"; return 0;}
  cout << "NO";
  return 0;
}
