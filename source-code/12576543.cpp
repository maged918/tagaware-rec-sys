//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
#include<utility>
#include<vector>
#define ll long long int
#define fi first 
#define se second
using namespace std;
int main()
{
ll n,m,x,y,i,j,z,fl;
ll a[101];
cin>>n>>m;

for(i=0;i<=100;i++) a[i] = 0;

for(i=0;i<m;i++)
{
z = -1;
for(j=1;j<=n;j++)
{
cin>>x;
if(x > z) {z = x; fl = j;}
}

a[fl]++;

}

z = -1;
for(i=1;i<=n;i++)
{
if(a[i] > z) {z = a[i]; fl = i;}
}

cout<<fl;
return 0;
}
