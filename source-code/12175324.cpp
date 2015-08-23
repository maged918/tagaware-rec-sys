//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int a1,a2,a3,a4,a5,a6;
    while(~scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6)){
        int S = (a1 + a2 + a3)*(a1 + a2 + a3) - a1 * a1 - a3 * a3 - a5 * a5;
        printf("%d\n", S);
    }
    return 0;
}
