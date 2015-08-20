//Language: MS C++


#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <limits>
using namespace std;
#define LL long long
#define mod 1000000007
typedef pair<int, int> pii;
set <pii> st;
int n, m, re;
char s[300003];

void input(){


}

void solve(){
	scanf("%d %d %s", &n, &m, s);
	for (int i = 0; i < n - 1; i++){
		if (s[i] != '.' || s[i + 1] != '.')
			continue;
		int ri = i;
		for (int j = i + 1; j < n; j++){
			if (s[j] != '.')
				break;
			else
				ri = j;
		}

		re += ri - i;
		st.insert(pii(i, ri));
		i = ri;

	}

	int a;
	char t[3];
	for (int i = 0; i < m; i++){
		scanf("%d %s", &a, t);
		a--;
		if (s[a] == t[0] || 
			(s[a] != '.' && t[0] != '.')){
			printf("%d\n", re);
			continue;
		}
		s[a] = t[0];
		if (s[a] == '.'){
			pii nxt = pii(a, a);
			if (a && s[a - 1] == '.')
				nxt.first--;
			if (a + 1 < n && s[a + 1] == '.')
				nxt.second++;
			auto le = st.lower_bound(pii(a, 0));
			if (le != st.begin()){
				le--;
				if ((*le).second == a - 1){
					nxt.first = (*le).first;
					re -= (*le).second - (*le).first;
					st.erase(le);
				}
			}

			auto ri = st.lower_bound(pii(a, 0));
			if (ri != st.end() && (*ri).first == a + 1){
				nxt.second = (*ri).second;
				re -= (*ri).second - (*ri).first;
				st.erase(ri);
			}

			if (nxt.first < nxt.second){
				re += nxt.second - nxt.first;
				st.insert(nxt);
			}
		}
		else{
			auto it = st.lower_bound(pii(a, 0));
			if (it != st.end() && (*it).first == a){
				re -= (*it).second - (*it).first;
				pii nxt = pii(a + 1, (*it).second);
				st.erase(it);
				if (nxt.first < nxt.second){
					re += nxt.second - nxt.first;
					st.insert(nxt);
				}
				
			}
			else if (st.begin() != it){
				it--;
				if ((*it).first <= a && a <= (*it).second){
					pii le = pii((*it).first, a - 1);
					pii ri = pii(a + 1, (*it).second);
					re -= (*it).second - (*it).first;
					st.erase(it);
					if (le.first < le.second){
						re += le.second - le.first;
						st.insert(le);
					}
					if (ri.first < ri.second){
						re += ri.second - ri.first;
						st.insert(ri);
					}
				}
			}
				
		}
		printf("%d\n", re);
	}
}

int main(void){
//	freopen("input.txt","r",stdin);
	solve();
	return 0;
}