//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

#define dbgs(x) cerr << (#x) << " --> " << (x) << ' '
#define dbg(x) cerr << (#x) << " --> " << (x) << endl

#define foreach(i,x) for(type(x)i=x.begin();i!=x.end();i++)
#define FOR(ii,aa,bb) for(int ii=aa;ii<=bb;ii++)
#define ROF(ii,aa,bb) for(int ii=aa;ii>=bb;ii--)

#define type(x) __typeof(x.begin())

#define orta (bas + son >> 1)
#define sag (k + k + 1)
#define sol (k + k)

#define pb push_back
#define mp make_pair

#define nd second
#define st first

#define endl '\n'

typedef pair < int ,int > pii;

typedef long long ll;

const long long linf = 1e18+5;
const int mod = 1e9+7;
const int logN = 17;
const int inf = 1e9;
const int N = 1e5+5;

int i, j, k, n, m, x, y, t, q, z;

string str;

class node {
	public:
	int cnt[26], L;
	node() { memset(cnt, 0, sizeof cnt); L = -1; }	
} ST[N << 2], emp;

node merge(node x, node y) {
	node temp;
	FOR(i,0,25) temp.cnt[i] = x.cnt[i] + y.cnt[i];
	return temp;
}

void upd(int k,int x,int y, int t) {
	memset(ST[k].cnt, 0, sizeof ST[k].cnt);
	ST[k].cnt[t] = y - x + 1;
	ST[k].L = t;
}

void push(int k,int bas, int son) {
	if(ST[k].L == -1) return ;
	upd(sol,bas,orta,ST[k].L);	
	upd(sag,orta+1,son,ST[k].L);	
	ST[k].L = -1;
}

node init(int k,int bas,int son) {
	ST[k].L = -1;
	if(bas == son) { ST[k].cnt[str[bas]-'a']++; return ST[k]; }
	return ST[k] = merge(init(sol, bas, orta), init(sag, orta + 1, son));
}

node query(int k,int bas,int son,int x,int y) {
	if(bas > y || son < x) return emp;
	if(x <= bas && son <= y) return ST[k];
	push(k,bas,son);
	return merge(query(sol, bas, orta, x, y), query(sag, orta+1, son, x, y));	
}

node update(int k,int bas,int son,int x,int y,int t) {
	if(bas > y || son < x) return ST[k];
	if(x <= bas && son <= y) {
		upd(k,bas,son,t);
		return ST[k];
	}
	push(k,bas,son);
	return ST[k] = merge(update(sol, bas, orta, x, y, t), update(sag, orta + 1, son, x, y, t));	
}

int main(){
	
	ios_base::sync_with_stdio(false);

	cin >> n >> q >> str; str = '0' + str;

	init(1,1,n);

	FOR(i,1,q) {
		
		cin >> x >> y >> z;

		node t = query(1,1,n,x,y);
	
		if(z == 1) {
			int last = x;
			FOR(i,0,25) {  update(1,1,n,last,last+t.cnt[i]-1,i); last += t.cnt[i]; }
		}
		
		else {
			int last = x;
			ROF(i,25,0) {  update(1,1,n,last,last+t.cnt[i]-1,i); last += t.cnt[i]; }
		}
		
	}

	FOR(i,1,n) {
		
		node temp = query(1,1,n,i,i);

		FOR(i,0,25) if(temp.cnt[i]) cout << (char)(i+'a'); 
		
	} cout << endl;

	return 0;
}
