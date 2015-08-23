//Language: GNU C++


#include<iostream>
using namespace std;
int main(){
    int k;
    int n;
    int out = 1;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>k;
        if(k == 1) out = -1;
    } 
    cout<<out;
}