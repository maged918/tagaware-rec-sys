//Language: GNU C++


#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
 
using namespace std;

int main()
{
ios::sync_with_stdio(0);
 int n;
 cin>>n;
 int a[n+1];
 int cnt[n+1];
 for(int i=0;i<n+1;i++)
   cnt[i]=0;




 //bool visited[n+1]={false};
 a[0]=0;
 for(int i=1;i<n+1;i++)
   {
     cin>>a[i];
     //  visited[a[i]]=true;
     if(a[i]<n+1 && cnt[a[i]]==0)
       cnt[a[i]]=1;
     else 
       a[i]=0;

   }

 int l=1;
 int m=1;
 while(l<n+1 && m<n+1)
   {
     while(l<n+1)
       {
	 if(cnt[l]==0)
	   {
	     cnt[l]=1;
	   break;
	   }
	 else
	   l++;
       }
     while(m<n+1)
       {
	 if(a[m]==0)
	   break;
	 else
	   m++;
       }

     a[m]=l;

   }

 for(int i=1;i<n+1;i++)
   cout<<a[i]<<endl;

 return 0;
}
