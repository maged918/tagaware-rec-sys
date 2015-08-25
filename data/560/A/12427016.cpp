//Language: GNU C++


#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<stack>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*define X first
define Y second
define pb push_back
define MP make_pair
define pii pair<int,int> */
const int OO=0x3f3f3f3f;
int ans=1;
int n;
int main(){
	scanf("%d",&n);
	int x;
	while(n--){
		scanf("%d",&x);
		if(x==1)ans=-1; 
	}
	printf("%d\n",ans);
} 