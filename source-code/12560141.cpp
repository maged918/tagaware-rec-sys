//Language: GNU C++


#include "stdio.h"
int main()
{
        int n,m;
        int ans;
        while(scanf("%d%d",&n,&m)==2)
        {
                if(n==1)
                        {
                                puts("1");
                                continue;
                        }
                if(m-1>=n-m)
                        ans=m-1;
                else
                        ans=m+1;
                printf("%d\n",ans);
        }
        return 0;
}
