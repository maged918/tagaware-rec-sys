//Language: GNU C++11


#include<stdio.h>

int main() {
  int a,b;
  scanf("%d",&a);
  while(a--) {
    scanf("%d", &b);
    if(b==1) {
      printf("-1\n");
      return 0;
    }
  }
  printf("1\n");
  return 0;
}
