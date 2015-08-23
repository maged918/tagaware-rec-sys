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
int main()
{
     int i,j,k,l,m,n,ans,sum,t,s,q;
     while(scanf("%d%d%d",&t,&s,&q)==3)
     {
         i=0;
         q--;
         sum=s;
         while(sum<t)
         {
             sum=sum+(sum*q);
             i++;
         }
         printf("%d\n",i);
     }
     return 0;
}
