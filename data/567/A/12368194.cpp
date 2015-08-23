//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
#define li long long int
int main()
{

    li n,i,j;
    cin>>n;
    li arr[n];
    for(i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    j=arr[1]-arr[0];
    li k=arr[n-1]-arr[0];
    cout<<j<<" "<<k<<endl;
    li mn,mx;
    for(i=1;i<n-1;++i)
    {
        mn=min(arr[i]-arr[i-1],arr[i+1]-arr[i]);
        mx=max(arr[i]-arr[0],arr[n-1]-arr[i]);
        cout<<mn<<" "<<mx<<endl;
    }
    cout<<arr[n-1]-arr[n-2]<<" "<<arr[n-1]-arr[0]<<endl;
    return 0;
}
