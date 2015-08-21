//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e6+100;

bool mark[maxn+10];
int dp[maxn+10],pd[maxn+10];

int main(){
    long long int t,s,q; cin >> t >> s >> q;
    long long int ans = 0;
    long long int vs = s;
    while(vs < t){
        int k = vs;
        ans++;
        vs *= q;
    }   
    long long int zero = 1;
    cout << max(zero , ans) << endl;
}
//"A", "O", "Y", "E", "U", "I"