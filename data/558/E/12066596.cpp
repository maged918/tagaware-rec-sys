//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define FI(n) for(int i=0;i<n;i++)
#define FJ(n) for(int j=0;j<n;j++)
char s[100010];
int main(){
    int n, q;
    cin >> n >> q;
    cin >> s;
    FI(n) s[i] -= 'a';
    while (q--){
        int cnt2[27*256] = {};
        int cnt[26] = {};
        int i, j, k;
        cin >> i >> j >> k;
        i--; j--;
        if (~(j - i) & 1) {
            cnt[s[j]]++;
            --j;
        }
        for (short* it = (short*) (s + i); it <= (short*) (s + j); ++it)
            cnt2[*it]++;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                cnt[i] += cnt2[i * 256 + j];
                cnt[j] += cnt2[i * 256 + j];
            }
        }
        if (k){
            for (char r = 0; r < 26; r++){
                memset(s + i, r, cnt[r]);
                i += cnt[r];
                cnt[r] = 0;
            }
        }
        else{
            for (char r = 25; r >= 0; r--){
                memset(s + i, r, cnt[r]);
                i += cnt[r];
                cnt[r] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        s[i] += 'a';
    }
    puts(s);
    return 0;
}
