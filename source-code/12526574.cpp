//Language: GNU C++11


#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

const int N = 6e5;
 
string s;
vector<int> v[N],lay[N],pre[N];
int n,m,ptv[N],vtp[N],lt[N],rt[N],p,max_l;

void dfs(int x,int l)
{
//	cout << x << ' ' << l << endl;
	max_l = max(max_l,l);
	ptv[++p] = x;
	vtp[x] = p;
	lay[l].push_back(p);
	int len = v[x].size();
	for (int i = 0; i<len; i++)
		dfs(v[x][i],l+1);
	if (len==0)
		rt[vtp[x]] = vtp[x];
	else
		rt[vtp[x]] = rt[vtp[v[x][len-1]]];
//	cout << x << " end" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 2; i<=n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	cin >> s;
	dfs(1,1);
//	cout << max_l << endl;
	for (int i = 1; i<=n; i++)
	{
		int len = lay[i].size();
//		cout << i << endl;
		pre[i].push_back(0);
		for (int j = 0; j<len; j++)
		{
			pre[i].push_back(pre[i][j]);
//			cout << pre[i][j+1] << endl;
			pre[i][j+1] ^= (1<<(s[ptv[lay[i][j]]-1]-'a'));
		}
	}
	/*cout << endl;
	for (int i = 1; i<=n; i++)
		cout << i << ' ' << rt[i] << endl;
	cout << endl;*/
	for (int i = 1; i<=m; i++)
	{
		int x,y;
		cin >> x >> y;
		int l = lower_bound(lay[y].begin(),lay[y].end(),vtp[x])-lay[y].begin();
		int r = lower_bound(lay[y].begin(),lay[y].end(),rt[vtp[x]]+1)-lay[y].begin()-1;
//		cout << l << ' ' << r << endl;	
		int tmp = pre[y][r+1]^pre[y][l];
		if (__builtin_popcount(tmp)<2)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
	
