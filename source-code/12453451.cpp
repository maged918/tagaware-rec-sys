//Language: GNU C++


#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
long long f[4001][4001],sum[4001],C[4001][4001],ans,mod=1000000007;
int n;
int main(){
	scanf("%d",&n);
	if(n==1){
		printf("1\n");return 0;
	}
	f[1][1]=1;sum[0]=1;
	//for(int i=2;i<=n;i++) for(int j=1;j<=i;j++) f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
	//for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) sum[i]=(sum[i]+f[i][j])%mod;
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	sum[1]=1;sum[0]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++) sum[i]=(sum[i]+(C[i-1][j]*sum[j])%mod)%mod;
	}
	for(int j=1;j<=n;j++) ans=(ans+(C[n][j]*sum[n-j])%mod)%mod;
	cout<<ans<<endl;
	return 0;
}
