//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

const int  INF = std::numeric_limits<int>::max()/3;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define eps (1.0e-9)
#define are_equal(a,b)fabs((a)-(b))<eps
#define abs_val(a)((a)>=0)?(a):(-(a))
#define LS(b)(b&(-(b))) // Least significant bit
#define DEG_to_RAD(a)(((a)*PI)/180.0) // convert to radians
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}

/**
 * __builtin_popcount(int d) // count bits
 * strtol(s, &end, base); // convert base number
 */
//----------------------------------------------------------------------//

vector<vi> tree;
vi IN,OUT,vis;
string labels;
int chars[500100][26];
vii H[2*500100];
int A[30];
bool isPalin(vi freq){
    int odds  = 0;
    for (int j = 0; j < 26; ++j) {
        odds += freq[j]&1;
    }
    return odds <= 1;
}

int cnt;

void dfs(int u, int h){

//  printf("u = %d\n", u );

    IN[u] = ++cnt;

    int x = H[h].back().second ^ A[labels[u-1] - 'a'];

    H[h].push_back(ii(IN[u], x) );

    for (int i = 0; i < tree[u].size(); ++i)
        dfs(tree[u][i], h + 1);

    OUT[u] = ++cnt;
}

void test(){
    int sz = 100000;
    printf("%d %d\n" , sz , sz);

    for (int i = 1; i <= sz - 1; ++i) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < sz; ++i) {
        char nxt = (rand() % 26) + 'a';
        printf("%c", nxt);
    }
    printf("\n");

    for (int i = 0; i < sz; ++i) {
        printf("%d %d\n",sz - 1, sz - 1);
    }
}

string tostr(int b){
    string ret;
    while(b){
        ret.push_back((b&1) + '0');
        b >>= 1;
    }
    if(ret.empty())ret.push_back('0');
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(){
    FASTER;

//  test();
//  return 0;

    int n,m;
    cin >> n >> m;
    tree.assign(2*n+2, vi());
    IN.assign(3*n + 10,0),OUT.assign(3  *n+10, 0);

    for (int i = 0; i < 30; ++i)
        A[i] = (1 << i);

    for (int i = 0; i <= n + 1; ++i)
        H[i].resize(1);

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }
    cin >> labels;

    cnt = 0;
    dfs(1,1);
//
    for (int i = 0; i < m; ++i) {
        int v,h;
        cin >> v >> h;
        vii::iterator beg = lower_bound(H[h].begin(), H[h].end(), ii(IN[v], - 1));
        vii::iterator end = lower_bound(H[h].begin(), H[h].end(), ii(OUT[v], - 1));
        beg--,end--;
        int t = beg->second ^ end->second;
        bool ok = t - (t & -t);

//      cout << (!ok ? "Yes" : "No") << endl;

        if(!ok)printf("Yes\n");
        else
            printf("No\n");

    }

    return 0;
}
