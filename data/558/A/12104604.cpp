//Language: GNU C++


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
	long long int i,n,a,x;
	cin>>n;
	vector<pair<long long int,long long int> > neg,pos;
	for(i=0;i<n;i++)
	{
		cin>>x>>a;
		if(x<0)
			neg.push_back(pair<long long int,long long int>(x,a));
		else
			pos.push_back(pair<long long int,long long int>(x,a));
	}
	sort(neg.begin(),neg.end(), std::greater<pair<long long int,long long int> >());
	sort(pos.begin(),pos.end());
	long long int result=0;
	for(i=0;i<pos.size() && i<neg.size();i++)
	{
		result+=pos[i].second;
		result+=neg[i].second;
	}
	if(i<pos.size())
		result+=pos[i].second;
	else if(i<neg.size())
		result+=neg[i].second;
	cout<<result;
	

	return 0;
}