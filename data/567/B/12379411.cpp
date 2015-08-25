//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double eps = 1e-4;
map <int, bool> mp;
int main()
{
    //freopen("H:\\in.txt","r",stdin);
    //freopen("H:\\out.txt","w",stdout);
    int n, mmax = 0, ans = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		int temp;
		char ch;
		scanf("%c %d", &ch, &temp);
		getchar();
		if (ch == '+')
		{
			mp[temp] = 1;
			mmax++;
			ans = max(ans, mmax);
		}
		else
		{
			if (mp[temp])
				mp[temp] = 0, mmax--;
			else
				ans++;
		}
	}
	printf("%d\n", ans);
    return 0;
}
