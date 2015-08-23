//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[3][1000007];
int main()
{

    int n;int maxi=-1;
    int x,l=-999,r=999999;
    cin>>n;
    for(int i=0;i<n;i++){cin>>x;
    if(a[2][x]==0)
    {a[0][x]=i;
    }
    a[2][x]++;
    a[1][x]=i;
    }
    for(int i=0;i<1000005;i++)
    {
        if(a[2][i]>maxi || ((a[2][i]==maxi) && (r-l)>(a[1][i]-a[0][i])))
        {maxi=a[2][i];
        l=a[0][i];
        r=a[1][i];}
       // cout<<a[2][i]<<" "<<a[0][i]<<" "<<a[1][i]<<endl;


    }//cout<<endl;
    cout<<l+1<<" "<<r+1<<endl;
    return 0;
}

