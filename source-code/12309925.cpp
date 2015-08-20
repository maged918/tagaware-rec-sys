//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=100005;
const int inf=(int)1e9;
int n,a[maxn],b[maxn],c[maxn];
map<int,int>m1[maxn],m2[maxn],sum;
int main()
{
    cin>>n;
    int i;
    for( i=0;i<n;i++)
    {
            cin>>a[i];
            int t=a[i];
            int k=0,l=0;
            while(t>0)
            {
                      sum[t]++;
                      m1[i][t]=k;
                      m2[i][t]=l;
                      if(t%2==0)k++; else k=0;
                      l++;
                      t>>=1;
            }
    }
    for( i=100005;i>=1;i--)
    {
            if(sum[i]==n)break;
    }
    for(int p=0;p<n;p++)
    {
            b[p]=m2[p][i];c[p]=m1[p][i];
    }
    int ma=inf;
    for( i=0;i<18;i++)
    {
            int r=0;
            for(int j=0;j<n;j++)
            {
                    r+=i+b[j]-2*min(i,c[j]);
            }
            ma=min(r,ma);
    }
    cout<<ma<<endl;
    //system("pause");
    return 0;
}
                      
                      
