//Language: GNU C++


#include <cstdio>
#include <algorithm>

using namespace std;
int main()
{
 int a1,b1,a2,b2,a3,b3,t,l;
 scanf("%d%d%d%d%d%d",&a1,&b1,&a2,&b2,&a3,&b3);
 if(a2 + a3 <= a1 && max(b2,b3) <= b1) printf("YES");
 else if(a2 + b3 <= a1 && max(a3,b2) <= b1) printf("YES");
      else if(max(a3,a2) <= a1 && b2 + b3 <= b1) printf("YES");
           else if(max(a2,b3) <= a1 && b2 + a3 <= b1) printf("YES");
                else if(b2 + a3 <= a1 && max(a2,b3) <= b1) printf("YES");
                      else if(b2 + b3 <= a1 &&  max(a2,a3) <= b1) printf("YES");
                           else if(max(b2,a3) <= a1 && a2 + b3 <= b1) printf("YES");
                                 else if(max(b2,b3) <= a1 && a2 + a3 <= b1) printf("YES");
                                     else printf("NO");
 }
