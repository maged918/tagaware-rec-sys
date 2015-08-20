//Language: MS C++


#include <iostream>
#include <map>
using namespace std;
struct node
{
    int times, l, r, len;
};
const int maxn = 100050;
map<int, node> M;
int a[maxn];
int main()
{
    int n; cin >> n;
    int Mtimes = 0, Mnum = 0, minlen = maxn;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (M[a[i]].times == 0)M[a[i]].l = i + 1;
        M[a[i]].r = i + 1;
        M[a[i]].times++;
        M[a[i]].len = M[a[i]].r - M[a[i]].l;
        if (M[a[i]].times > Mtimes)
        {
            Mtimes = M[a[i]].times;
            Mnum = a[i];
            minlen = M[a[i]].len;
        }
        else if (M[a[i]].times == Mtimes && M[a[i]].len < minlen)
        {
            Mnum = a[i];
            minlen = M[a[i]].len;
        }
    }
    printf("%d ", M[Mnum].l);
    printf("%d\n", M[Mnum].r);
    return 0;
}