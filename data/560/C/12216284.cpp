//Language: GNU C++11


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
main()
{
    int a[6],f=1,s=0;
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
    s=a[0]+a[1]+a[2];
    s=s*s-a[0]*a[0]-a[2]*a[2]-a[4]*a[4];
    cout<<s;
}
