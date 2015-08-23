//Language: GNU C++


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 57
#define M 400007

using namespace std;

typedef long long LL;
typedef pair<LL,LL> PII;

int h,q;
LL sum[MAX];
LL two[MAX];

void init ( )
{
    two[1] = 1;
    for ( int i = 2 ; i < MAX ; i++ )
        two[i] = two[i-1]<<1;
    sum[0] = 0;
    for ( int i = 1 ; i < MAX ; i++ )
        sum[i] = sum[i-1] + two[i];
}

PII p[M];
int cnt;

int main ( )
{
    int a,f;
    LL l,r;
    init();
    while ( ~scanf ( "%d%d" , &h , &q ) )
    {
        cnt = 0;
        while ( q-- )
        {
           scanf ( "%d%I64d%I64d%d" , &a , &l , &r , &f );
           l -= sum[a-1];
           r -= sum[a-1];
           int temp = a;
           while ( temp < h )
           {
               l = l*2-1;
               r = r*2;
               temp++;
           }
           if ( f == 0 ) p[cnt++] = make_pair ( l , r );
           else
           {
               if ( l > 1 )
                    p[cnt++] = make_pair ( 1 , l-1 );
               if ( r < two[h] )
                    p[cnt++] = make_pair ( r+1 , two[h] );
           }
        }
        sort ( p , p+cnt );
        //cout << p[0].first << " " << p[0].second << endl;
        LL ans = -1 , loc = 1 , t = 0;
        for ( int i = 0 ; i < cnt ; i++ )
        {
            if ( p[i].first > loc )
            {
                ans = loc;
                t += p[i].first - loc;
            }
            loc = max ( loc , p[i].second+1 );
        }
        if ( two[h] >= loc )
        {
            ans = loc;
            t += two[h] - loc + 1;
        }

        //cout << "YES : " << t << endl;

        if ( t == 0 )
            puts ("Game cheated!");
        else if ( t > 1 )
            puts ("Data not sufficient!");
        else printf ( "%I64d\n" , ans + sum[h-1]);
    }
}
