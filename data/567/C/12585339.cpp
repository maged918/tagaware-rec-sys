//Language: GNU C++


#include <cstdio> 
#include <cstring> 
#include <map> 
#include <iostream> 
using namespace std; 
typedef long long LL; 
map<int, LL> s1, s2; 
int main() 
{ 
    LL n, k; 
    LL ans, x; 
	cin >> n >> k; 
	ans = 0; 
	for(int i = 0; i < n; i++) 
	{ 
	    scanf("%I64d",&x); 
		if(x%k == 0) 
		{ 
		    LL t1 = s2[x/k]; 
			ans += t1; 
			LL t2 = s1[x/k]; 
			s2[x] += t2; 
		} 
	    s1[x]++; 
	} 
	cout << ans << endl; 
    return 0; 
} 
	 	  	 	 		  	  		   				 	  	