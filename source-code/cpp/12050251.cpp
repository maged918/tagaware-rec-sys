//Language: GNU C++


#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
int main(int argc, char **argv)
{
    //[1,1e5]
    int n;
    scanf("%d", &n);
    //ai[1, 1e6]
    int ai;
    //first <= 1e5 second in [0 or 1, 1e6] first last in [0, n - 1]
    vector<pair<int, int> > p(1000000 + 1, make_pair(0, 0));
    vector<int>first(1000000 + 1, -1), last(1000000 + 1, -1);
    for(int i = 0; i < n; i++){
        scanf("%d", &ai);
        p[ai].first ++;
        p[ai].second = ai;
        if(first[ai] == -1){
            first[ai] = i;
        }
        last[ai] = i;
    }
    int shortest = n + 1;
    sort(p.begin(), p.end());
    int beauty = p.back().first;
    int l, r;
    for(int i = p.size() - 1; i >= 0; i--){
        if(p[i].first != beauty){
            break;
        }
        int len = last[p[i].second] - first[p[i].second] + 1;
        if(len < shortest){
            shortest = len;
            l = first[p[i].second];
            r = last[p[i].second];
        }
    }
    printf("%d %d\n", l + 1, r + 1);
    return 0;
}
