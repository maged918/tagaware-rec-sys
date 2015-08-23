//Language: GNU C++11


/* Copyright 2015 Fyodor Dmitrievich Listvin */
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define pname "b_lib"
#ifdef DBG
#define WR(smth) smth
#else
#define WR(smth)
#endif
#define DB(a) #a " == " << (a) << ";	"
#define REP(n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i,n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long int lli;

const int NMAX = (int)1e6;
const int inf = (int)2e9;

int N;

//~ int sum(int x){
	//~ int R = 0;
	//~ for (int i = x; i >= 0; i = (i & (i+1)) - 1)
		//~ result += t[i];
	//~ return R;
//~ }
//~ 
//~ void inc(int x, int delta){
	//~ for (int i = x; i < N; i = (i | (i+1)))
		//~ t[i] += delta;
//~ }

int solve(){
	vector <bool> known(NMAX+1);
	vector <int> history;
	
	char c; int id;
	REP(N) cin >> c >> id, history.pb((c == '-' ? -1 : 1) * id);
	
	int cur = 0;
	REP(N)
		if (history[i] < 0){
			if (!known[-history[i]])
				cur += !known[-history[i]];
				//~ history[i] = 0;
		}
		else
			known[history[i]] = true;
			
	int M = cur;
	REP(N){ cerr << DB(cur) DB(history[i]) << endl; if (history[i]) M = max(M, cur += history[i] > 0 ? 1 : -1); }
	
	return M;
}

int main(){
	#ifdef DBG
		freopen(pname".in","r",stdin);
		cerr << "	DBG defined, output will appear here\n\n";
	#endif

	while (cin >> N) cout << solve() << endl;

	#if (defined STRESS) || (defined DBG)
		cerr << clock()/(CLOCKS_PER_SEC/1000) << "ms.\n";
	#endif
	return 0;	
}
