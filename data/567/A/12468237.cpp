//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n){
        int arr[100005];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            if(i==0){
                cout<<abs(arr[1]-arr[0])<<' ';
                cout<<abs(arr[n-1]-arr[0])<<endl;
            }
            else if(i==n-1){
                cout<<abs(arr[n-1]-arr[n-2])<<' ';
                cout<<abs(arr[n-1]-arr[0])<<endl;
            }
            else{
                int ans1=min(abs(arr[i]-arr[i-1]),abs(arr[i+1]-arr[i]));
                int ans2=max(abs(arr[i]-arr[0]),abs(arr[n-1]-arr[i]));
                cout<<ans1<<' '<<ans2<<endl;
            }
        }
    }
    return 0;
}
