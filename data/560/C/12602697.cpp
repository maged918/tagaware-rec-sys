//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <set>
#include <queue>
#include <time.h>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
	int a[10];
	while (scanf("%d" , &a[1]) != EOF)
	{
		for (int i = 2;i <= 6;i ++)
			scanf("%d" , &a[i]);
		int cur = 2 * a[1] - 1 , ans = 0;
		int level = 1;
		while (level <= a[2] + a[3])
		{
			if (level <= a[2])
				cur ++;
			else
			{
				if (level > a[2] + 1)
					cur --;
			}

			if (level <= a[6])
				cur ++;
			else
			{
				if (level > a[6] + 1)
					cur --;
			}
			ans += cur;
			level ++;
		}
		printf("%d\n" , ans);
	}
	return 0;
}