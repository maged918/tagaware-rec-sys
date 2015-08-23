//Language: MS C++



#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <set>
#include <ctime>
#include <cmath>
#include <assert.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i=a; i<(int)n; i++)
#define per(i,n,a) for (int i=n; i>=a; i--)
#define hk push_back
#define pk pop_back
#define mp make_pair
#define PI 3.141592653589793
#define clr(a) memset(a, 0, sizeof(a))
#define clr1(a) memset(a, -1, sizeof(a))
typedef vector<int> VI;
typedef vector< pair<int, int> > VIP;
typedef vector< pair<int, pair<int, double> > > VIPP;
typedef vector<string> VS;
typedef vector <double> VD;
typedef vector <bool> VB;
typedef long long ll;
#define MAX_V 1000
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
    ll res = 1; a %= mod; for (; b; b >>= 1){ if (b & 1)res = res*a%mod; a = a*a%mod; }return res;
}

int n, q, a, b;
bool c;
char s[100001];
map<int, pair<VI, pair<int, bool> > > sortInfo;

bool cutHead(map<int, pair<VI, pair<int, bool> > >::iterator& it, int pos, VI& cnt) {
    int left = pos - it->first;
    if (left == 0) return 0;
    if (it->second.second.second == 1) {
        rep(j, 0, 26) {
            if (left == 0) break;
            int smaller = min(left, it->second.first[j]);
            left -= smaller;
            cnt[j] += smaller;
            it->second.first[j] -= smaller;
        }
    }
    else {
        per(j, 25, 0) {
            if (left == 0) break;
            int smaller = min(left, it->second.first[j]);
            left -= smaller;
            cnt[j] += smaller;
            it->second.first[j] -= smaller;
        }
    }
    return 1;
}

bool cutTail(map<int, pair<VI, pair<int, bool> > >::iterator& it, int pos, VI& cnt) {
    int left = it->second.second.first - b;
    if (left == 0) return 0;
    if (it->second.second.second == 1) {
        per(j, 25, 0) {
            if (left == 0) break;
            int smaller = min(left, it->second.first[j]);
            left -= smaller;
            cnt[j] += smaller;
            it->second.first[j] -= smaller;
        }
    }
    else {
        rep(j, 0, 26) {
            if (left == 0) break;
            int smaller = min(left, it->second.first[j]);
            left -= smaller;
            cnt[j] += smaller;
            it->second.first[j] -= smaller;
        }
    }
    return 1;
}

void addCntErase(map<int, pair<VI, pair<int, bool> > >::iterator& it, VI& cnt) {
    rep(i, 0, 26) {
        cnt[i] += it->second.first[i];
    }
    sortInfo.erase(it);
}

int main()
{
    cin >> n >> q;
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, q) {
        cin >> a >> b >> c;
        a--; b--;

        VI cnt(26, 0);
        if (i == 0) {
            rep(j, a, b + 1) cnt[s[j] - 'a']++;
            sortInfo[a] = mp(cnt, mp(b, c));
            continue;
        }

        map<int, pair<VI, pair<int, bool> > >::iterator it = sortInfo.upper_bound(a);
        if (it != sortInfo.begin()) {
            map<int, pair<VI, pair<int, bool> > >::iterator it1 = it;
            it1--;
            if (it1->second.second.first >= a) it = it1;
        }

        if (it != sortInfo.end()) {
            int maxIdx = min(b + 1, it->first);
            rep(j, a, maxIdx) cnt[s[j] - 'a']++;
        }
        else rep(j, a, b + 1) cnt[s[j] - 'a']++;

        while (it != sortInfo.end()) {
            bool polarity = it->second.second.second;
            int lPos = it->first, rPos = it->second.second.first;

            map<int, pair<VI, pair<int, bool> > >::iterator it2 = it;           
            it2++;

            int minIdx = max(rPos + 1, a);
            if (it2 == sortInfo.end()) {                
                rep(j, minIdx, b + 1) cnt[s[j] - 'a']++;
            }
            else {
                int maxIdx = min(it2->first, b + 1);
                rep(j, minIdx, maxIdx) cnt[s[j] - 'a']++;
            }


            if (lPos > b) break;
            if (lPos == a && rPos == b) {
                it->second.second.second = c; break;
            }
            else if (lPos <= a && rPos >= b) {
                if (polarity != c) {
                    VI cntH(26, 0), cntT(26, 0);
                    bool bH = cutHead(it, a, cntH);
                    bool bT = cutTail(it, b, cntT);
                    addCntErase(it, cnt);
                    if (bH) sortInfo[lPos] = mp(cntH, mp(a - 1, polarity));
                    if (bT) sortInfo[b + 1] = mp(cntT, mp(rPos, polarity));
                }
                break;
            }
            else if (lPos >= a && rPos <= b) {
                addCntErase(it, cnt);
                it = it2;
            }
            else if (lPos < a && rPos >= a) {
                VI cntH(26, 0);
                bool bH = cutHead(it, a, cntH);
                addCntErase(it, cnt);
                if (bH) sortInfo[lPos] = mp(cntH, mp(a - 1, polarity));
                it = it2;
            }           
            else if (lPos <= b && rPos > b) {
                VI cntT(26, 0);
                bool bT = cutTail(it, b, cntT);
                addCntErase(it, cnt);
                if (bT) sortInfo[b + 1] = mp(cntT, mp(rPos, polarity));
                it = it2;
            }
        }


        bool add = false;
        int cSum = 0;
        rep(i, 0, 26) if (cnt[i]) {
            add = true; //break; } 
            cSum += cnt[i];
        }
        if (add && cSum != b - a + 1) {
            cout << "wrong: " << cSum << ", " << b - a + 1 << endl;
        }
        if (add) sortInfo[a] = mp(cnt, mp(b, c));
    }


    map<int, pair<VI, pair<int, bool> > >::iterator it = sortInfo.begin();
    int ld = 0;
    if (it != sortInfo.end()) {
        rep(i, 0, it->first) printf("%c", s[i]);
        ld = it->first;
    }
    while (1) {
        if (it == sortInfo.end()) break;
        map<int, pair<VI, pair<int, bool> > >::iterator it1 = it;
        it1++;

        if (it->second.second.second) {
            rep(i, 0, 26) {
                rep(j, 0, it->second.first[i]) printf("%c",'a' + i);
            }
        }
        else {
            per(i, 25, 0) {
                rep(j, 0, it->second.first[i]) printf("%c", 'a' + i);
            }
        }
        ld = it->second.second.first + 1;
        if (it1 == sortInfo.end()) break;
        rep(i, it->second.second.first + 1, it1->first) printf("%c", s[i]);
        it++;
    }

    rep(i, ld, n) printf("%c", s[i]);
    cout << endl;

    return 0;
}