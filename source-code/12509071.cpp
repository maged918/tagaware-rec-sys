//Language: GNU C++


#include <iostream>
using namespace std;
long long arr[105][105];
int win[105];
int main() {
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }
    if(n%2==1){
        if(m==(n+1)/2){
            cout<<m-1;
            return 0;
        }
    }
    
    if(m<=n/2){
        cout<<m+1;
        return 0;
    }
    else {
        cout<<m-1;
        return 0;
    }
    
        
    return 0;
}