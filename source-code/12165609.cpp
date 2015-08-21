//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+5;
#define debug(x) cout << #x << " = " << x << endl

int main(){
	//eopen("input.txt","r",stdin);
	int n,tmp;
	int mn = 1e9;
	scanf("%d",&n);
	while( n-- ){
		scanf("%d",&tmp);
		mn = min(mn,tmp);
	}
	if( mn == 1) puts("-1");
	else puts("1");
    return 0;
}
