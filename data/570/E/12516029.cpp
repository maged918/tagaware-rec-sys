//Language: GNU C++


#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstdio>
using namespace std;
const int MAXN = 502;
const long long modulo = 1000000007;
const int inf = 1000000001;

char a[MAXN][MAXN];

void printTable( int N , int M )
{
    for ( int i = 1; i <= N; i++)
    {
        for ( int j = 1; j <= M; j++)
            cout << a[i][j];
        cout << endl;
    }
}

void ExpandTable(int N , int& M)
{
    M++;
    int Half = ((N + M + 1) / 2) + 1;
    for ( int i = 1; i <= N; i++)
    {
        int j = M;
        while ( i + j >= Half )
        {
            a[i][j + 1] = a[i][j];
            a[i][j] = 'z';
            j--;
        }
    }
}

long long dp[MAXN][MAXN] = {0} , prevDp[MAXN][MAXN] = {0};

void reNewDP()
{
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            prevDp[i][j] = dp[i][j];
            dp[i][j] = 0;
         }
    }
}

int main()
{
    //freopen("input.in" , "r" , stdin);
    int N , M;
    scanf("%d%d", &N, &M);

    if ( N == 1 && M == 1 )
    {
        cout << 1 << endl;
        return 0;
    }

    for ( int i = 1; i <= N; i++)
    {
        char crap;
        scanf("%c", &crap);

        for ( int j = 1; j <= M; j++)
        {
            if ( N <= M )
                scanf("%c", &a[i][j]);
            else
                scanf("%c", &a[j][i]);
        }
    }

    if ( N > M ) swap( N , M );

    //if ( (N + M) % 2 == 1 )
      //  ExpandTable(N , M);

    int Mid = ( N + M ) / 2;

    if ( a[1][1] != a[N][M] )
    {
        cout << 0 << endl;
        return 0;
    }


    prevDp[1][1] = 1;
    for ( int level = 2; level <= Mid; level++)
    {
        int Cells = min( level , N );
        //cout << "Level " << level << endl;
        for ( int i = 1; i <= Cells; i++)
        {
            for ( int j = 1; j <= Cells; j++)
            {
                int upX , upY, downX, downY;
                upX   = i;
                upY   = (level + 1) - upX;
                downX = (N - Cells + 1) +  (j - 1);
                downY = (N + M - level + 1) - downX;

                //cout << upX << " " << upY << " " << downX << " "  << downY << endl;

                if ( a[upX][upY] != a[downX][downY] )
                {
                    dp[i][j] = 0;
                    //cout << "dp[" << level << "][" << i << "][" << j << "] = " << dp[level][i][j] << endl;
                    continue;
                }

                //cout << upX << " " << upY << " " << downX << " "  << downY << endl;
                //cout << i << " " << j << endl;
                //cout << "Ended " << endl;

                int extra = (level > N ? 1 : -1);

                dp[i][j] = prevDp[i-1][j+extra] +
                           prevDp[ i ][j+extra] +
                           prevDp[i-1][ j     ] +
                           prevDp[ i ][ j     ];

                dp[i][j] %= modulo;
                //cout << upX << " " << upY << " " << downX << " "  << downY << " " << dp[level][i][j] << endl;
                //cout << "dp[" << level << "][" << i << "][" << j << "] = " << dp[level][i][j] << endl;
            }
        }
        reNewDP();

    }

    long long ans = 0;
    if ( (M + N) % 2 == 0)
    {
        for ( int i = 1; i <= N; i++)
            ans += prevDp[i][i];
    }
    else
    {
        for (int i = 1; i <= N; i++)
            ans += prevDp[i][i] + prevDp[i][i+1];
    }

    cout << ans % modulo << endl;

    return 0;
}
