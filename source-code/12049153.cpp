//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PI;
PI lhs[105], rhs[105];
int lhd, rhd;
int main()
{
    int n;
    scanf("%d", &n);
    int lsum=0, rsum=0;
    lhd=rhd=0;
    for(int i=0;i<n;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x<0)
            lhs[lhd++]=make_pair(x,y), lsum+=y;
        else
            rhs[rhd++]=make_pair(x,y), rsum+=y;
    }
    sort(lhs, lhs+lhd);
    reverse(lhs, lhs+lhd);
    sort(rhs, rhs+rhd);
    if(lhd==rhd)
        printf("%d\n", lsum+rsum);
    else if(lhd>rhd)
    {
        lsum=0;
        for(int i=0;i<rhd+1;i++)
            lsum+=lhs[i].second;
        printf("%d\n", lsum+rsum);
    }
    else
    {
        rsum=0;
        for(int i=0;i<lhd+1;i++)
            rsum+=rhs[i].second;
        printf("%d\n", lsum+rsum);
    }
    return 0;
}