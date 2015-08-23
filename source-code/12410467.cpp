//Language: GNU C++11


#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int> > a, b;
  int x = 0, y = 0;
  int tmp, tmp2;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp >> tmp2;
    if (tmp > 0)
      a.push_back({tmp, tmp2});
    else
      b.push_back({-tmp, tmp2});
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int v1 = 0, v2 = 0;
  int i;
  for (i = 0; i < a.size() && i < b.size(); i++)
  {
    v1 += a[i].second;
    v1 += b[i].second;
    v2 += b[i].second;
    v2 += a[i].second;
  }
  if (i < a.size())
    v1 += a[i].second;
  if (i < b.size())
    v2 += b[i].second;
  cout << max(v1, v2) << endl;
  return 0;
}
