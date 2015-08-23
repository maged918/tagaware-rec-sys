//Language: GNU C++11


// fenwick tree
#include <bits/stdc++.h>
using namespace std;

int n , ord;
const int size = 500000;
int L[size+10] , R[size+10];
vector<int> ve[size+10];
vector<int> depth[size+10];
vector<pair<int,int>> q[size+10];
bool res[size+10];
char str[size+10];

struct data {
    int var[size+10];
    void init() {
        memset( var , 0 , sizeof(var) );
    }
    int lowBit( int x ) {
        return x & -x;
    }
    void update( int x , int y ) {
        while ( x<=size ) {
            var[x] += y;
            x += lowBit(x);
        }
    }
    int query( int x ) {
        int sum = 0;
        while ( x ) {
            sum += var[x];
            x -= lowBit(x);
        }
        return sum;
    }
};
data tree[26];

void dfs( int u , int h ) {
    L[u] = ++ ord;
    depth[h].push_back(u);
    for ( const auto& v : ve[u] ) {
        dfs( v , h+1 );
    }
    R[u] = ord;
}

int main() {
    int m , x , y;
    while ( ~scanf("%d %d",&n,&m) ) {
        for ( int i = 0 ; i<26 ; ++i ) {
            tree[i].init();
        }
        for ( int i = 0 ; i<=n ; ++i ) {
            ve[i].clear();
            depth[i].clear();
            q[i].clear();
        }
        memset( res , true , sizeof(res) );
        for ( int i = 2 ; i<=n ; ++i ) {
            scanf("%d",&x);
            ve[x].push_back(i);
        }
        scanf("%s",str+1);
        ord = 0;
        dfs( 1 , 1 );
        for ( int i = 1 ; i<=m ; ++i ) {
            scanf("%d %d",&x,&y);
            q[y].emplace_back( x , i );
        }
        for ( int i = 1 ; i<=n ; ++i ) {
            if ( !depth[i].size() ) {
                break;
            }
            for ( const auto& u : depth[i] ) {
                tree[str[u]-'a'].update( L[u] , 1 );
            }
            for ( const auto& pi: q[i] ) {
                int odd = 0;
                for ( int j = 0 ; j<26 ; ++j ) {
                    odd += ( tree[j].query( R[pi.first] ) - tree[j].query( L[pi.first]-1 ) )& 1;
                }
                res[pi.second] = odd<=1;
            }
            for ( const auto& u : depth[i] ) {
                tree[str[u]-'a'].update( L[u] , -1 );
            }
        }
        for ( int i = 1 ; i<=m ; ++i ) {
            printf("%s\n",res[i]?"Yes":"No");
        }
    }
    return 0;
}
