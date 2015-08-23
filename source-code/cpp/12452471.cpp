//Language: GNU C++11


#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin>>t;
	float s;
	cin>>s;
	int q;
	cin>>q;
	int i=0;
	float sp=0;
	bool comp=false;
	while(comp!=true)
	{
		i++;
		sp = s*q;
		if(sp>=t)
			break;
		else
			s = sp;
	}
	cout<<i;
	return 0;
}