//Language: GNU C++


/*   W          w           w        mm          mm             222222222       7777777777777    */
/*    W        w w         w        m  m        m  m          222        22              7777    */
/*    w        w w         w        m  m        m  m                     22              777     */
/*     w      w   w       w        m    m      m    m                    22              77      */
/*     w      w    w      w        m    m      m    m                 222                77      */
/*      w    w      w    w        m      m    m      m              222                  77      */
/*      w    w      w    w        m      m    m      m            222                    77      */
/*       w  w        w  w        m        m  m        m         222                      77      */
/*       w  w        w  w        m        m  m        m      222                         77      */
/*        ww          ww        m          mm          m     222222222222222             77      */

//#pragma comment(linker, "/STACK:102400000,102400000")
//C++
//int size = 256 << 20; // 256MB
//char *p = (char*)malloc(size) + size;
//__asm__("movl %0, %%esp\n" :: "r"(p));
//G++
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <ctime>
#include <deque>
#include <cmath>
#include <vector>
#include <cctype>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#define REP(i,s,t) for(int i=(s);i<=(t);i++)
#define REP2(i,t,s) for(int i=(t);i>=(s);i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;

const int N=1005;
int n;
int a[N];
int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("test.in","r",stdin);
  #endif
  while(~scanf("%d",&n))
  {
      REP(i,1,n)
      {
          scanf("%d",&a[i]);
      }
      int _min=*min_element(a+1,a+1+n);
      if(_min==1)
      {
          printf("-1\n");
      }
      else
      {
          printf("%d\n",1);
      }
  }
  return 0;
}
