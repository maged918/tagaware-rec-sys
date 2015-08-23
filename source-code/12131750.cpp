//Language: GNU C++


#include <bits/stdc++.h>
#define fi first
#define se second
#define all( x ) x.begin(), x.end()
#define pb push_back

const int maxn = 100020;

using namespace std;

typedef long long Lint;
typedef pair<int,int> ii;

int a, q, beg;
int sum[maxn];
char ar[maxn];
set <ii> st[26];

void f( int l, int r, set<ii> &st ) {

    set <ii> :: iterator it = st.lower_bound( ii( l, 0 ) ), it2;
    it2 = it;
    int h = beg;
    if( it != st.begin() ) {
        it--;
        if( it->se > l ) {
            st.insert( ii( it->fi, l ) );
            beg += it->se-l;
            st.erase( it );
        }
        it = it2;
    }
    for(;it != st.end() && it->fi <= r;) {

        if( it->se > r+1 ) {
            st.insert( ii( r+1, it->se ) );
            beg += r - it->fi + 1;
            st.erase( it );
            break;
        }
        beg += it->se - it->fi;
        it2 = it;
        ++it;
        st.erase( it2 );
    }

    if( h != beg ) st.insert( ii( h, beg ) );
}

int main() {

    //freopen("asd.in.rc","r",stdin);

    scanf("%d %d",&a,&q);

    scanf(" %s",ar+1);

    for(int i=1;i<=a;i++)
        ar[i] -= 'a';

    for(int i=1;i<=a;) {
        int j = i;
        while( j <= a && ar[i] == ar[j] ) ++j;
        st[ar[i]].insert( ii( i, j ) );
        i = j;
    }

    while( q-- ) {
        int l, r, c;
        scanf("%d %d %d",&l,&r,&c);

        beg = l;
        if( c ) for(int i = 0; i < 26; i++) f( l, r, st[i] );
        else for(int i = 25; i >= 0; i--) f( l, r, st[i] );

    }

    for(int i=0;i<26;++i) {

        for(set<ii> :: iterator it = st[i].begin() ; it != st[i].end() ; ++it ) {

            for(int j = it->fi; j < it->se; ++j)
                ar[j] = i + 'a';

        }

    }
    printf("%s\n",ar+1);
    return 0;
}
