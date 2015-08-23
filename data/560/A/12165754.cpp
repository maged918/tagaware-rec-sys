//Language: GNU C++11


#include<cstdio>
#include<algorithm>
#include<iostream>
#include<set>
#include<iterator>
#include<queue>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<map>
#include<cstdlib>
using  namespace std;
#define foreach(i,a) for(typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define v2 pair<int,int>
#define v3 pair<int, v2 >
#define xx first
#define x xx
#define y second
#define yy y.x
#define zz y.y
#define m2 make_pair
#define m3(a,b,c) make_pair(a,make_pair(b,c))
#define s(x) scanf("%d",&x)
int main()
{
    int n;
    cin>>n;
    int r=INT_MAX;
    for(int i=1;i<=n;++i)
    {
        int p;
        cin>>p;
        r=min(p,r);
    }
    if(r==1)cout<<-1;
    else cout<<1;
    return 0;
}
