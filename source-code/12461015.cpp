//Language: GNU C++


#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
using namespace std;
#define INF 100000
typedef long long ll;
const int maxn=100010;
int h[maxn],ans[maxn],a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    memset(h,0,sizeof(h));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        h[a[i]]++;
    }
    int ct=0;
    for(int i=1;i<=n;i++)
        if(!h[i]) ans[ct++]=i;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]>n) a[i]=ans[cnt++];
        else if(h[a[i]]>1) {h[a[i]]--;a[i]=ans[cnt++];}
    }
    for(int i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    return 0;
}
