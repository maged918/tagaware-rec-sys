//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
        int mini,maxi;
        mini=abs((arr[1])-(arr[0]));
        maxi=abs((arr[n-1])-(arr[0]));
    printf("%d %d\n",mini,maxi);
    for(int i=1;i<n-1;i++)
    {
        mini=min(abs((arr[i])-(arr[i-1])),abs((arr[i+1])-(arr[i])));
        maxi=max(abs((arr[i])-(arr[0])),abs((arr[n-1])-(arr[i])));

        printf("%d %d\n",mini,maxi);

    }
     mini=abs((arr[n-1])-(arr[n-2]));
        maxi=abs((arr[n-1])-(arr[0]));
    printf("%d %d\n",mini,maxi);

    return 0;
}
