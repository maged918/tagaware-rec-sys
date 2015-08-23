//Language: GNU C++11


/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)
int getint(){
    int t = 0, flag = 1; char c = getchar();
    while (c<'0' || c>'9' || c == '-')
    {
        if (c == '-')
            flag = -1;
        c = getchar();
    }
    while (c >= '0'&&c <= '9')
        t = t * 10 + c - '0', c = getchar();
    return t*flag;
}
int GCD(int m, int n)
{
    return !m ? n : GCD(n%m, m);
}
template <typename T>
string to_string(T value)
{
  //create an output string stream
  ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}
LL MultMod(LL a,LL b,LL MOD)
{
    a %= MOD;
    b %= MOD;
    LL ret = 0;
    while(b){
        if (b & 1){
            ret += a;
            if(ret >= MOD) ret -= MOD;
        }
        a = a << 1;
        if (a >= MOD) a -= MOD;
        b = b >> 1;
    }
    return ret;
}
int x, a, n, t, m;
vector<pii> vp, vn;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>n){
        vp.clear(), vn.clear();
        for(int i=0;i<n;i++){
            cin>>x>>a;
            if(x>0) vp.push_back({x, a});
            else vn.push_back({-x, a});
        }
        sort(vp.begin(), vp.end());
        sort(vn.begin(), vn.end());
        int ans=0;
        if(vp.size()==vn.size()){
            for(int i=0;i<vp.size();i++)
                ans+=vp[i].se+vn[i].se;
            //int ans=accumulate(vp.begin(), vp.end(), 0)+accumulate(vn.begin(), vn.end(), 0)+
        }else{
            int minsize=min(vp.size(), vn.size());
            for(int i=0;i<minsize;i++) ans+=vp[i].se+vn[i].se;
            if(vp.size()>vn.size()) ans+=vp[minsize].se;
            else ans+=vn[minsize].se;
            //if(vp.size()>vn.size()) ans+=vp[minsize].se;
        }
        cout<<ans<<endl;
    }
    return 0;
}
