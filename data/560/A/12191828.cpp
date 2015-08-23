//Language: GNU C++11


#include <cstdio>

int main() {
    int a, n; scanf ("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        if (a == 1) {
            printf("-1\n");
            return 0;
        }
    }
  
    printf("1\n");
    return 0;
}