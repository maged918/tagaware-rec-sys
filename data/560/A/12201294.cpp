//Language: MS C++


#include<iostream>
#include<string.h>
#include<math.h>
#include<fstream>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<vector> 
#define MAXSIZE 100
using namespace std;
const int INF = 1<<30; 
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b)) 
int n = 0; 
int a = 0, ans = 1;
int main()
{
	//freopen("data_A.txt","r",stdin);
	while(scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			if (a == 1)
			{
				ans = -1;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
