//Language: GNU C++


#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>

#define sqr(x)  ((x) * (x))
#define rep(i,n)  for(int i = 0;i < (n);++i)
#define fill(x,y) memset(x,y,sizeof(x))
#define REP(v,p,k) for(int v=p;v<=k;++v)
#define sz(c) (int)c.size()
#define pb push_back

typedef long long ll; 
typedef unsigned int uint;

typedef long double ld;
typedef unsigned long long ull;
using namespace std;


int main() {
	ios_base::sync_with_stdio( 0);
//	clock_t start = clock();
//	freopen("INPUT.txt","r",stdin);
//	freopen("OUTPUT.txt","w",stdout);
//	cout << endl << double(clock() - start) / CLOCKS_PER_SEC << endl;	
    double p,q;
    cin >> p >> q;
    bool a = true;
    int i = 1;
    bool z = true;
    int kol1 = 0;
    int kol2 = 0;
    int ans = 0;
    bool pi = false;
    while(i < 2000000){
    	int y = int(sqrt(i));
    	for(int j = 1;j < y + 1;++j){
    		if((i != j && i % j == 0 && j != 1 )|| (i == 1)){
    			z = false;
    			break;
    		}                   	
    	}
    	if(z == true) kol1++;
    	z = true;		
   
    	int u = i;
    	int o = 0;
    	while(u != 0){
    		o = o * 10 + u % 10;
    		u/=10;
    	}	
    	if(i == o){
    		kol2++;
    	}
    	double k1,k2;
    	k1 = double(kol1);
    	k2 = double(kol2);
    //	cout << kol1 << " " << kol2 << " " << i << "\n";
    	if(k1 - (p / q) * k2 > 0.000000001){
    		if(pi == false){
    			ans = i - 1;    
       			pi = true;
       		}
    	}
    	else pi = false;
    	i++;
    }
    cout << ans;
	return 0;
}