//Language: GNU C++


#include<bits/stdc++.h>

using namespace std;

#define onlylove "My Sky"
#define mysky "TT"

#define X first
#define Y second
#define sz(A) int(A.size())
#define mpair make_pair
#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1 )
#define sqr(x) ((x)*(x))
#define rep(i , n) for(int i = 0 , _a = n ; i < _a ; i++)
#define For( i , a , b) for(int _a = a , _b = b , i = _a ; i <= b ; i++)


typedef long long ll;
typedef pair<int , int> pt;

const int OnlineJudge = 1;
const int maxn = 109;
multiset<int> se;
int ans = 0;
int n;
int was[maxn] , cur[maxn];

int main()
{
    std ::ios_base::sync_with_stdio(false);
    cin.tie(0);

    if (OnlineJudge){
    } else freopen("input.inp","r",stdin);

    cin >> n;
    For(i , 1 , n) {
        char type;
        int id;
        cin >> type >> id;
        if (type == '+'){
            se.insert(id);
            cur[i] = cur[i-1] + 1;
        } else {
            if (se.find(id) == se.end()) {
                    cur[i] = cur[i-1];
                    For(j , 1 , i ) was[j]++;
            } else {
                multiset<int>::iterator it = se.find(id);
                se.erase(it);
                cur[i] = cur[i-1] - 1;
            }
        }
    }

    For(i , 1,  n)
       ans = max(ans , cur[i] + was[i]);

    cout << ans << endl;

    return 0;
}
