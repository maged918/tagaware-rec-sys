//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>

#define MAXN 500 + 9
#define SZ(x) (int)(x).size()
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

using namespace std;

const int MOD = 1e9 + 7;
const int X[2] = {0, 1};
const int Y[2] = {1, 0};

int n, m, finish;
long long res;

char L[MAXN][MAXN];
int Dis[2][MAXN][MAXN];
int Num[2][MAXN][MAXN];
long long DP[2][MAXN][MAXN];

vector < pair<int,int> > V[2][MAXN + MAXN];

bool Inside(int,int);

int main()
{
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= m; j++)
    {
      scanf(" %c", &L[i][j]);
      Dis[0][i][j] = i + j - 2;
      Dis[1][i][j] = n - i + m - j;
      Num[0][i][j] = SZ(V[0][Dis[0][i][j]]);
      Num[1][i][j] = SZ(V[1][Dis[1][i][j]]);
      V[0][Dis[0][i][j]].PB(MP(i,j));
      V[1][Dis[1][i][j]].PB(MP(i,j));
    }
  }
  finish = (n + m - 2) / 2;
  DP[0][0][0] = (L[1][1] == L[n][m]);
  for(int f = 1; f <= finish; f++)
  {
    for(int i = 0; i < SZ(V[0][f]); i++)
    {
      for(int j = 0; j < SZ(V[1][f]); j++)
      {
        DP[f & 1][i][j] = 0;
        int x1 = V[0][f][i].ST;
        int y1 = V[0][f][i].ND;
        int x2 = V[1][f][j].ST;
        int y2 = V[1][f][j].ND;
        if(L[x1][y1] == L[x2][y2])
        {
          for(int p = 0; p < 2; p++)
          {
            for(int l = 0; l < 2; l++)
            {
              int x3 = x1 - X[p];
              int y3 = y1 - Y[p];
              int x4 = x2 + X[l];
              int y4 = y2 + Y[l];
              if(Inside(x3, y3) && Inside(x4, y4))
              {
                DP[f & 1][i][j] += DP[(f - 1) & 1][Num[0][x3][y3]][Num[1][x4][y4]];
              }
            }
          }
          while(DP[f & 1][i][j] >= MOD)
          {
            DP[f & 1][i][j] -= MOD;
          }
        }
      }
    }
  }
  if((n + m) & 1)
  {
    for(int i = 0; i < SZ(V[0][finish]); i++)
    {
      for(int j = 0; j < SZ(V[1][finish]); j++)
      {
        if(V[0][finish][i].ST == V[1][finish][j].ST && V[1][finish][j].ND - V[0][finish][i].ND == 1)
        {
          res += DP[finish & 1][i][j];
        }
        else if(V[0][finish][i].ND == V[1][finish][j].ND && V[1][finish][j].ST - V[0][finish][i].ST == 1)
        {
          res += DP[finish & 1][i][j];
        }
      }
    }
  }
  else
  {
    for(int i = 0; i < SZ(V[0][finish]); i++)
    {
      for(int j = 0; j < SZ(V[1][finish]); j++)
      {
        if(V[0][finish][i] == V[1][finish][j])
        {
          res += DP[finish & 1][i][j];
        }
      }
    }
  }
  printf("%lld\n", res % MOD);
}

bool Inside(int a, int b)
{
  return (1 <= a && a <= n && 1 <= b && b <= m);
}
