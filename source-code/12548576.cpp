//Language: GNU C++


#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define pb push_back
#define clr(a) memset(a,0,sizeof(a))
#define full(a) memset(a,63,sizeof(a))
#define pi 2*acos(0.0)
#define sf1(n) scanf("%d",&n)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf1d(n) scanf("%lf",&n)
#define sf2d(a,b) scanf("%lf%lf",&a,&b)
#define sf3d(a,b,c) scanf("%lf%lf%lf",&a,&b,&c)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
map <long long int,long long int> mp1;
map <long long int,long long int> mp2;
int main()
{
    long long int n,k;
    cin>>n>>k;

    long long int ans=0;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mp1[arr[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        mp2[arr[i]]++;
        if(i==0||i==n-1)
        continue;
        if(arr[i]%k==0)
        {
            long long int l=arr[i]/k;
            long long int lcount=mp2[l];
            if(l==arr[i])
            lcount--;
            long long int r=arr[i]*k;
            long long int rcount=mp1[r]-mp2[r];
            ans+=rcount*lcount;
        }
    }
    cout<<ans;
    return 0;
}

      	 	 	 			  	 		 	 	  	