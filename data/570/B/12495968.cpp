//Language: GNU C++


#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>
#include <ctime>
 
#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define LL long long
 
#define MAX 105
#define AMAX 55
#define MOD 1000000007

#define f(c,d) ((1<<(c))*(d))
 
using namespace std;

int n,m;

int main(){
	scanf("%d%d",&n,&m);
	if(n==1)printf("1\n");
	else if(m==1)printf("2\n");
	else if(m==n)printf("%d\n",n-1);
	else if(n-m-1>m-1-1)printf("%d\n",m+1);
	else printf("%d\n",m-1);
	//system("pause");
    return 0;
}
