//Language: GNU C++


#include <cstdio>
#include <set>

using namespace std;

set<int> x;

int main(int argc, char **argv)
{
    int n, k, a, q, sol = -1, currPossible, target;
    scanf("%d%d%d%d", &n, &k, &a, &q);
    x.insert(0); x.insert(n+1);
    a++;
    currPossible = (n+1) / a;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &target);
        set<int>::iterator nextIt = x.upper_bound(target);
        int fNext = *nextIt;
        nextIt--;
        int fPrev = *nextIt;
        x.insert(target);
        currPossible = currPossible - (fNext-fPrev) / a;
        currPossible = currPossible + (fNext-target) / a;
        currPossible = currPossible + (target-fPrev) / a;
        if (currPossible < k) { sol = i+1; break; }
    }
    printf("%d\n", sol);
    return 0;
}