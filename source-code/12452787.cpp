//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <math.h>
#include <limits.h>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <map>
#include <stack>
using namespace std;
//mehulagarwal
#define ll         long long
#define S(x)       scanf("%d", &x)
#define Sl(x)      scanf("%lld", &x)
#define Sd(x)      scanf("%lf", &x)
#define P(x)       printf("%d\n", x)
#define Pl(x)      printf("%lld\n", x)
#define Pd(x)      printf("%lf\n", x)
#define Pblank()   printf(" ")
#define mem(x,y)   memset(x,y,sizeof(x))
#define F(x,y,z,i) for (x = y; x < z; x = x + i)
#define mod 1000000007

int dppa[1500005], dppr[1500005];
int isprime[1500005]={0};

int main()
{
    int i=2,j,p,q,temp,te;
    isprime[0]=1;
    isprime[1]=1;
    for(i=2;i*i<=1500004;i++) {
        if(isprime[i]==1)
            continue;
        for(j=i*2;j<=1500004;j+=i)
        {
            isprime[j]=1;
        }
    }

    dppr[1] = 0;
    for (i = 2; i < 1500003; i++) {
        if (isprime[i] == 0) {
            dppr[i] = dppr[i-1] + 1;
        } else {
            dppr[i] = dppr[i-1];
        }
    }

    string s1,s;
    stack <int> sta;
    dppa[0] = 0;
    for (i = 1; i < 1500005; i++) {
        temp = i;
        s = "";
        s1 = "";
        while (temp > 0) {
            te = temp % 10;
            temp = temp / 10;
            s1.push_back(te + '0');
            sta.push(te);
        }
        while (!sta.empty()) {
            s.push_back(sta.top() + '0');
            sta.pop();
        }
        int len = s.length();
        if (s == s1) {
            dppa[i] = dppa[i-1]+1;
        } else {
            dppa[i] = dppa[i-1];
        }
    }

    cin >> p >> q;

    for (i = 1500000; i >= 1; i--) {
        if (q*dppr[i] <= p*dppa[i]) {
            cout << i << endl;
            break;
        }
    }
    if (i == 0) {
        cout << "Palindromic tree is better than splay tree\n";
    }

	return 0;
}
