//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
int x[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);

    for(int i=1;i<=n;i++)
    {
        if(i==1)
            printf("%d %d\n",abs(x[i]-x[i+1]),abs(x[i]-x[n]));
        else if(i==n)
            printf("%d %d\n",abs(x[i]-x[i-1]),abs(x[i]-x[1]));
        else
            printf("%d %d\n",min(abs(x[i]-x[i-1]),abs(x[i]-x[i+1])),max(abs(x[i]-x[1]),abs(x[i]-x[n])));
    }
    return 0;
}
