//Language: GNU C++


#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct node
{
	ll int p,ans;//previous & ans
}node;
set<ll int> st;
set<ll int>::iterator it;
map<ll int,node> mp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	ll int i,p=-1;
	node r;
	ll int ans=0;
	st.insert(-1);
	r.p=-1;
	r.ans=0;
	mp[-1]=r;
	for(i=0;i<n;i++)
	{
		if(s.at(i)!='.')
		{
			st.insert(i);
			r.p=p;
			r.ans=(i-p)-1;
			if(r.ans>=2)
			{
				r.ans--;
			}
			else
			r.ans=0;
			ans+=r.ans;
			mp[i]=r;
			p=i;
		}
	}
	st.insert(n);
	r.p=p;
	r.ans=(n-p)-1;
	if(r.ans>=2)
	{
		r.ans--;
	}
	else
	r.ans=0;
	ans+=r.ans;
	mp[i]=r;
	//~ cout<<ans<<endl;
	int index;
	char c;
	for(i=0;i<m;i++) //m queries
	{
		cin>>index>>c;
		index--;//converting to 0-based
		if(s.at(index)!='.' && c!='.')
		{
			cout<<ans<<endl;
			continue;
		}
		else if(s.at(index)=='.' && c=='.')
		{
			cout<<ans<<endl;
			continue;
		}
		else if(s.at(index)!='.' && c=='.')
		{
			it=st.lower_bound(index);
			r=mp[*it];
			ans-=r.ans;
			p=r.p;
			st.erase(it);
			it=st.lower_bound(index);
			r=mp[*it];
			ans-=r.ans;
			r.p=p;
			r.ans=(*it-p)-1;
			if(r.ans>=2)
			{
				r.ans--;
			}
			else
			r.ans=0;
			ans+=r.ans;
			mp[*it]=r;
		}
		else
		{
			it=st.lower_bound(index);
			r=mp[*it];
			ans-=r.ans;
			p=r.p;
			r.p=index;
			r.ans=(*it-index)-1;
			if(r.ans>=2)
			{
				r.ans--;
			}
			else
			r.ans=0;
			ans+=r.ans;
			mp[*it]=r;
			st.insert(index);
			r.p=p;
			r.ans=(index-p)-1;
			if(r.ans>=2)
			{
				r.ans--;
			}
			else
			r.ans=0;
			ans+=r.ans;
			mp[index]=r;
		}
		s.at(index)=c;
		cout<<ans<<endl;
	}
	return 0;
}
