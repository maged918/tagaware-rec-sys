//Language: GNU C++11


#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n,x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    }
    cout<<arr[1]-arr[0]<<" "<<arr[n-1]-arr[0]<<"\n";
    for(int i=1;i<n-1;i++)
    {
    cout<<min((arr[i]-arr[i-1]),(arr[i+1]-arr[i]));
    cout<<" "<<max((arr[i]-arr[0]),(arr[n-1]-arr[i]))<<"\n";
    }
    cout<<arr[n-1]-arr[n-2]<<" "<<arr[n-1]-arr[0];
    
    return 0;
}