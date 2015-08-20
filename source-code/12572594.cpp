//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define ff(i,s,e) for(int i=(s);i<=(e);i++)
#define mx(a,b) a=max(a,b)
#define mn(a,b) a=min(a,b)

int N, a[105], mx;
char k;

vector<int> st;
set<int> s;

int main() {
	scanf("%d\n", &N);
	fo(i, N) {
		scanf("%c %d\n", &k, &a[i]);
		if(k == '-') a[i] *= -1;
		if(a[i] > 0) {
			s.insert(a[i]);
		} else {
			if(s.count(-a[i]) == 0) st.push_back(-a[i]);
			else s.erase(-a[i]);
		}
	}
	s.clear();
	for(int j : st) s.insert(j);
	fo(i, N) {
		mx = max(mx, (int) s.size());
		if(a[i] > 0) s.insert(a[i]);
		else s.erase(-a[i]);
		mx = max(mx, (int) s.size());
	}
	printf("%d\n", mx);
	return 0;
}
