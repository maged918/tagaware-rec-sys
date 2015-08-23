//Language: GNU C++


#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;
#define dg(x) cout<<#x<<" = "<<x<<endl
#define ot(x) cout<<#x<<" = "<<x<<" "
#define INF 0x3f3f3f3f
long long a[6];
int tag[6];
int main()
{
    for (int i=0;i<6;++i) cin>>a[i];
    long long ans = 0;
    memset(tag,0,sizeof(tag));
    int l = 6;
    while (1){
        if (l<6 && l>3){
            long long b[6];
            for (int i=0;i<6;++i) b[i] = a[i];
            for (int i=0;i<6;++i){
                if (a[i]>0) continue;
                b[i] = 1LL;
                int ll = (i+1)%6;
                int rr = (i+5)%6;
                if (a[ll]) b[ll] --;
                if (a[rr]) b[rr] --;
                if (!b[ll]) {
                    l--;
                    tag[ll] = 1;
                }
                if (!b[rr]) {
                    l--;
                    tag[rr] = 1;
                }
                ++l;
                tag[i] = 0;
                ans ++;
            }
            for (int i=0;i<6;++i) a[i] = b[i];
        }
        else if (l == 6){
            for (int i=0;i<6;++i){
                if (tag[i] == 1) break;
                long long tmp = 0;
                tmp = tmp + 2LL * a[i] - 1LL;
                ans = ans + tmp;
                a[i] --;
                if (a[i] == 0) {
                    tag[i] = 1;
                    --l;
                }
            }
        }
/*
ot(l);  dg(ans);
for (int i=0;i<6;++i) ot(a[i]);
dg('#');
*/
        if (l == 3) {
            long long pp;
            for (int i=0;i<6;++i) {
                if (a[i]>0) {
                    pp = a[i];
                    break;
                }
            }
            ans = ans + pp*pp;
            break;
        }
        if (l<=2) break;
    }

    cout<<ans<<endl;
    return 0;
}
