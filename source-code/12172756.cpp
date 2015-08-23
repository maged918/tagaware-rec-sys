//Language: GNU C++11


#include <iostream>
#include<algorithm>
using namespace std;

int arr[6];

int cal(int x){
    return x*x;
}

int main(){
    for(int i=0;i<6;i++)
        cin>>arr[i];
    int ans=cal(arr[0]+arr[1]+arr[2]);
    for(int i=0;i<3;i++)
        ans-=cal(arr[i*2]);
    cout<<ans;
    return 0;
}

