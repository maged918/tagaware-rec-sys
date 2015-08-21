//Language: GNU C++


# include <bits/stdc++.h>
# define ll long long
# define pll pair < ll, ll >
# define fs first 
# define se second
# define mp make_pair
# define pb push_back
# define rep(i, n) for( ll (i) = 0; (i) < (n); (i)++)
# define REP(i, n) for( ll (i) = 1; (i) <= (n); (i)++)
# define wl(i) while((i)--)
# define vec vector < ll >
# define ma map < ll, ll >
# define sf(i) scanf("%lld",&(i))
# define pr(i) printf("%lld ",(i))
# define prn(i) printf("%lld\n",(i))
# define cpr(i) cout<<(i)<<" "
# define cprn(i) cout<<(i)<<endl
# define csf(i) cin>>(i)
# define srt(v) sort( v.begin(), v.end() )
# define srtc(v, x) sort( v.begin(), v.end(), x)
# define srtr(v) sort( v.begin(), v.end(), greater< ll >())
# define mod 1000000007
# define MAX_PRIME 0
# define SEGMENT_MAX 0

using namespace std;

bool compare( pll &a, pll &b ){
	return (a.first > b.first || ( a.first == b.first && a.second < b.second));
}

int main(){
	ll n, m;
	sf(n); sf(m);
	ll mn[n];
	memset(mn, 0, sizeof mn);
	rep(i, m){
		vector < pair < ll, ll> > p;
		rep(j, n){
			ll v;
			sf(v);
			p.pb(mp(v, j));
		}
		sort(p.begin(), p.end(), compare);
		mn[p[0].second] += 1; 
	}
	vector < pll > tmp;
	rep(i, n){
		tmp.pb(mp(mn[i], i));
	}
	sort(tmp.begin(), tmp.end(), compare);
	cout<<tmp[0].second + 1<<endl;
	return 0;
}