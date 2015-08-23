//Language: GNU C++


# include <bits/stdc++.h>
using namespace std;

int a[1000005];
int b[105];
char ch[105];

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	int i,initial=0;
	for(i=0;i<n;i++)
	{
		scanf("%c %d",&ch[i],&b[i]);
		if(ch[i]=='-' && a[b[i]]==0) initial++;
		else if(ch[i]=='+' && a[b[i]]==0) a[b[i]]=1;
		getchar();
	} 
	
	memset(a,0,sizeof(a));

	int p=initial,ans=initial;

	for(i=0;i<n;i++)
	{
		if(ch[i]=='+') { p++; a[b[i]]++; }
		else if(ch[i]=='-') { p--; a[b[i]]--; }

		ans=max(ans,p);  
	}

	printf("%d\n",ans);
	return 0;
}