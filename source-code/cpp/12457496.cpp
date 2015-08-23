//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

int nump[1199912];
int palin[1199912];

int prime(int n)
{	int a=2;
	int ind=0;
	while(a<=n)
	{int ch=0;
	for(int i=2;i<=sqrt(a);i++)
	{	if(a%i==0)
		{ch=1;break;}
	}
	if(ch==0)ind++;
	nump[a]=ind;
	a++;
	}
	return ind;
}

int prim[1199914]={0};

int prime2(int n)
{	
	for(int i=2;i<=n;i++)
	{	for(int j=2;j<=n/i;j++)
		{	
			prim[i*j]=-1;
		}
	}
	int add=0;
	for(int i=2;i<=n;i++)
	{	if(prim[i]!=-1)
		{	add++;
		}
		nump[i]=add;
	}
}
int palin1(int num)
{	int siz=0;
	int save=num;
	int other=0;
	while(save!=0)
	{	siz++;
		other=other*10+save%10;
		save=save/10;
	}
	if(other==num)return 1;
	else return 0;
}

int palindrome(int n)
{	int num=1;
	int ind=1;
	int add=0;
	while(num<=n)
	{	int ch=palin1(num);
		if(ch==1)add++;
		palin[num]=add;
		num++;
	}
}
double ab(double a)
{	if(a<0)return -a;else return a;
}

double dif(double a,double b)
{	return ab(a-b);
}

int find(double rate)
{	int numw=-1;

	for(int i=1;i<=1199911;i++)
	{	double numb=nump[i];
		double numr=palin[i];
		if(rate*numr>=numb)
		{	if(numw<i)numw=i;
		}
		
	}
	return numw;
}
int main()
{	palindrome(1199911);
	prime2(1199911);
	nump[1]=0;palin[1]=1;
	double p,q;
	cin>>p>>q;
	cout<<find(p/q)<<endl;
}
