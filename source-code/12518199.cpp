//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int n,m;
    scanf("%d %d",&n,&m);
    if(n==1) {
        printf("1\n");
        return 0;
    }
    if(m<=n/2) printf("%d\n",m+1);
    else    printf("%d\n",m-1);
    return 0;
}
