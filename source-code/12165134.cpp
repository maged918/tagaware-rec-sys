//Language: GNU C++11


#include <cstdio>
int main(){
    long n, i, value;
    scanf("%I32d\n",&n);
    for ( i = 1; i <= n; i++ ){
        scanf("%I32d",&value);
        if ( value == 1 ){
            printf("-1");
            break;
        }
    }
    if ( i == n + 1 )
        printf("1");
    return 0;
}
