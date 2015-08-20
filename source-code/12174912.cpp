//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int main()
{
//  freopen("input.txt","r",stdin);
    int l,w,a[5],b[5];
    while(scanf("%d %d",&a[1],&b[1])!=EOF)
    {
        
        scanf("%d%d",&a[2],&b[2]);
        scanf("%d%d",&a[3],&b[3]);
    /*  if(a[2]>a[1]||a[3]>a[1]||a[2]>b[1]||a[3]>b[1])
        {
            printf("NO");
        }
        else if(b[2]>a[1]||b[2]>b[1]||b[3]>a[1]||b[3]>b[1])
        {
            printf("NO");
        }
        else if(a[1]*b[1]<(a[2]*b[2]+a[3]*b[3]))
        {
            printf("NO");
        }*/
        
     if(max(b[1],a[1])-max(b[2],a[2])-max(b[3],a[3])>=0&&min(b[1],a[1])>=max(min(b[2],a[2]),min(b[3],a[3])))
        printf("YES\n");
        else if((min(b[1],a[1])-min(b[2],a[2])-min(b[3],a[3])>=0)&&max(b[1],a[1])>=max(max(b[2],a[2]),max(b[3],a[3]))) //两短 
        printf("YES\n");
        else if(max(b[1],a[1])-max(b[2],a[2])-min(b[3],a[3])>=0&&min(b[1],a[1])>=max(min(b[2],a[2]),max(b[3],a[3])))  //两短 
        printf("YES\n");
        else if(max(b[1],a[1])-min(b[2],a[2])-max(b[3],a[3])>=0&&min(b[1],a[1])>=max(max(b[2],a[2]),min(b[3],a[3])))
        printf("YES\n");
        else if((min(b[1],a[1])-max(max(b[2],a[2]),max(b[3],a[3]))>=0)&&max(b[1],a[1])-min(b[2],a[2])-min(b[3],a[3])>=0)
        printf("YES\n");
        else 
        printf("NO\n");
        
    }
}