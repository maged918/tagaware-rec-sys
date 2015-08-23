//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <set> 
using namespace std;

int main()
{
	//freopen("input","r",stdin);
	//freopen("output","w",stdout);
	int T,S,q;
	scanf("%d%d%d",&T,&S,&q);
	double s=S;
	double t=(double)q;

	int cnt=1;
	while (s*t<T)
	{
		cnt++;
		s=s*t;
	}
	printf("%d\n",cnt);
	return 0;
}