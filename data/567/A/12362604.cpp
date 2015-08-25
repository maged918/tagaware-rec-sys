//Language: GNU C++11


# include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	long long s;
	long long e;
	long long arr[100001];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	s = arr[0];
	e = arr[n-1];


	for(int i=0;i<n;i++)
	{
		if(i!= n-1 && i)
			cout << min(arr[i]-arr[i-1],arr[i+1]-arr[i])<<" "<<max(arr[i]-s,e-arr[i]);
		else if(i == n-1)
			cout << arr[i]-arr[i-1]<<" "<<arr[i]-arr[0];
		else
			cout << arr[i+1]-arr[i]<<" "<<arr[n-1]-arr[0];

		
		cout <<"\n";
	}
	return 0;
}
