//Language: GNU C++


#include <bits/stdc++.h>
#define ll long long
using namespace std;
int v[1000010];
int main()
{
	int i;
	memset(v,0,sizeof(v));
	int t;//time
	scanf("%d",&t);
	string s;
	int id,ans=0,cur=0;
	for(i=0;i<t;i++)
	{
		cin>>s>>id;
		if(s=="+")
		{
			cur++;
			v[id]=1; //visited
		}
		else if(s=="-")
		{
			if(v[id]==0)//No arrival details
			{
				ans++;
			}
			else
			{
				cur--;
				v[id]=0;//Left
			}
		}
		ans=max(ans,cur);
	}
	printf("%d\n",ans);
	return 0;
}
