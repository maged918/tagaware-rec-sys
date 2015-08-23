//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
#define MAX 3
vector< pair<int,int> > res(MAX);
int main()
{
  int a[MAX],ans; a[0] =  a[1] = a[2] = ans = 0;
  int n; cin >> n ;
  for(int i = 0 ; i < MAX ; ++i)
    {
      cin >> res[i].first >> res[i].second;
      ans+= res[i].first;
    }
  a[0] = res[0].first;
  a[1] = res[1].first;
  a[2] = res[2].first;
  while(ans < n )
    {
      for(int i = 0 ; i < MAX ; ++i)
	{
	  int difi = res[i].second - res[i].first;
	  int toadd = ( ans  + difi  > n ? n - ans : difi);
	  a[i] += toadd;
	  ans += toadd;
	}	
    }
  for(int i = 0 ; i < MAX ; ++i)
    cout << a[i] << " ";
  cout << "\n";
  return 0;
}
