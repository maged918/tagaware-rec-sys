//Language: GNU C++11


#include<stdio.h>
int main()
{
    int n,a;
    int ans=1;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        if(a==1)
            ans=-1;
    }
    printf("%d\n",ans);
    return 0;
}
