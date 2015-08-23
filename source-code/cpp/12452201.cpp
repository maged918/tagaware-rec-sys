//Language: GNU C++


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int p,q,pi[10000000],rub[10000000],maxx;
double a,l[10000000];
vector <int> k;

bool check1(int a)
{
	if(a==1) return false;
	for(int i=0;i<k.size()&&k[i]<=sqrt(a);i++)
		if(a%k[i]==0) return false;
	k.push_back(a);
	return true;
}

bool check2(int a)
{
	int b[10],i=0;
	while(a>0)
	{
		b[i]=a%10;
		a/=10;
		i++;
	}
	for(int j=0;j<i;j++)
		if(b[j]!=b[i-1-j]) return false;
	return true;
}

int main()
{
	cin >> p >> q;
	a=((double) p)/q;
	//cout << a << endl;
	rub[0]=0; pi[0]=0;
	for(int i=1;i<10000000;i++)
	{
		if(check1(i)==true) pi[i]=pi[i-1]+1; else pi[i]=pi[i-1];
		if(check2(i)==true) rub[i]=rub[i-1]+1; else rub[i]=rub[i-1];
		l[i]=((double)pi[i])/rub[i];
	}
	//for(int i=1;i<42;i++)
	//	cout << i << " "<<pi[i] << " " << rub[i] << endl;
	for(int i=1;i<10000000;i++)
		if(a>=l[i]) maxx=i;
	//cout << "1422" << " "<<pi[1422] << " " << rub[1422] << " " <<l[1422]<< endl;
	if(maxx==0||maxx==9999999) cout << "Palindromic tree is better than splay tree"; else cout << maxx;
	//getchar();getchar();
	return 0;
}
