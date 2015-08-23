//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

const int MAX = 200000 + 10;
long n, a[MAX], cnt[MAX];
vector <int> tmp;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]),
        cnt[a[i]]++;

    for (int i = 1; i <= n; i++)
        if (cnt[i] == 0) tmp.push_back(i);

    for (int i = 0, j = 0; i < n; i++)
        if (a[i] > n) a[i] = tmp[j++];
        else if (cnt[a[i]] > 1)
            cnt[a[i]]--, a[i] = tmp[j++];

    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}