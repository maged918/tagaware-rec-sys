//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,s,q,cnt=0;
    cin>> t>>s>>q;
    if(q*s>=t)
    cout<<"1"<<endl;
    else {
    while(t>s){
        s*=q;
        cnt++;
    } 
    cout<<cnt<<endl;}
        return 0;
    }