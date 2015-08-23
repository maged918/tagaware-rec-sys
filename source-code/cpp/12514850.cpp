//Language: GNU C++11


#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	std::vector<vector<int> > votes;
	for (int cities = 0; cities < m; cities++)
	{
		std::vector<int> v;
		for (int candidate_number = 0; candidate_number < n; candidate_number++)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		votes.push_back(v);
	}
	int count[n] = {0};
	for (int i = 0; i < n; i++)
		count[i] = 0;
	for (int i = 0; i < votes.size(); i++)
	{
		int maxv = votes[i][0];
		int maxi = 0;
		for (int j = 0; j < votes[i].size(); j++)
		{
			if (votes[i][j] > maxv)
			{
				maxv = votes[i][j];
				maxi = j;
			}
		} 
		count[maxi]++;
	}
	int maxv = count[0];
	int maxi = 0;
	for (int i = 0; i < n; i++)
	{
		if (count[i] > maxv)
		{
			maxv = count[i];
			maxi = i;
		}
	}
	maxi++;
	cout << maxi << endl;
	return 0;
}