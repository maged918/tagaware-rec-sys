//Language: GNU C++


/* ***********************************************
Author        :zyc
Created Time  :2015/7/22 22:12:59
File Name     :c.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>
using namespace std;
#define ll long long
int arr[6];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    for(int i=0;i<6;i++)
        scanf("%d",&arr[i]);
    ll sum=arr[0]*arr[1]*2+arr[2]*arr[3]*2+arr[4]*arr[5]*2;
    int x1=abs(arr[0]-arr[3]),x2=abs(arr[1]-arr[4]),x3=abs(arr[2]-arr[5]);
    sum+=x1*x1;
    cout<<sum<<endl;
    return 0;
}
