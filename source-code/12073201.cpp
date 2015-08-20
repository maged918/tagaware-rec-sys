//Language: GNU C++


#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
int arr[1000001][2],arr2[1000002]={0};
int main()
{
    memset(arr,0,sizeof arr);
    int n;
    scanf("%d",&n);

    int i;
    int start,enda,num=1000001;
    arr2[num] = -1;
    for(i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        arr2[a]++;

        if(arr[a][0] == 0 && arr[a][1] == 0)arr[a][0] = arr[a][1] = i;
        else arr[a][1] = i;

        if(a == num)enda = i;
        else if(arr2[a] > arr2[num]){
            num = a;
            start = arr[a][0];
            enda = arr[a][1];
        }
        else if(arr2[a] == arr2[num]){
            if(arr[a][1]-arr[a][0] < arr[num][1]-arr[num][0]){
                num = a;
                start = arr[a][0];
                enda = arr[a][1];
            }
        }
    }
    printf("%d %d",start,enda);
    return 0;
}
