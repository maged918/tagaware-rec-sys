//Language: GNU C++11


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pair<int,int> > vpi;


int main()
{
  long long n,m;
  cin>>n>>m;
  if(n == 1) cout<<1;
  else if(n - m + 1 == m - 1) cout<<m-1;
  else if(n - m == m-1) cout<<m-1;
  else if(m == n - m) cout<<m+1;
  else if(n-m+1 < m-1) cout<<m-1;
  else if(n-m+1 > m-1) cout<<m+1;

  return 0;
}