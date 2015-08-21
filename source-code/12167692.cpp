//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int Arr[1005];
int main(){
int n,i;
cin>>n;
for(i=0;i<n;i++)cin>>Arr[i];
sort(Arr,Arr+n);
if(Arr[0]==1)cout<<"-1\n";
else cout<<"1\n";
return 0;}
