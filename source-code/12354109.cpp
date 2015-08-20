//Language: GNU C++11


#include <bits/stdc++.h>
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define pb push_back
#define mp make_pair
#define ALL(v) v.begin(), v.end()
#define V vector<int>
#define VP vector<pair<int, int> >
#define clr(A,x) memset(A, x, sizeof(A))
#define cpy(A,B) memcpy(A, B, sizeof(B))
#define g(s) getline(cin, s)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MAX=100005;
const ull MOD=1000000007;
const int NR_CIFRE=100005;
///templates
/*template <typename T>
string to_string(T value){
    ostringstream os;
    os << value;
    return os.str();
}
ull putere(int baza, int exp){
    ull rez=1;
    while(exp!=0)
        if(exp%2==1){
            rez=rez*baza;
            exp--;
        }
        else{
            baza=baza*baza;
            exp/=2;
        }
    return rez;
}
int cautare_binara_stl(int val, V A){
    int ret, step;
    for (step = 1; step < A.size(); step <<= 1);
    for (ret = 0; step; step >>= 1)
        if (ret + step < A.size() && A[ret + step] <= val)
            ret += step;
    return ret;
}*/
///end of templates


int main()
{
    int n;
    ll v[MAX];
    cin>>n;
    for1(i, n)
    {
        cin>>v[i];
    }
    cout<<v[2]-v[1]<<' '<<v[n]-v[1]<<'\n';
    for(int i=2; i<n; i++)
    {
        cout<<min(v[i]-v[i-1], v[i+1]-v[i])<<' '<<max(v[n]-v[i], v[i]-v[1])<<'\n';
    }
    cout<<v[n]-v[n-1]<<' '<<v[n]-v[1];














    return 0;
}
