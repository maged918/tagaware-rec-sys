//Language: GNU C++11


#include <bits/stdc++.h>
#ifdef BUG
    #include "debug.hpp"
#else
    #define DEBUG(var)
    #define EXPECT(expr)
#endif
#define NO_IO_TIE ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
template< class T1, class T2 > inline istream &
operator>>( istream & fin, pair< T1, T2 > & pr )
{ fin >> pr.first >> pr.second; return fin; }
template< class T0, class T1, class T2 > inline istream &
operator>>( istream & fin, tuple< T0, T1, T2 > & t )
{ fin >> get<0>(t) >> get<1>(t) >> get<2>(t); return fin; }
template< class T > inline istream &
operator>>( istream & fin, vector< T > & a ) {
for( auto & u: a) fin >> u; return fin; }
template<class T, size_t n> inline istream &
operator>>( istream & fin, array<T, n> & a ) {
for( auto & u: a) fin >> u; return fin; }
/* @@@ ----------------------------------- */

string probE()
{
    size_t n, m;
    cin >> n >> m;
    string str;
    cin >> str;

    /* pad to ease life */
    const char pad = '+';
    str = pad + str + pad;

    /* mark end of contigous intervals of same letter */
    map<size_t, char> loc;
    for(size_t i = 0; i + 1 < str.length(); ++i)
        if(str[i] != str[i+1])
            loc[i] = str[i];

    loc[str.length() - 1] = str.back();

    for(size_t i = 0; i < m; ++ i)
    {
        size_t l, r, op;
        cin >> l >> r >> op;

        /* find the char at l - 1 and insert the loc */
        auto first = loc.lower_bound(l - 1);
        first = loc.emplace_hint(first, l - 1,first->second);
        ++ first;

        /* populate the count between left & right */
        vector<size_t> cnt(26);
        auto last = loc.lower_bound(r);
        ++ last;

        size_t j = l - 1;
        for(auto iter = first; iter != last; ++ iter)
            cnt[iter->second - 'a'] += min(iter->first, r) - j,
                j = iter->first;

        while(r < last->first)
            -- last;
        ++ last;

        /* remove [first, last) */
        auto iter = loc.erase(first, last);
        // auto iter = loc.upper_bound(l);

        if(op == 1) /* increasing */
        {
            for(size_t j = 0; j < 26; ++ j)
                if(0 < cnt[j])
                {
                    iter = loc.emplace_hint(iter, l + cnt[j] - 1, 'a' + j);
                    ++ iter;
                    l += cnt[j];
                }
        }
        else
            for(size_t j = 25; j < 26; -- j)
                if(0 < cnt[j])
                {
                    iter = loc.emplace_hint(iter, l + cnt[j] - 1, 'a' + j);
                    ++ iter;
                    l += cnt[j];
                }
    }

    size_t l = 0;
    for(const auto pr: loc)
        for(; l < pr.first; ++ l)
            str[l] = pr.second;

    str.pop_back();
    str.pop_back();
    return str;
}

int main( const int argc, char * argv [])
{
    NO_IO_TIE;
    cout << probE();

    return EXIT_SUCCESS;
}
