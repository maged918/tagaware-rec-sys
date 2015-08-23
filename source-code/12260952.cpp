//Language: MS C++


#include<iostream>
using namespace std;

int main()
{
	int min[3];
	int max[3];
	int N;
	cin >> N;
	int ans[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> min[i] >> max[i];
		ans[i] = min[i];
	}
	int remain = N - min[0] - min[1] - min[2];
	for (int i = 0; i < 3; i++)
	{
		if (remain>=(max[i] - min[i])) ans[i] = max[i], remain -= (max[i] - min[i]);
		else ans[i] = min[i] + remain, remain = 0;
	}
	cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}
	  	   	 						  	    	       	