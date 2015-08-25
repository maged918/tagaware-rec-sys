//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define oo 1000000000
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

char s[300005];
int ans = 0;
set<pii> st;

int main(){
	int n, m, j;
	scanf("%d %d", &n, &m);
	scanf(" %s", s);
	for(int i = 0; i < n; ){
		if(s[i] != '.') { i++; continue; }
		for(j = i; s[j] == '.' && j < n; j++);
		st.insert(pii(i, j-1));
		ans += j-i-1;
		i = j;
	}
	while(m--){
		int pos; char c;
		scanf("%d %c", &pos, &c);
		pos--;
		//printf("No teste %d %c\n", pos, c);
		if(s[pos] == '.' && c != '.'){
			set<pii>::iterator it = st.lower_bound(pii(pos, oo)); --it;
			int ini = it->fst;
			int fim = it->snd;
			st.erase(it);
			if(ini != fim) {
				if(ini == pos) { ans--; st.insert(pii(ini+1, fim)); }
				else if(fim == pos) { ans--; st.insert(pii(ini, fim-1)); }
				else { ans = max(0, ans-2); st.insert(pii(ini, pos-1)); st.insert(pii(pos+1, fim)); }
			}	
		}
		else if(s[pos] != '.' && c == '.') {
			if(st.empty()) { st.insert(pii(pos, pos)); printf("%d\n", ans); s[pos] = c; continue; }
			set<pii>::iterator it, it2;
			it = st.lower_bound(pii(pos, oo));
			it2 = it;
			--it;
			pii p1 = (*it);
			if(it2 == st.end()) {
				if(pos == p1.snd+1) { st.insert(pii(p1.fst, pos)); ans++; st.erase(it); }
				else { st.insert(pii(pos, pos)); }
			}
			else {
				pii p2 = *it2;
				//printf("[%d, %d] [%d, %d]\n", p1.fst, p1.snd, p2. fst, p2.snd);
				if(pos == p1.snd+1 && pos == p2.fst-1) { 
					st.insert(pii(p1.fst, p2.snd)); 
					ans += 2; 
					st.erase(it2); 
					st.erase(it);
				}
				else if(pos == p1.snd+1) { st.insert(pii(p1.fst, pos)); ans++; st.erase(it); }
				else if(pos == p2.fst-1) { st.insert(pii(pos, p2.snd)); ans++; st.erase(it2); }
				else { st.insert(pii(pos, pos)); }
			}
		}
		s[pos] = c;
		printf("%d\n", ans);
	}
	return 0;
}
