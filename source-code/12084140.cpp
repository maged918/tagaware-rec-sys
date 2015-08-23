//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pos, neg;
int n;

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i)
	{
		int x, a;
		scanf("%d%d", &x, &a);
		if (x > 0) pos.emplace_back(x, -a);
		else neg.emplace_back(-x, -a);
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	int s(0);
	int i;
	for (i = 0; i < pos.size() && i < neg.size(); ++ i)
		s -= pos[i].second + neg[i].second;
	
	if (i < pos.size()) s -= pos[i].second;
	if (i < neg.size()) s -= neg[i].second;

	printf("%d\n", s);

   	return 0;
}
