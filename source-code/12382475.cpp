//Language: MS C++


#include <stdio.h>

int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a < b ? b : a; }

int I[100003];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)scanf("%d", &I[i]);

    printf("%d %d\n", I[2] - I[1], I[n] - I[1]);
    for (int i = 2; i < n; i++){
        int a = I[i+1] - I[i];
        int b = I[i] - I[i-1];
        int c = I[i] - I[1];
        int d = I[n] - I[i];
        printf("%d %d\n", min(a, b), max(c, d));
    }
    printf("%d %d\n", I[n] - I[n - 1], I[n] - I[1]);
}