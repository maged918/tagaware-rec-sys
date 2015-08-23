//Language: GNU C++11


#include <bits/stdc++.h>
#define lb lower_bound
#define ub upper_bound
#define b begin
#define e end
using namespace std;
vector <int> v[26];
int main()
{
	int n,q,l,r,d;string s;cin>>n>>q>>s;
	for (int i=0;i<s.size();i++)
		v[s[i]-'a'].push_back(i);
	while (q--)
	{
	    cin>>l>>r>>d;
		l--;r--;
		if (d==1)
		{
			int cnt=l;
			for (int i = 0; i <= 26; ++i)
			{
				int ss=lb(v[i].b(),v[i].e(),l)-v[i].b(),ff=ub(v[i].b(),v[i].e(),r)-v[i].b();
				for (int j=ss;j<ff;j++)
				{
					v[i][j]=cnt;
					cnt++;
				}
			}
		}
		else if (d==0)
		{
			int cnt=l;
			for (int i=26;i>=0;i--)
			{
				int ss=lb(v[i].b(),v[i].e(),l)-v[i].b(),ff=ub(v[i].b(),v[i].e(),r)-v[i].b();
				for (int j = ss; j < ff; ++j)
				{
					v[i][j]=cnt;
					cnt++;
				}
			}
		}
	}
	for (int i=0;i<27;i++)
		for (int j=0;j<v[i].size();j++)
			s[v[i][j]]=char('a'+i);
	cout<<s<<endl;
	return 0;
}
