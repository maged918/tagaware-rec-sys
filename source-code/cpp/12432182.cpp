//Language: GNU C++


#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<string>
#include<set>
using namespace std;

#define LL long long
#define ULL unsigned long long
int n,k,a;
int m,num;
int ans=-1;
set<int> S;
set<int> ::iterator it;
int main(void){
	cin>>n>>k>>a;
	a++;
	int have = (n+1)/a;
	cin>>m;
	S.insert(0);
	S.insert(n+1);
	int u,d;
	for(int i=1;i<=m;i++){
		cin>>num;
		u = *S.lower_bound(num);
		it = S.lower_bound(num);
		it--;
		d = *it;
		int now = (u-d)/a;
		int nt = (num-d)/a+(u-num)/a;
		have = have - (now - nt);
		S.insert(num);
		if(have<k){
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}