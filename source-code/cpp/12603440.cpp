//Language: GNU C++11


#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define all(x) x.begin(), x.end()
#define f(i,a,b) for(int i = (a); i <= (b); i++)
#define fd(i,a,b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define faster_io() ios_base::sync_with_stdio(false)
#define pb push_back
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define vii vector<pair<int,int>>

const int INF = 1000000002;
const ll INFLL = 100000000000000000ll;
const ll MOD = 1000000007;

// ----------------------------------------------------------------------------------------------------------

int N, Q;
string S;

int main()
{
    cin >> N >> Q >> S;
    int ans = 0;
    f(i,1,N-1) if(S[i] == '.' && S[i-1] == '.') ans++;
    while(Q--)
    {
        char v;
        int p;
        cin >> p >> v;
        p--;
        if((S[p] == '.' && v != '.') || (S[p] != '.' && v == '.'))
        {
            if(v == '.')
            {
                if(p>0 && S[p-1] == '.') ans++;
                if(p<N && S[p+1] == '.') ans++;
            }
            else
            {
                if(p>0 && S[p-1] == '.') ans--;
                if(p<N && S[p+1] == '.') ans--;
            }
        }

        S[p] = v;
        printf("%d\n", ans);
    }
}
