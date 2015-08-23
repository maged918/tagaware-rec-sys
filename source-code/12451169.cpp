//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

const int Max = 1200000;

bool prime[Max],palindrome[Max];

void seive()
{
	fill(prime,prime+Max,true);
	for (int i = 2; i*i < Max; ++i) {
		if(prime[i]) {
			for (int j = i*i; j < Max; j+=i) {
				prime[j]=false;
			}
		}
	}
	prime[1]=false;
}

bool checkpalindrome(int v)
{
	string a="";
	while(v!=0) {
		a=a+(char)(v%10+'0');
		v/=10;
	}
	int i=0,j=a.size()-1;
	while(i<j) {
		if(a[i]!=a[j])
			return false;
		i++;j--;
	}
	return true;
}

void palin()
{
	for (int i = 1; i < Max; ++i) {
		if(checkpalindrome(i))
			palindrome[i]=true;
		else
			palindrome[i]=false;
	}
}

int main()
{
	int ans=-1,p,q,c_prime=0,c_palin=0;
	scanf("%d %d",&p,&q);
	seive();
	palin();
	for (int i = 1; i < Max; ++i) {
		if(prime[i]){
			c_prime++;
		}
		if(palindrome[i]){
			c_palin++;
		}
		if(p*1LL*c_palin-q*1LL*c_prime>=0)
			ans=max(ans,i);
		// printf("%d %d %d %f\n",i,c_prime,c_palin,(double)c_prime/(double)c_palin);
	}
	if(ans!=-1)
		printf("%d\n", ans);
	else
		printf("Palindromic tree is better than splay tree\n");
}