//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > a(n+2);
    for(int i=0;i<n;i++)
     {
        cin>>a[i].first>>a[i].second;
     }
    a[n]=make_pair(INT_MIN,0);
    a[n+1]=make_pair(INT_MAX,0);
    
    sort(a.begin(),a.end());
    int i=0;
    for(i=0;i<n+2;i++)
     {
        if(a[i].first<0 && a[i+1].first>0)
          break;
     }
    int pos=i;
    int c1=0,c2=0;
    for(int i=pos,j=pos+1;i>0 && j<n+2;i--,j++)
    {
        c1+=a[i].second;
        if(j<n+1)
         {
            c1+=a[j].second;
         }
    }
    for(int i=pos,j=pos+1;i>=0 && j<n+1;i--,j++)
    {
        c2+=a[j].second;
        if(i>0)
         {
            c2+=a[i].second;
         }
    }
    cout<<max(c1,c2);
  
    
}