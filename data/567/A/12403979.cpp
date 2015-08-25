//Language: GNU C++11


#include <cstdio>
#define SIZE 100001
int main(void)
{
    int i,n,arr[SIZE];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d %d\n",(arr[1]-arr[0]),(arr[n-1]-arr[0]));
    for(i=1;i<n-1;i++){
        if(arr[i]-arr[i-1]>arr[i+1]-arr[i])
            printf("%d ",arr[i+1]-arr[i]);
        else
            printf("%d ",arr[i]-arr[i-1]);
        if(arr[i]-arr[0]<arr[n-1]-arr[i])
            printf("%d\n",arr[n-1]-arr[i]);
        else
            printf("%d\n",arr[i]-arr[0]);
    }
    printf("%d %d\n",(arr[n-1]-arr[n-2]),(arr[n-1]-arr[0]));
    return 0;
}
