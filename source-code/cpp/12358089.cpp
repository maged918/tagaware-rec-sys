//Language: GNU C++11


#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <string>
#define PB push_back
#define FT first
#define SD second
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef pair<int,int>  P;
const int N=5+2e5,MOD=7+1e9;
map<LL,int> mp1,mp2;
LL a[N];
int main()
{
    //freopen("E:/ACM_code/in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    LL k;
    scanf("%d%I64d",&n,&k);
    mp1.clear(),mp2.clear();
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
        mp1[a[i]]++;
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        mp1[a[i]]--;
        if(a[i]%k==0){
            if(mp2.count(a[i]/k) && mp1.count(a[i]*k)){
                ans+=1LL*mp2[a[i]/k]*mp1[a[i]*k];
            }
        }
        mp2[a[i]]++;
    }
    printf("%I64d\n",ans);
    //system("pause");
    return 0;
}