//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std; using ll = long long;
const int N = int(1e6 + 50);
bool was[N];
int main(){
    int n, ans = 0; scanf("%d", &n);
    for (int i = 0; i < n; i++){
        string s; int val, cur_max = 0; cin >> s >> val;
        if (s[0] == '+')was[val] = true;
        else{
            if (!was[val])ans++;
            else was[val] = false;
        }
        for (int j = 1; j <= int(1e6); j++){
            if (was[j]){
                cur_max++;
            }
            ans = max(ans, cur_max);
        }
    }
    printf("%d\n", ans);
    return 0;
}