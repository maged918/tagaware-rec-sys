//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <map>
#define ll long long
#define ull unsigned long long
#define FOR(i, n) for (int i = 0; i < n; i++)
#define si(x) scanf("%d", &x);
using namespace std;

void findNext(int* x, vector <bool> &b)
{
	for(int i=*x; i<b.size(); i++)
	{
		if(!b[i])
		{
			*x = i;
			break;
		}
	}
	b[*x] = true;
}

int main()
{
	int t;
	cin>>t;
	vector <int> v(t, 0);
	vector <bool> b(t+1, false);
	map <int, int> m;
	int z=1;
	for(int i=0; i<t; i++)
	{
		cin>>v[i];
		if(v[i] <= t)
			b[v[i]] = true;
		if(m.find(v[i]) == m.end())
			m[v[i]] = 1;
		else
			m[v[i]]++;
	}	
	findNext(&z, b);
	for(int i=0; i<t; i++)
	{
		if(m[v[i]] >= 2 || v[i] >t)
		{
			m[v[i]]--;
			v[i] = z;
			findNext(&z, b);
		}
	}
	for(int i=0; i<t; i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<"\n";

	return 0;
}