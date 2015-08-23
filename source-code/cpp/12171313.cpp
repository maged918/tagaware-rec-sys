//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
const int inf=0x7f7f7f7f;


int main(){
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
#endif

    int a[10];
    for (int i = 1; i <= 6; ++i)
    {
    	cin >> a[i];
    }

    ll ans=a[2]-a[5];
    int b=a[2];
    while(a[1] || a[3] || a[4] || a[6]){
	    while(a[1] && a[3]){
	    	b++;
	    	ans+=b*2;
	    	a[1]--;
	    	a[3]--;
	    }

	    while(a[1] && a[4]){
	    	b;
	    	ans+=b*2;
	    	a[1]--;
	    	a[4]--;
	    }

	    while(a[6] && a[3]){
	    	b;
	    	ans+=b*2;
	    	a[6]--;
	    	a[3]--;
	    }

	    while(a[6] && a[4]){
	    	b--;
	    	ans+=b*2;
	    	a[6]--;
	    	a[4]--;
	    }
	}

    cout << ans << endl;

    return 0;
}
