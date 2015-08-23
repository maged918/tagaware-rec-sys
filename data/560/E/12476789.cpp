//Language: GNU C++11


#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<functional>
#pragma comment(linker, "/STACK:102400000,102400000")//C++
using namespace std;

const double PI = 3.141592653589793238462643383279502884197169399;
const int MAXINT = 0x7fffffff;
const int MAXSIZE = 200000 + 5;
const long long INF = 0x7FFFFFFFFFFFFFFF;
const int MOD = 1e9+7;

struct node{
    int h,w;
};

//升序
bool operator <(const node&p1, const node&p2){
	if (p1.h == p2.h) return p1.w<p2.w;
    else return p1.h<p2.h;
}

long long f[MAXSIZE];

void init(){
    f[0] = 1 , f[1] = 1;
    for (int i = 2; i < MAXSIZE; i++)
        f[i] = f[i-1] * i % MOD;
}

long long inv (long long num, long long n){
    long long ret = 1;
    while (n){
        if (n&1){
            ret *= num;
            ret %= MOD;
        }
        num *= num;
        num %= MOD;
        n >>= 1;
    }
    return ret;
}

long long C(int n, int k)
{
    return f[n]*inv(f[k] * f[n-k] % MOD , MOD-2) % MOD;
}

int main(){
    init();

    vector<node> arr;
    arr.clear();
    int h,w,n;
    int a,b;

    cin>>h>>w>>n;
    while (n--){
        cin>>a>>b;
        node temp={a,b};
        arr.push_back(temp);
    }
    node temp = {h,w};
    arr.push_back(temp);
    sort(arr.begin(), arr.end());

    long long dp[2005];
    for (int i=0;i<arr.size();++i){
        dp[i] = C(arr[i].h + arr[i].w -2, arr[i].w-1);
        for (int j=0;j<i;++j){
            if (arr[i].w < arr[j].w) continue;
            dp[i] -= dp[j] * C(arr[i].h - arr[j].h + arr[i].w - arr[j].w, arr[i].h - arr[j].h);
            dp[i] = (dp[i] % MOD + MOD) % MOD;
        }
    }
    cout<<dp[arr.size()-1]<<endl;
    return 0;
}
