//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int line[100005],e[100005],n;

int main()
{
	queue<int>q;
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>line[i];
		e[line[i]]++;
		if(e[line[i]]>1||line[i]>n)
			q.push(i); 
	}
	for(i=1;i<=n;i++)
	{
		if(!e[i])
		{
			int a=q.front();
			line[a]=i;
			q.pop();
		}
		if(q.empty()) break;
	}
	for(i=1;i<=n;i++)
	printf("%d ",line[i]);
	return 0;
}

			
 
