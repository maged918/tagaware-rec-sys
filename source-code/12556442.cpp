//Language: GNU C++11


/*************************************************************************
    > File Name: code/cf/#314/F.cpp
    > Author: 111qqz
    > Email: rkz2013@126.com 
    > Created Time: 2015年08月16日 星期日 14时37分15秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int N = 1E2+7;
int n, k, a[N], b[N];
LL dp[N][N];
string sign[N];
int L, R, F, S;
enum 
{
    OLD, CUR, NEW
};
int get_type(int i) 
{
    if (i < L || i > R) return OLD;
    if (i == F || i == S) return CUR;
    return NEW;
}
bool compare(int a, int b, string s) 
{
    if (s == "=") return a == b;
    if (s == ">") return a > b;
    if (s == "<") return a < b;
    if (s == ">=") return a >= b;
    if (s == "<=") return a <= b;
}
bool check(int l, int r, int f, int s)
{
    L = l, R = r;
    F = f, S = s;
    for (int i = 0; i < k; i++) 
    {
        int lf = get_type(a[i]); // 判断对于当前要添加的位置，是否有题目中给出限制的位置，如果是，判断是否满足限制．
                //如果有一个限制条件不满足就不成立，所有限制条件都满足才成立．
        int rg = get_type(b[i]);
        if (lf != CUR && rg != CUR) continue;
        if (!compare(lf, rg, sign[i])) return false;
    }
    return true;
}
LL cal(int l, int r) 
{
    LL &res = dp[l][r];//dp[l][r] 表示在区间[l,r]放置的方案的个数
    if (res != -1) return res;
    res = 0;
    if (l + 1 == r) //最后相邻，表示最后两个n放在一起了，答案＋１
    {
        if (check(l, r, l, r)) res++;
    } else 
    {
        if (check(l, r, l, l + 1)) res += cal(l + 2, r); //一对的两个都放在左边
        if (check(l, r, l, r)) res += cal(l + 1, r - 1); //左１右１
        if (check(l, r, r - 1, r)) res += cal(l, r - 2);// 右２
    }
    return res;
}
int main () 
{
    scanf("%d %d", &n, &k);
    n = n * 2;
    for (int i = 0; i < k; i++) 
    {
        cin>>a[i]>>sign[i]>>b[i];
        a[i]--;
        b[i]--;
    }
    memset(dp, -1, sizeof(dp));
    printf("%I64d\n",cal(0,n-1));
    return 0;
}
