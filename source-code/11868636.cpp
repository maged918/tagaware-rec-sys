//Language: GNU C++11


#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mp make_pair
using namespace std;
typedef long long ll;


 
int main(){

ll mn1,mn2,mn3,mx1,mx2,mx3,n,s=0,a1,a2,a3;
cin>>n>>mn1>>mx1>>mn2>>mx2>>mn3>>mx3;
s=mn1+mn2+mn3;
a1=mn1;
a2=mn2;
a3=mn3;
while(s<n && a1<mx1){
    a1++;
    s++;
}
while(s<n && a2<mx2){
    a2++;
    s++;
}
while(s<n && a3<mx3){
    a3++;
    s++;
}
cout<<a1<<" "<<a2<<" "<<a3;
 

    return 0;
} 