//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define SZ size()
#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define ITR(i, j, n) for(int i = j; i < (int)n; i++)
#define mem(array, val) memset(array, val, sizeof(array))
#define READ(filename) freopen(filename, "r", stdin)
#define WRITE(filename) freopen(filename, "w", stdout)
#define Pii pair <int, int>
#define Fr first
#define Sc second
#define Long long long
#define si(a) scanf("%d", &a)
#define sl(a) scanf("%I64d", &a)
#define sd(a) scanf("%lf", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define sll(a, b) scanf("%I64d%I64d", &a, &b)
#define sdd(a, b) scanf("%lf%lf", &a, &b)
#define Fast_IO ios_base::sync_with_stdio(0);cin.tie(0)

int main()
{
   int n, m, ara[100];
   mem(ara, 0);
   sii(n, m);
   REP(i, m) {
      int mi = -1, id = -1;
      REP(j, n) {
         int a;
         si(a);
         if(a > mi) mi = a, id = j;
      }
      ara[id]++;
   }
   int mi = -1, id = -1;
   REP(i, n) if(ara[i] > mi) mi = ara[i], id = i;
   printf("%d\n", id+1);

   return 0;
}
