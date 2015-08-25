//Language: GNU C++11


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
 int n,m,i,j,ind,v,max;
int hash[101]={0};
cin>>n>>m;

for(i=1;i<=m;i++)
{
max=0;ind=1;
 for(j=1;j<=n;j++){
 scanf("%d",&v);
 if(v>max)
 {max=v;ind=j;}
 }
++hash[ind];
}
max=0;ind=1;
for(i=1;i<=n;i++)
{
if(hash[i]>max)
{max=hash[i];ind=i;}
}
cout<<ind;
}
