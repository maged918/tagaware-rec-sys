//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;

int a[maxn];
int l[maxn], r[maxn];
int cnt[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++)
    {
        if (!cnt[a[i]])
            l[a[i]] = i;
        cnt[a[i]] ++;
        r[a[i]] = i;
    }
    int _max = 0;
    vector <int> list;
    for (int i = 1; i < maxn; i ++)
        if (cnt[i] > _max)
        {
            _max = cnt[i];
            list.clear();
            list.push_back(i);
        }
        else if (cnt[i] == _max)
            list.push_back(i);
    int min_l = 0x3f3f3f3f;
    int ans;
    for (int i = 0; i < (int)list.size(); i ++)
    {
        int id = list[i];
        if (r[id] - l[id] + 1 < min_l)
        {
            min_l = r[id] - l[id] + 1;
            ans = id;
        }
    }
    printf("%d %d\n", l[ans], r[ans]);
    return 0;
}
