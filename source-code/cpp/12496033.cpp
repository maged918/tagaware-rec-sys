//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
#include<set>
using namespace std;
#define REPF( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define REP( i , n ) for ( int i = 0 ; i < n ; ++ i )
#define CLEAR( a , x ) memset ( a , x , sizeof a )
const int INF=0x3f3f3f3f;
typedef long long LL;
const int mod=258280327;
const int maxn=1e5+100;
int mp[110][110];
int num[110];
int n,m;
int main()
{
    while(cin>>n>>m)
    {
        CLEAR(num,0);
        REPF(i,1,m)
          REPF(j,1,n) cin>>mp[i][j];
        REPF(i,1,m)
        {
            int mx=mp[i][1];
            int id=1;
            for(int j=2;j<=n;j++)
                if(mp[i][j]>mx)
                {
                   mx=mp[i][j];
                   id=j;
                }
            num[id]++;
        }
        int id=1,mx=num[1];
        for(int i=2;i<=n;i++)
            if(num[i]>mx)
        {
            mx=num[i];
            id=i;
        }
        cout<<id<<endl;
    }
}
