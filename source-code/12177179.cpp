//Language: GNU C++


#include<stdio.h>
int main()
{
    int a[7];
    for(int i=1;i<=6;i++)
        scanf("%d",&a[i]);
    int ans=0;
    for(int i=1;i<=3;i++)
        ans+=a[i];
    ans*=ans;
    for(int i=1;i<=6;i+=2)
        ans-=a[i]*a[i];
    printf("%d\n",ans);
    return 0;
}
