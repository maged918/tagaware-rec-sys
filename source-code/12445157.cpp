//Language: GNU C++


#include <bits/stdc++.h>
#define ll long long
#define sc(a) scanf("%lld", &a)
#define pr(a) printf("%lld\n", a)

using namespace std;

ll arr[100005];
ll rep[100005];
ll flag[100005];
stack <ll> st;

int main()
{
	ll n,i;
	sc(n);
	for (i = 1; i <= n; i++) {
		sc(arr[i]);
		if (arr[i] > n) {
			rep[i] = 1;
		}
		else {
			if (flag[arr[i]] == 0) {
				flag[arr[i]] = 1;
			}
			else {
				rep[i] = 1;
			}
		}
	}
	for (i = 1; i <= n; i++) {
		if (flag[i] == 0) {
			st.push(i);
		}
	}
	for (i = 1; i <= n; i++) {
		if (rep[i] == 0)
			printf("%lld ", arr[i]);
		else {
			printf("%lld ", st.top());
			st.pop();
		}
	}
	cout << endl;

	return 0;
}

