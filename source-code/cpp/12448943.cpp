//Language: MS C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>
#include <fstream>
#define ll long long int
using namespace std;
int ar[100010];
int ar2[100010];
int main()
{
   //freopen("in.txt", "r", stdin);
   int n;
   scanf("%d", &n);
   for(int i = 0; i < n; i++)
   {
	   scanf("%d", &ar2[i]);
	   ar[ar2[i]]++;
   }
   int c = 1;
   for(; c <= n; c++)
   {
	   if(ar[c] == 0) break;
   }
   for(int i = 0; i < n; i++)
   {
	   if(ar[ar2[i]] > 1 || ar2[i] > n)
	   {
		   ar[ar2[i]]--;
		   ar2[i] = c;
		   c++;
		   for(; c <= n; c++)
		   {
			   if(ar[c] == 0) break;
		   }
	   }
   }
   for(int i = 0; i < n; i++)
   {
	   if(i == n-1)printf("%d\n", ar2[i]);
	   else printf("%d ", ar2[i]);
   }
   return 0;
}