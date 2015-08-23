//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

string nums[100005];

int main() {
    int n, lim = 99999;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        while (x) {
            int rem = x % 2;
            nums[i] += char(rem + '0');
            x /= 2;
        }
        reverse(nums[i].begin(), nums[i].end());
        lim = min(lim, (int)nums[i].size());
    }
    string pat = "";
    bool f = 1;
    for(int i = 0;i < lim and f;i++) {
        for(int j = 1;j < n;j++) {
            if(nums[j][i] != nums[j - 1][i])
                f = 0;
        }
        if(f)
            pat += nums[0][i];
    }
    pat += '1';
    int ans = 0, mxs = 0;
    for (int i = 0; i < n; i++) {
        for (int j = pat.size() - 1; j < nums[i].size(); j++) {
            if (nums[i][j] == '1') {
                ans += nums[i].size() - j;
                nums[i].erase(nums[i].begin() + j, nums[i].end());
                break;
            }
        }
        mxs = max(mxs, (int) nums[i].size());
    }
    for (int i = 0; i < n; i++) {
        string tmp(mxs - nums[i].size(), '0');
        lim = max(lim, mxs - (int) tmp.size());
        nums[i] = tmp + nums[i];
    }
    int ans2 = 99999999;
    for (int i = 0; i <= mxs - pat.size() + 1; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int start = 0;
            while (nums[j][start] == '0')
                start++;
            cnt += abs(start - i);
        }
        ans2 = min(ans2, cnt);
    }
    printf("%d", ans + ans2);
    return 0;
}