//Language: GNU C++


#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
int find(int i, int no, int a[1000])
{
	for (int j = 0; j < no; j++)
		if (a[j] == i)
			return 1;
	return 0;
}
int main()
{
	int no, a[1000];
	cin>>no;
	for (int i = 0; i < no; i++)
		cin>>a[i];
	if (find(1,no,a) == 1)
		cout<<"-1"<<endl;
	else 
		cout<<"1"<<endl;
}
