//Language: GNU C++


#include<iostream>
using namespace std;



int main()
{
bool flag=true;
int a[10],i,ans,x,y;
for(i=0;i<6;i++)
cin>>a[i];


ans= (a[0]+a[1]+a[2])*(a[0]+a[1]+a[2])-a[0]*a[0]-a[2]*a[2]-a[4]*a[4];

cout<<ans;
return 0;
}
