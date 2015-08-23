//Language: GNU C++


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=200050;
typedef long long llo;
char cc;
int n,m,ans,gs,x;
int a[1000500];
int main(){
	scanf("%ld\n",&n);
	gs=ans=0;
	for(int i=1;i<=n;++i){
		scanf("%c%ld\n",&cc,&x);
		if(cc=='+'){
			if(++gs>ans)ans=gs;
			a[x]=1;
		}else{
			if(a[x]){
				a[x]=0;
				--gs;
			}else ++ans;
		}
	}
	printf("%ld\n",ans);
	return 0;
}
