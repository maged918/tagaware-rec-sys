//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define LL long long
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

int n,hash[103];
int hash2[1123456];

int main()
{	
	cin >> n;
	char c;
	int reg,in[103];
	for(int i=0;i<n;i++)
	{
		cin >> c;
		cin >> reg;
		if(c == '+')
			in[i] = reg;
		else
			in[i] = -1*reg;
	}
	for(int i=0;i<n;i++)
	{
		if(hash2[abs(in[i])] == 1 && in[i] < 0)
				continue;				
		hash2[abs(in[i])] = 1;
		if(in[i] > 0)
		{
			int j = i;
			while( j < n && in[j] != -1*in[i])
			{
				hash[j]++;
				j++;
			}
		}
		if(in[i] < 0)
		{
			int j = i;
			while(j >= 0 && in[j] != -1*in[i])
			{
				hash[j]++;
				j--;
			}
		}
	}
	int ma = -1*INF;
	for(int i=0;i<n;i++)
		ma = max(ma,hash[i]);
	cout << ma << endl;

	return 0;
}
