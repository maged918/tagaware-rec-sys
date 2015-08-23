//Language: GNU C++


/**
 *    @author     : Dipta Das
 *    @University : CUET CSE 11
 *    @Codeforces : diptadas
 *    @Topcoder   : dipta670
 *    @link       : www.fb.com/dipta.das
 */

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<math.h>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

#define LL         long long
#define pll        pair<LL,LL>
#define mp         make_pair
#define fr         first
#define sc         second
#define pb         push_back

#define read(n)    scanf("%lld",&n)
#define mset(a,s)  memset(a,s,sizeof(a))
#define all(a)     a.begin(),a.end()

#define PI         acos(-1.0)
#define EPS        1e-9
#define MOD        1000000007
#define INF        1e9
#define NN         100009

LL a[NN],b[NN],c[NN],d[NN];

int main()
{
    LL n,m,i,j,k;

    read(n);

    for(i=0;i<n;i++)
    {
        read(a[i]);
        b[a[i]]=1;
    }

    j=0;

    for(i=1;i<=n;i++)
    {
        if(b[i]==0) c[j++]=i;
    }

    k=0;

    for(i=0;i<n;i++)
    {
        if(a[i]>n || d[a[i]]) printf("%lld ",c[k++]);
        else
        {
            printf("%lld ",a[i]);
            d[a[i]]=1;
        }
    }



    return 0;
}
