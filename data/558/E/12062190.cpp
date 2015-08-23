//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

#define fillchar(a, s) memset((a), (s), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define rep(it, v) for (auto it = (v).begin(); it != (v).end(); it++)

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 10;

int N, Q;
char S[MAXN];
pii num[26];	//pair(char, cnt)
set<pii> st;	//pair(start of range, char)

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
	}
	scanf("%d %d %s", &N, &Q, S);
	for (int i = 0; i < N; i++) {
		st.insert(pii(i, S[i] - 'a'));
	}
	for (int a, b, t; Q--; ) {
		scanf("%d %d %d", &a, &b, &t);
		a--;
		for (int i = 0; i < 26; i++) {
			num[i] = pii(i, 0);
		}
		//ok now work on clearing between
		auto it = prev(st.upper_bound(pii(a, 26)));
		it = st.insert(pii(a, it->second)).first;
		auto jt = prev(st.upper_bound(pii(b, 26)));
		if (b != N) {
			jt = st.insert(pii(b, jt->second)).first;
		} else {
			jt = st.end();
		}
		while (it != jt) {
			auto cur = it++;
			int rt = (it == st.end() ? N : it->first);
			num[cur->second].second += (rt - cur->first);
			st.erase(cur);
		}
		if (!t) {
			reverse(num, num + 26);
		}
		//insert them now
		for (int i = 0, j = a; i < 26; i++) {
			int ct = num[i].second;
			if (ct) {
				st.insert(pii(j, num[i].first));
				j += ct;
			}
		}
	}
	auto jt = st.begin();
	auto it = jt++;
	while (true) {
		int rt = (jt == st.end() ? N : jt->first);
		int diff = rt - it->first;
		for (int i = 0; i < diff; i++) {
			putchar(it->second + 'a');
		}
		if (jt == st.end()) {
			break;
		}
		it++;
		jt++;
	}
}