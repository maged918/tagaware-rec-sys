//Language: GNU C++11


#include <iostream>
#include <string>
#include <cstdio>
int a1,a2,a3,a4,a5,a6,sum,tem,i;
int main ()
{
  scanf("%d %d %d %d %d %d",&a1,&a2,&a3,&a4,&a5,&a6);
  sum=(a1+a2)*2*(a3+a2);
  sum-=(a2*a2)+(a5*a5);
  printf("%d",sum);
  return 0;
}