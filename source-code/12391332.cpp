//Language: GNU C++


/* Author d.a_tuong
   Problems: Problem D One-Dimensional Battle Ships
   Source: Codeforces Round #Pi
   Link: http://codeforces.com/contest/567/problem/D
   Categories: Data Struct, Binary Search
   Complexity: O(nlogn)
*/

#include <bits/stdc++.h>

using namespace std;

int n, k, cnt, sz, m;
set <int> a;

int Solve(int L, int R){
    return (R - L + 2) / (sz + 1);
}

int main(){
    scanf("%d %d %d", &n, &k, &sz);
    a.insert(0);
    a.insert(n + 1);
    scanf("%d", &m);
    cnt = Solve(1, n);
    for (int i = 0; i < m; i++){
        int x;
        scanf("%d", &x);
        set <int> :: iterator iter1, iter2;
        iter1 = iter2 = a.lower_bound(x);
        iter1--;
        cnt += Solve(*iter1 + 1, x - 1) + Solve(x + 1, *iter2 - 1) - Solve(*iter1 + 1, *iter2 - 1);
        if (cnt < k){
            printf("%d", i + 1);
            return 0;
        }
        a.insert(x);
    }
    printf("-1");
}
