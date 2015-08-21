//Language: GNU C++


#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int flog=1;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x==1) flog=0;
    }
    if(flog==0) puts("-1");
    else puts("1");
    return 0;
}
