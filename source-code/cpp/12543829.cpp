//Language: GNU C++11


#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int maxn = 500005;

 
 int tm[maxn];
 char vv[maxn];
vector <int> q[maxn];
int depth[maxn];
int  in[maxn];
int out[maxn];
int knum=0; 
vector <int> cal[maxn][27];
 

int dfs1(int x,int cur)
{
	int i;
	cal[cur][vv[x]-'a'+1].push_back(++knum);
	in[x]=knum;
	for (i=0;i<q[x].size();i++)
	{ 
		depth[q[x][i]]=cur+1;
			dfs1(q[x][i],cur+1);
	} 
	out[x]=knum;
return 0;
} 
int main()
{
	

	int n,m,i,k,t1,t2;
	scanf("%d%d",&n,&m);
	
	for (i=2;i<=n;i++)
	{
		scanf("%d",&tm[i]);
		q[tm[i]].push_back(i);
	}
	if (n==1) getchar();
	getchar(); tm[1]=1;
	scanf("%c",&vv[1]);
	for (i=2;i<=n;i++)
	{
		scanf("%c",&vv[i]);
	}
	depth[1]=1; 
	dfs1(1,1); //prepared for [depth,charactor];

 
	for (k=1;k<=m;k++)
	{
		scanf("%d%d",&t1,&t2);
	//	if (depth[t1]>=t2)
	//	printf("Yes\n");
	//	else
		{
		 
		 
			int line=0,flag=0;
			for (i=1;i<=26;i++)
			{
	 
			 int tf1=lower_bound(cal[t2][i].begin(),cal[t2][i].end(),in[t1])- cal[t2][i].begin()+1;
			 int tf2=upper_bound(cal[t2][i].begin(),cal[t2][i].end(),out[t1])- cal[t2][i].begin()+1;
			 if ((tf2-tf1)%2)
			 {
				 if (line==0)
				 {line=1;continue;}
				 if (line==1)
				 {flag=1;break;}
			 }
				

			}
			if (flag==0)
			printf("Yes\n");
			else
			{printf("No\n");}
		}


	}
	return 0;
	
	
}  