//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
int arr[1000001];
int main()
{
	int n, x;
	char c;
	cin>>n;
	memset(arr, 0, sizeof arr);
	deque<pair<char, int> >ar;
	for (int i = 0; i<n; i++)
	{
		cin >> c;
		cin >> x;
		if (c == '-'&&!arr[x]){
			ar.push_front(make_pair('+', x));
		}
		if (c == '+')
			arr[x] = 1;
		else if (c == '-')
			arr[x] = 0;
		ar.push_back(make_pair(c, x));
	}
	int ans = 0, t = 0;
	for (int i = 0; i<ar.size(); i++)
	{
		char c = ar[i].first;
		int x = ar[i].second;
		ans = max(ans, t);
		if (c == '+')
            t++;
		else
            t--;
		ans = max(t, ans);
	}
	cout<<ans<<endl;

	return 0;
}
