//Language: GNU C++11


/*           !         !
            ! !       ! !
           ! . !     ! . !
             ^ ^ ^ ^ ^ ^
           ^             ^
      ___^  (0)   _   (0)  ^___
    ____^        '"'        ^____
       ^          ^          ^
     ^     * * * * * * * *     ^
    ^   *   /\   /\   /\    *    ^
   ^   *                     *    ^
  ^   *   /\   /\   /\   /\   *    ^
 ^   *                         *    ^
 ^  *                           *   ^
 ^  *                           *   ^
  ^ *                           *  ^
   ^*                           *^
    ^ *                       * ^
    ^  *                     *  ^
      ^ *        ) (        * ^
          ^^^^^^^^ ^^^^^^^^ */
#include <algorithm>
#include <cstdio>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define umap std::unordered_map
#define uset std::unordered_set
#define qnan std::numeric_limits<double>::quiet_NaN()
#define infin std::numeric_limits<double>::infinity()
#define all(x) (x).begin(), (x).end()
#define in(a, x) ((x).find(a) != (x).end())
#define Odd(x) (x & 1)
#define Even(x) !(x & 1)
#define For(i, a, n) for( int i = a; i < n; ++i )
#define Rof(i, a, n) for( int i = n - 1; i >= a; --i )
#define oo INT_MAX

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef long long dint;
typedef unsigned long long udint;

using namespace std;

struct LR
{
	dint left;
	dint right;
};
bool operator< (const LR& lr, const LR& lr2) { return lr.left < lr2.left; }
bool operator< (const LR& lr, dint x) { return lr.left < x; }

int main(int argc, char**)
{
	if( argc > 1 )
	{
		freopen("debug/1.in", "r", stdin);
		freopen("debug/out.txt", "w", stdout);
	}
	ios::sync_with_stdio(false);
	cin.tie(0);

    int h, q;
    cin >> h >> q;

    deque<LR> v;
    vector<LR> nai;
    nai.reserve(q);
    dint aruMin = 1LL << (h - 1);
    dint aruMax = 1LL << h;

    int i, a;
    dint l, r;
    For( j, 0, q )
    {
        cin >> i >> l >> r >> a;
        l = l << (h - i);
        r = (r + 1) << (h - i);
        if( a )
        {
            aruMin = max(aruMin, l);
            aruMax = min(aruMax, r);
        }
        else nai.push_back({l, r});
    }
    sort(all(nai));

    if( aruMin < aruMax )
    {
        v.push_back({aruMin, aruMax});

        for( auto& pa : nai )
        {
            l = pa.left;
            r = pa.right;
            auto iL = lower_bound(all(v), l);
            if( iL != v.begin() )
            {
                auto iPrev = prev(iL);
                if( iPrev->right > l )
                {
                    dint rPrev = iPrev->right;
                    iPrev->right = l;

                    if( rPrev > r )
                    {
                        // divide
                        v.insert(iL, {r, rPrev});
                        if( v.size() > 2 ) break;
                        continue;
                    }
                }
            }

            auto iR = lower_bound(all(v), r);
            if( iR != v.begin() )
            {
                if( prev(iR)->right > r ) { --iR; iR->left = r; }
            }
            v.erase(iL, iR);
        }
    }

    if( !v.size() )
    {
        cout << "Game cheated!" << endl; return 0;
    }
    if( v.size() > 1 || v.front().right - v.front().left > 1 )
    {
        cout << "Data not sufficient!" << endl; return 0;
    }
    cout << v.front().left << endl;
}
